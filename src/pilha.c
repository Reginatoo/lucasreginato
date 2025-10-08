#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

typedef struct{
    form forma;
    struct no* proximo;
}no;
typedef struct{
    no* topo;
    int tamanho;
}pilhastruct;

PILHA cria_pilha(){
    pilhastruct* p=(pilhastruct*)malloc(sizeof(pilhastruct));
    if (p==NULL){
        printf ("erro de alocação na pilha \n");
    }
    p->topo=NULL;
    p->tamanho=0;
    return p;
}
void inserir_na_pilha(PILHA p, form f){
    pilhastruct* p1= (pilhastruct*)p;
    no* novo_no = (no*) malloc(sizeof(no));
    if (novo_no == NULL) {
        printf("Erro de alocação no nó da pilha\n");
        exit(1);
    }
    novo_no->forma=f;
    novo_no->proximo = p1->topo;
    p1->topo = novo_no;
    
    p1->tamanho++;
}
form remover_da_pilha(PILHA p){
    pilhastruct* p1= (pilhastruct*)p;
    if(p1->topo==NULL){
        printf("não ha nada para remover\n");
        return NULL;
    }

    no* no_removido=p1->topo;
    form forma_a_retornar=no_removido->forma;
    p1->topo=p1->topo->proximo;

    free(no_removido);
    p1->tamanho--;
    return(forma_a_retornar);
}
void kill_pilha(PILHA p){
    pilhastruct* p1=(pilhastruct*)p;
    while(p1->tamanho!=0){     
        no* no_removido=p1->topo;
       p1->topo=p1->topo->proximo;

         free(no_removido);
        p1->tamanho--;

    }
    free(p1);
}