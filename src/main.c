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

    char caminho_geo[600];
    if(dir_entrada!=NULL){
        sprintf(caminho_geo, "%s/%s", dir_entrada, arq_geo );
    }
else{
    strcpy(caminho_geo, arq_geo);
}

FILE* arquivo_geo = fopen(caminho_geo, "r");
    if (arquivo_geo == NULL) {
        printf(" não foi possível abrir o arquivo .geo!\n");
        return 1;
    }

    char linha[600];
    char comando[10];

    while (fgets(linha, sizeof(linha), arquivo_geo)) {
     sscanf(linha, "%s", comando);
     if(strcmp (comando, "c")==0){
    int id;
    float r, x, y;
    char *corb, *corp;
    sscanf(linha, "c %d %f %f %f %s %s", &id, &r, &x, &y, corb, corp);
    FORMA novo_circulo=cria_circulo(id, x, y, r, corb, corp);
    inserir_na_fila(chao, novo_circulo);
     }
     
}
}