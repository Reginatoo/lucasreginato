#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "colisao.h"
#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"

typedef struct {
    float x1, y1, x2, y2;
} Segmento;

char get_tipo(void* forma) {
    if (forma == NULL) return '\0';
    return *((char*)forma);
}

Segmento texto_para_segmento(void* t) {
    Segmento s;
    float x = get_xT(t);
    float y = get_yT(t);
    float compr = get_areaT(t) / 2.0;
    char ancora = get_aT(t);

    s.y1 = s.y2 = y;
    if (ancora == 'i') {
        s.x1 = x;
        s.x2 = x + compr;
    } else if (ancora == 'm') {
        s.x1 = x - compr / 2.0;
        s.x2 = x + compr / 2.0;
    } else {
        s.x1 = x - compr;
        s.x2 = x;
    }
    return s;
}

 Segmento linha_para_segmento(void* l) {
    Segmento s;
    s.x1 = get_X1L(l);
    s.y1 = get_Y1L(l);
    s.x2 = get_X2L(l);
    s.y2 = get_Y2L(l);
    return s;
}

 int circulo_vs_circulo(void* c1, void* c2) {
    float dx = get_XC(c1) - get_XC(c2);
    float dy = get_YC(c1) - get_YC(c2);
    float soma_raios = get_RC(c1) + get_RC(c2);
    return (dx * dx + dy * dy) <= (soma_raios * soma_raios);
}

 int retangulo_vs_retangulo(void* r1, void* r2) {
    return (get_XR(r1) < get_XR(r2) + get_WR(r2) &&
            get_XR(r1) + get_WR(r1) > get_XR(r2) &&
            get_YR(r1) < get_YR(r2) + get_HR(r2) &&
            get_YR(r1) + get_HR(r1) > get_YR(r2));
}

 int circulo_vs_retangulo(void* c, void* r) {
    float ponto_teste_x = get_XC(c);
    float ponto_teste_y = get_YC(c);

    if (get_XC(c) < get_XR(r)) ponto_teste_x = get_XR(r);
    else if (get_XC(c) > get_XR(r) + get_WR(r)) ponto_teste_x = get_XR(r) + get_WR(r);
    if (get_YC(c) < get_YR(r)) ponto_teste_y = get_YR(r);
    else if (get_YC(c) > get_YR(r) + get_HR(r)) ponto_teste_y = get_YR(r) + get_HR(r);

    float dx = get_XC(c) - ponto_teste_x;
    float dy = get_YC(c) - ponto_teste_y;
    float raio = get_RC(c);
    return (dx * dx + dy * dy) <= (raio * raio);
}

 int segmento_vs_forma(Segmento s, void* forma) {
    char tipo_forma = get_tipo(forma);

    if (tipo_forma == 'c') { 
        float raio = get_RC(forma);
        float dx1 = s.x1 - get_XC(forma);
        float dy1 = s.y1 - get_YC(forma);
        if ((dx1*dx1 + dy1*dy1) <= (raio*raio)) return 1;

        float dx2 = s.x2 - get_XC(forma);
        float dy2 = s.y2 - get_YC(forma);
        if ((dx2*dx2 + dy2*dy2) <= (raio*raio)) return 1;
        return 0;
    }
    if (tipo_forma == 'r') { 
        int ponta1_dentro = (s.x1 >= get_XR(forma) && s.x1 <= get_XR(forma) + get_WR(forma) &&
                             s.y1 >= get_YR(forma) && s.y1 <= get_YR(forma) + get_HR(forma));
        if (ponta1_dentro) return 1;
        
        int ponta2_dentro = (s.x2 >= get_XR(forma) && s.x2 <= get_XR(forma) + get_WR(forma) &&
                             s.y2 >= get_YR(forma) && s.y2 <= get_YR(forma) + get_HR(forma));
        return ponta2_dentro;
    }
    return 0;
}

int verifica_sobreposicao(form forma_i, form forma_j) {
    if (forma_i == NULL || forma_j == NULL) return 0;

    char tipo_i = get_tipo(forma_i);
    char tipo_j = get_tipo(forma_j);

    if (tipo_i == 'c' && tipo_j == 'c') return circulo_vs_circulo(forma_i, forma_j);
    if (tipo_i == 'r' && tipo_j == 'r') return retangulo_vs_retangulo(forma_i, forma_j);
    if (tipo_i == 'c' && tipo_j == 'r') return circulo_vs_retangulo(forma_i, forma_j);
    if (tipo_i == 'r' && tipo_j == 'c') return circulo_vs_retangulo(forma_j, forma_i);

    if (tipo_i == 'l' || tipo_i == 't') {
        Segmento s_i = (tipo_i == 'l') ? linha_para_segmento(forma_i) : texto_para_segmento(forma_i);
        return segmento_vs_forma(s_i, forma_j);
    }
    if (tipo_j == 'l' || tipo_j == 't') {
        Segmento s_j = (tipo_j == 'l') ? linha_para_segmento(forma_j) : texto_para_segmento(forma_j);
        return segmento_vs_forma(s_j, forma_i);
    }

    return 0;
}