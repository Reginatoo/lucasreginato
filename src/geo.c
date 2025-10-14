#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "geo.h" 
#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "disparador.h"
void processar_geo(char* caminho_geo, FILA chao, FILA arena, float* chao_x, float* chao_y, float* chao_w, float* chao_h, char chao_cor[], float* arena_x, float* arena_y, float* arena_w, float* arena_h, char arena_cor[]){
 
  FILE* arquivo_geo = fopen(caminho_geo, "r");
    if (arquivo_geo == NULL) {
        printf(" não foi possível abrir o arquivo .geo!\n");
        exit(1);
    }

    char linha[600];
    char comando[10];

    while (fgets(linha, sizeof(linha), arquivo_geo)) {
     sscanf(linha, "%s", comando);
     if(strcmp (comando, "c")==0){
    int id;
    float r, x, y;
    char corb[20], corp[20];
    sscanf(linha, "c %d %f %f %f %s %s", &id, &r, &x, &y, corb, corp);
    FORMA novo_circulo=cria_circulo(id, x, y, r, corb, corp);
    inserir_na_fila(chao, novo_circulo);
     }
     if(strcmp(comando, "r")==0){
        int id;
       float x, y, w, h;
        char corb[20], corp[20];
        sscanf(linha, "r %d %f %f %f %f %s %s", &id, &w, &h, &x, &y, corb, corp);
        FORMA novo_retangulo=cria_retangulo(id, x, y, w, h, corb, corp);
        inserir_na_fila(chao, novo_retangulo);
     }
    if(strcmp(comando, "l")==0){
        int id;
        float x1, y1, x2, y2;
        char cor[30];
        sscanf(linha, "l %d %f %f %f %f %s", &id, &x1, &y1, &x2, &y2, cor);
        FORMA nova_linha=cria_linha(id, x1, y1, x2, y2, cor);
        inserir_na_fila(chao, nova_linha);
     }
     if(strcmp(comando, "t")==0){
        int id;
        float x, y;
        char corb[20], corp[20], txt[30];
        char a;
        sscanf(linha, "t %d %f %f %s %s %c %s", &id, &x, &y, corb, corp, &a, txt);
        FORMA novo_texto=cria_texto(id, x, y, corb, corp, a, txt);
        inserir_na_fila(chao, novo_texto);
     }
     if (strcmp(comando, "chao") == 0) {
            sscanf(linha, "chao %f %f %f %f %s", chao_x, chao_y, chao_w, chao_h, chao_cor);
}
    if (strcmp(comando, "arena") == 0) {
            sscanf(linha, "arena %f %f %f %f %s", arena_x, arena_y, arena_w, arena_h, arena_cor);
    }
}
printf("--- Fim da leitura do .geo ---\n");
    fclose(arquivo_geo);

}