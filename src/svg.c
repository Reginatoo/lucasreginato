#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "svg.h"
#include "circulo.h"  
#include "retangulo.h" 
#include "linha.h"     
#include "texto.h"     
#include "qry.h"      
#include "fila.h"      


void desenhar_circulo(FILE* svg, void* forma) {
    fprintf(svg, "\t<circle cx=\"%f\" cy=\"%f\" r=\"%f\" stroke=\"%s\" fill=\"%s\" stroke-width=\"1\" opacity=\"0.6\" />\n",
            get_XC(forma), get_YC(forma), get_RC(forma), 
            get_cbC(forma), get_cpC(forma));
}

void desenhar_retangulo(FILE* svg, void* forma) {
    fprintf(svg, "\t<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" stroke=\"%s\" fill=\"%s\" stroke-width=\"1\" opacity=\"0.6\" />\n",
            get_XR(forma), get_YR(forma), get_WR(forma), get_HR(forma),
            get_cbR(forma), get_cpR(forma));
}

void desenhar_linha(FILE* svg, void* forma) {
    fprintf(svg, "\t<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" stroke=\"%s\" stroke-width=\"1\" />\n", 
            get_X1L(forma), get_Y1L(forma), get_X2L(forma), get_Y2L(forma),
            get_CorL(forma));
}

void desenhar_texto(FILE* svg, void* forma) {
    char a = get_aT(forma);
    const char* anchor = "start"; 

    if (a == 'm') {
        anchor = "middle";
    } else if (a == 'f') {
        anchor = "end";
    }
    
    char* cor_preenchimento = get_cpT(forma);
    char* cor_borda = get_cbT(forma);
    char* cor_stroke = cor_borda;

    if (strcmp(cor_borda, "none") == 0) {
        cor_stroke = cor_preenchimento; 
    }
    
    fprintf(svg, "\t<text x=\"%f\" y=\"%f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"1\" font-family=\"%s\" font-weight=\"%s\" font-size=\"%s\" text-anchor=\"%s\">%s</text>\n",
            get_xT(forma), get_yT(forma), 
            cor_preenchimento, cor_stroke,
            get_familiaT(forma), get_pesoT(forma), get_tamT(forma),
            anchor,
            get_txtT(forma));
}

void desenhar_forma_generica(FILE* svg, void* forma) {
    if (forma == NULL) return;
    
    char tipo = get_tipo_da_forma(forma); 

    if (tipo != 'c' && tipo != 'r' && tipo != 'l' && tipo != 't') {
        fprintf(stderr, "AVISO: Forma com tipo desconhecido ('%c') ou ponteiro corrompido. Forma ignorada.\n", tipo);
        return;
    }
    switch (tipo) {
        case 'c': desenhar_circulo(svg, forma); break;
        case 'r': desenhar_retangulo(svg, forma); break;
        case 'l': desenhar_linha(svg, forma); break;
        case 't': desenhar_texto(svg, forma); break;
    }
}

void desenhar_svg(char* caminho_svg, FILA chao, FILA arena, 
                  float cx, float cy, float cw, float ch, char* ccor) {
                      
    FILE* arq_svg = fopen(caminho_svg, "w");
    if (arq_svg == NULL) {
        printf("Erro ao criar o arquivo SVG %s!\n", caminho_svg);
        exit(1);
    }

    fprintf(arq_svg, "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n");
    fprintf(arq_svg, "<svg width=\"100%%\" height=\"100%%\" viewBox=\"%.0f %.0f %.0f %.0f\" xmlns=\"http://www.w3.org/2000/svg\">\n", 
            cx, cy, cw, ch); 
    fprintf(arq_svg, "\n\t\n");

    void* no_atual = get_primeiro_no(chao);
    while (no_atual != NULL) {
        void* forma = get_info_do_no(no_atual);
        desenhar_forma_generica(arq_svg, forma);
        no_atual = get_proximo_no(no_atual);
    }
    
    no_atual = get_primeiro_no(arena);
    while (no_atual != NULL) {
        void* forma = get_info_do_no(no_atual);
        desenhar_forma_generica(arq_svg, forma);
        no_atual = get_proximo_no(no_atual);
    }

    fprintf(arq_svg, "</svg>\n");
    fclose(arq_svg);
}