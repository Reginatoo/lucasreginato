#include <stdlib.h>
#include <stdio.h>
#include "disparador.h"
#include "pilha.h"
#include <string.h>

typedef struct
{
    int id;
    float x, y;
    FORMA forma;
    CARREGADOR carregador_esquerdo;
    CARREGADOR carregador_direito;
}disp;

DISPARADOR cria_disparador() {
    disp* d = malloc(sizeof(disp));
    if (d == NULL) {
        printf("erro na alocação do disparador\n");
        exit(1);
    }
    d->x = 0;
    d->y = 0; 
    d->forma = NULL;
    d->carregador_esquerdo = NULL;
    d->carregador_direito = NULL;
    return d;
}

void disparador_set_posicao(DISPARADOR d, float x, float y) {
    disp* d1 = (disp*)d;
    if (d1 == NULL) return;
    d1->x = x;
    d1->y = y;
}
void disparador_anexar_carregadores(DISPARADOR d, CARREGADOR esquerdo, CARREGADOR direito){
    disp* d1=(disp*)d;
    if (d1 == NULL) return;
    d1->carregador_direito=direito;
    d1->carregador_esquerdo=esquerdo;
}

void disparador_selecionar_carga(DISPARADOR d, char lado){
    disp* d1=(disp*)d;
    if (d1 == NULL) return;
    if(lado=='e'){
        if(d1->carregador_direito==NULL) return;
        FORMA nova_forma=remover_da_pilha(d1->carregador_direito);
        if (nova_forma==NULL) return;
        if(d1->forma!=NULL){
            inserir_na_pilha(d1->carregador_direito, d1->forma);
        }
        d1->forma=nova_forma;
    }
    if(lado=='d'){
        if(d1->carregador_esquerdo==NULL) return;
        FORMA nova_forma=remover_da_pilha(d1->carregador_esquerdo);
        if (nova_forma==NULL) return;
        if(d1->forma!=NULL){
            inserir_na_pilha(d1->carregador_esquerdo, d1->forma);
        }
        d1->forma=nova_forma;
    }
    if(lado!='e'&&lado!='d'){
        printf("Lado inválido para selecionar carga. Use 'e' ou 'd'.\n");
    }
}
FORMA disparador_disparar(DISPARADOR d){
   disp* d1 = (disp*)d;
   if (d1 == NULL) return NULL;
   FORMA forma_disparada = d1->forma;
   d1->forma = NULL;
   return forma_disparada;
}
float disparador_get_x(DISPARADOR d) {
    if (d == NULL) return -1;
    return ((disp*) d)->x;
}

float disparador_get_y(DISPARADOR d) {
    if (d == NULL) return -1;
    return ((disp*) d)->y;
}
FORMA disparador_get_forma_em_posicao(DISPARADOR d) {
    if (d == NULL) return NULL;
    return ((disp*)d)->forma;
}
PILHA disparador_get_carregador_esquerdo(DISPARADOR d) {
    if (d == NULL) return NULL;
    return ((disp*)d)->carregador_esquerdo;
}

PILHA disparador_get_carregador_direito(DISPARADOR d) {
    if (d == NULL) return NULL;
    return ((disp*)d)->carregador_direito;
}

void kill_disparador(DISPARADOR d) {
    if (d == NULL) return;
    free(d);
}
