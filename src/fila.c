#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

typedef struct{
    form forma;
    struct no* proximo;
}no;
typedef struct{
    no* inicio;
    no* fim;
    int tamanho;
}filastruct;

FILA cria_fila(){
    filastruct* q=(filastruct*)malloc(sizeof(filastruct));
    if (q==NULL){
        printf ("erro de alocação na fila \n");
    }
    q->inicio=NULL;
    q->fim=NULL;
    q->tamanho=0;
    return q;
}
void inserir_na_fila(FILA q, form f){
    filastruct* f1= (filastruct*)q;
    no* novo_no = (no*) malloc(sizeof(no));
    if (novo_no == NULL) {
        printf("Erro de alocação no nó da fila\n");
        exit(1);
    }
    novo_no->forma=f;
    novo_no->proximo=NULL;
    if(f1->inicio==NULL){
        f1->inicio=novo_no;
        f1->fim=novo_no;
    }else{
        f1->fim->proximo=novo_no;
        f1->fim=novo_no;
    }
    f1->tamanho++;

}
form remover_da_fila(FILA q){
    filastruct* f1= (filastruct*)q;
    if(f1->inicio==NULL){
        printf("não ha nada para remover\n");
        return NULL;
    }

    no* no_removido=f1->inicio;
    form forma_a_retornar=no_removido->forma;
    if(f1->inicio==f1->fim){
    f1->inicio=NULL;
    f1->fim=NULL;
    }else{
   f1->inicio=f1->inicio->proximo;
    }

    free(no_removido);
    f1->tamanho--;
    return(forma_a_retornar);
}
void kill_fila(FILA q){
    filastruct* f1=(filastruct*)q;
    while(f1->tamanho!=0){     
        no* no_removido=f1->inicio;
        f1->inicio=f1->inicio->proximo;
         free(no_removido);
        f1->tamanho--;

    }
    free(f1);
}