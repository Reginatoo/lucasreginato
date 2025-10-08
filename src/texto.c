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
        exit(1);}
        t->corb = strdup("black");
        t->eb = 1.0;
        t->tam = 10.0;
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
float get_ebT(TEXTO t){
    return ((text*)t)->eb;
}
float get_tamT(TEXTO t){
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
void set_estiloT(TEXTO t, char* cb, char* cp, float eb, float tam){
 text* t1= (text*)t;

    if (strcmp(cb, "-") != 0) {
        free(t1->corb);
        t1->corb = strdup(cb);
    }
    if (strcmp(cp, "-") != 0) {
        free(t1->corp);
        t1->corp = strdup(cp);
    }

    if (eb >= 0) {
        t1->eb = eb;
    } 

    if (tam >= 0) {
        t1->tam = tam;
    }
}
void kill_texto(TEXTO t_void) {
    text* t = (text*) t_void;
    if (t == NULL) {
        return;
    }
    free(t->corb);
    free(t->corp);
    free(t->ctd);
    free(t);
}


