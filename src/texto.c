#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "texto.h"
#include <math.h>
typedef struct{
    int id;
    float x, y, tam, eb;
    char *corb, *corp, *ctd;
    char a;
}text;

TEXTO cria_texto(int id, float x, float y, char* ctd, char a, char* cp){
text *t = malloc(sizeof(text));
    if (t == NULL) {
        printf("Erro na alocação de memória na criação do texto");
        exit(1);
    }

    t->id = id;
    t->x = x;
    t->y = y;
    t->a = a;
    t->ctd = strdup(ctd);
     if(t->ctd == NULL) {
        printf("Erro na alocação de memória para o conteudo do texto");
        exit(1);}
    t->corp = strdup(cp);
        if(t->corp == NULL) {
        printf("Erro na alocação de memória para a cor de preenchimento");
        exit(1);
        t->corb = strdup("black");
        t->eb = 1.0;
        t->tam = 10.0;
    return t;
    }