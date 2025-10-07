#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linha.h"
#include <math.h>
typedef struct{
    int id;
    float x1, y1, x2, y2;
    char *cor;
}lin;

LINHA cria_linha(int id, float x2, float y2, float x1, float y1, char* cor){
lin *l = malloc(sizeof(lin));
    if (l == NULL) {
        printf("Erro na alocação de memória na criação do linha");
        exit(1);
    }

    l->id = id;
    l->x1 = x1;
    l->y1 = y1;
    l->x2 = x2;
    l->y2 = y2;
    l->cor = strdup(cor);
     if(l->cor == NULL) {
        printf("Erro na alocação de memória para a cor");
        exit(1);}
    
        return l;
}
 int get_idL(LINHA l){
     return ((lin*)l)->id;
}
float get_X1L(LINHA l){
    return ((lin*)l)->x1;
}

float get_Y1L(LINHA l){
     return ((lin*)l)->y1;
}

float get_x2L(LINHA l){
    return ((lin*)l)->x2;
}
float get_y2L(LINHA l){
    return ((lin*)l)->y2;
}

char* get_cL(LINHA l){
     return ((lin*)l)->cor;
}
float get_areaL(LINHA l){
   lin* l1 = (lin*)l;
   float dx= l1->x1 - l1->x2;
   float dy= l1->y1 - l1->y2;
   float comprimento= sqrt((dx*dx)+(dy*dy));
   return comprimento;
}
void set_x1L(LINHA l, float x1){
    ((lin*)l)->x1 = x1;
}
void set_x2L(LINHA l, float x2){
    ((lin*)l)->x2 = x2;
}

void set_y1L(LINHA l, float y1){
    ((lin*)l)->y1 = y1;
}

void set_cL(LINHA l, char* c){
    lin* c1 = (lin*)l;
    free(c1->cor);
    c1->cor = strdup(c);
     if(c1->cor == NULL) {
        printf("Erro na alocação de memória para a cor");
        exit(1);}
    
}

void set_idL(LINHA l, int id){
   ((lin*)l)->id = id;
}

void kill_lin(LINHA c){
    lin* c1 = (lin*)c;
    if (c1 == NULL) {
        return;
    }
    free(c1->cor);
    free(c1);
}