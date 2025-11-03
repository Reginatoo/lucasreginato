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
#include "svg.h"
#include "qry.h"

void extrair_nome_base(const char* path, char* nome_base) {
    const char* barra = strrchr(path, '/');
    if (barra) path = barra + 1;

    strcpy(nome_base, path);
    char* ponto = strrchr(nome_base, '.');
    if (ponto) *ponto = '\0';
}
const char* extrair_nome_ficheiro(const char* path) {
    const char* barra = strrchr(path, '/');
    if (barra) {
        return barra + 1;
    }
    return path;
}

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
    DISPARADOR disparadores[100];
    for(int i = 0; i<100; i++) {
        disparadores[i] = cria_disparador();
    }
    PILHA carregadores[100];
    for(int i = 0; i<100; i++) {
        carregadores[i] = criar_pilha();
    }

    float chao_x = 0, chao_y = 0, chao_w = 1000, chao_h = 1000;
    char chao_cor[30] = "red";
    float arena_x, arena_y, arena_w, arena_h;
    char arena_cor[30]; 

    char caminho_geo[600];
    if(dir_entrada!=NULL){
        sprintf(caminho_geo, "%s/%s", dir_entrada, arq_geo);
    } else {
        strcpy(caminho_geo, arq_geo);
    }

    processar_geo(caminho_geo, chao, arena, &chao_x, &chao_y, &chao_w, &chao_h, chao_cor, &arena_x, &arena_y, &arena_w, &arena_h, arena_cor); 

    char nome_base_geo[100];
    extrair_nome_base(arq_geo, nome_base_geo);
    char caminho_svg_base[600];
    sprintf(caminho_svg_base, "%s/%s.svg", dir_saida, nome_base_geo);
    printf("Desenhando SVG inicial em: %s\n", caminho_svg_base);

    desenhar_svg(caminho_svg_base, chao, arena, chao_x, chao_y, chao_w, chao_h, chao_cor); 

    if (arq_qry != NULL) {
        printf("Processando ficheiro QRY: %s\n", arq_qry);

        char caminho_qry[600];
        char nome_base_qry[100];
        extrair_nome_base(arq_qry, nome_base_qry);
        if (dir_entrada != NULL) {
            sprintf(caminho_qry, "%s/%s", dir_entrada, arq_qry);
        } else {
            strcpy(caminho_qry, arq_qry);
        }
        char caminho_txt[600];
        sprintf(caminho_txt, "%s/%s-%s.txt", dir_saida, nome_base_geo, nome_base_qry);
        char caminho_svg_final[600];
        sprintf(caminho_svg_final, "%s/%s-%s.svg", dir_saida, nome_base_geo, nome_base_qry);

        processar_qry(caminho_qry, caminho_svg_base, caminho_svg_final, caminho_txt,
                      chao, arena, carregadores, disparadores, 
                      chao_x, chao_y, chao_w, chao_h, chao_cor);

    } else {
        printf("Nenhum ficheiro .qry foi fornecido \n");
    }

    printf("Limpando memória...\n");
    kill_fila(chao, destruir_forma_generica);
    kill_fila(arena, destruir_forma_generica); 

    for (int i = 0; i < 100; i++) {
        kill_pilha(carregadores[i], destruir_forma_generica);
        kill_disparador(disparadores[i]);
    }

    printf("Concluído.\n");
    return 0;
}