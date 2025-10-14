#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "pilha.h"
#include "disparador.h"
#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "geo.h"

int main(int argc, char* argv[]){
    char* dir_entrada=NULL;
    char* arq_geo=NULL;
    char* dir_saida=NULL;
    char* arq_qry=NULL;
    for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-e") == 0) {
                i++; 
                dir_entrada = argv[i];
            } else if (strcmp(argv[i], "-f") == 0) {
                i++; 
                arq_geo = argv[i];
            } else if (strcmp(argv[i], "-o") == 0) {
                i++;
                dir_saida = argv[i];
            } else if (strcmp(argv[i], "-q") == 0) {
                i++;
                arq_qry = argv[i];
            }
        }
   if (arq_geo == NULL || dir_saida == NULL) {
        printf("Erro: Faltam parâmetros obrigatórios! Use -f e -o.\n");
        return 1;
    }

    FILA chao=criar_fila();
    FILA arena=criar_fila();

     PILHA carregadores[100];
     for(int i = 0; i<100; i++) {
         carregadores[i] = criar_pilha();
    }
    float chao_x = 0, chao_y = 0, chao_w = 1000, chao_h = 1000;
    char chao_cor[30] = "lightgrey";
    float arena_x = 50, arena_y = 50, arena_w = 900, arena_h = 900;
    char arena_cor[30] = "white";

    char caminho_geo[600];
    if(dir_entrada!=NULL){
        sprintf(caminho_geo, "%s/%s", dir_entrada, arq_geo );
    }
else{
    strcpy(caminho_geo, arq_geo);
}

processar_geo(caminho_geo, chao, arena, &chao_x, &chao_y, &chao_w, &chao_h, chao_cor, &arena_x, &arena_y, &arena_w, &arena_h, arena_cor);