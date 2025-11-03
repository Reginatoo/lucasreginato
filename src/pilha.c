#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

struct no_pilha { 
    form forma;
    struct no_pilha* proximo; 
};
typedef struct no_pilha no;

typedef struct{
    no* topo;
    int tamanho;
}pilhastruct;

PILHA criar_pilha(){
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
int pilha_esta_vazia(PILHA p) {
    pilhastruct* p1 = (pilhastruct*)p;
    
    if (p1 == NULL || p1->topo == NULL) {
        return 1; 
    } else {
        return 0; 
    }
}
void kill_pilha(PILHA q, void (*destruir_forma)(form f)) {
    pilhastruct* p1 = (pilhastruct*)q; 
    if (p1 == NULL) return;
    no* atual = p1->topo; 
    no* proximo;
    while (atual != NULL) {
        proximo = atual->proximo; 
        if (destruir_forma != NULL) {
            destruir_forma(atual->forma); 
        }   
        free(atual);
        atual = proximo; 
    }
    free(p1);
}