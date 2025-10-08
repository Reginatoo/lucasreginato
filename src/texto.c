#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "texto.h"
#include <math.h>
typedef struct{
    int id;
    float x, y;
    char *corb, *corp, *ctd, *familia, *peso, *tam, *eb;
    char a;
}text;

TEXTO cria_texto(int id, float x, float y, char* ctd, char a, char* cp, char* familia, char* peso, char* tam){
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
     t->familia = strdup(familia);
      if(t->familia == NULL) {
        printf("Erro na alocação de memória para a familia do texto");
        exit(1);}
    t->peso = strdup(peso);
     if(t->peso == NULL) {
        printf("Erro na alocação de memória para o peso do texto");
        exit(1);}
    t->tam = strdup(tam);
     if(t->tam == NULL) {
        printf("Erro na alocação de memória para o tamanho do texto");
        exit(1);}
    t->corp = strdup(cp);
        if(t->corp == NULL) {
        printf("Erro na alocação de memória para a cor de preenchimento");
        exit(1);}

        t->corb = strdup("black");
        t->eb = strdup("1.0");
    return t;
    }
    int get_idT(TEXTO t){
     return ((text*)t)->id;
}
float get_XT(TEXTO t){
    return ((text*)t)->x;
}

float get_YT(TEXTO t){
     return ((text*)t)->y;
}

char get_aT(TEXTO t){
    return ((text*)t)->a;
}
char* get_ctdT(TEXTO t){
    return ((text*)t)->ctd;
}

char* get_cbT(TEXTO t){
     return ((text*)t)->corb;
}

char* get_cpT(TEXTO t){
     return ((text*)t)->corp;
}

float get_areaT(TEXTO t){
    return strlen(((text*)t)->ctd) * 10.0;
}
char* get_ebT(TEXTO t){
    return ((text*)t)->eb;
}
char* get_familiaT(TEXTO t) {
     return ((text*)t)->familia;
     }
char* get_pesoT(TEXTO t) { 
    return ((text*)t)->peso;
 }
char* get_tamanhoT(TEXTO t) { 
    return ((text*)t)->tam;
}

void set_xT(TEXTO t, float x){
    ((text*)t)->x = x;
}

void set_yT(TEXTO t, float y){
    ((text*)t)->y = y;
}

void set_cbT(TEXTO t, char* cb){
    text* t1 = (text*)t;
    free(t1->corb);
    t1->corb = strdup(cb);
     if(t1->corb == NULL) {
        printf("Erro na alocação de memória para a cor de borda");
        exit(1);}
    
}

void set_idT(TEXTO t, int id){
   ((text*)t)->id = id;
}

void set_cpT(TEXTO t, char* corp){
    text* t1 = (text*)t;
    free(t1->corp);
    t1->corp = strdup(corp);
     if(t1->corp == NULL) {
        printf("Erro na alocação de memória para a cor de preenchimento");
        exit(1);}
     }
void set_estiloT(TEXTO t, char* cb, char* cp, char* eb, char* tam){
 text* t1= (text*)t;

    if (strcmp(cb, "-") != 0) {
        free(t1->corb);
        t1->corb = strdup(cb);
    }
    if (strcmp(cp, "-") != 0) {
        free(t1->corp);
        t1->corp = strdup(cp);
    }

   if (strcmp(eb, "-") != 0) {
        free(t1->eb);
        t1->eb = strdup(eb);
    }

   if (strcmp(tam, "-") != 0) {
        free(t1->tam);
        t1->tam = strdup(tam);
    }}

void kill_texto(TEXTO t) {
    text* t1 = (text*)t;
    if (t == NULL) {
        return;
    }
    free(t1->corb);
    free(t1->corp);
    free(t1->ctd);
    free(t1->eb);
    free(t1->familia);
    free(t1->peso);
    free(t1->tam);
    free(t);
}


