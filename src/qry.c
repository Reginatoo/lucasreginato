#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qry.h"
#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "disparador.h"

char get_tipo_da_forma(void* forma) {
    if (forma == NULL) return '\0';
    return *((char*)forma);
}
void* encontrar_forma_por_id(FILA f, int id) {
    void* no_atual = get_primeiro_no(f);
    while (no_atual != NULL) {
        void* forma_atual = get_info_do_no(no_atual);
        int id_da_forma = -1;
        char tipo = get_tipo_da_forma(forma_atual);
        switch (tipo) {
            case 'c': id_da_forma = get_idC(forma_atual); break;
            case 'r': id_da_forma = get_idR(forma_atual); break;
            case 'l': id_da_forma = get_idL(forma_atual); break;
            case 't': id_da_forma = get_idT(forma_atual); break;
        }

        if (id_da_forma == id) {
            return forma_atual; 
        }
        
        no_atual = get_proximo_no(no_atual);
    }
    return NULL; 
}
void imprimir_dados_forma(FILE* arq_txt, void* forma) {
    if (forma == NULL) {
        fprintf(arq_txt, "  > Forma NULA\n");
        return;
    }
    
    char tipo = get_tipo_da_forma(forma);

    switch (tipo) {
        case 'c':
            fprintf(arq_txt, " Circulo ID:%d, X:%f, Y:%f, R:%f, Borda:%s, Preench:%s\n",
                get_idC(forma),
                get_XC(forma),
                get_YC(forma),
                get_RC(forma),
                get_cbC(forma),
                get_cpC(forma));
            break;
        case 'r':
            fprintf(arq_txt, " Retangulo ID:%d, X:%f, Y:%f, W:%f, H:%f, Borda:%s, Preench:%s\n",
                get_idR(forma),
                get_XR(forma),
                get_YR(forma),
                get_WR(forma),
                get_HR(forma),
                get_cbR(forma),
                get_cpR(forma));
            break;
           case 'l':
            fprintf(arq_txt, " Linha ID:%d, X1:%f, Y1:%f, X2:%f, Y2:%f, Cor:%s\n",
                get_idL(forma),
                get_X1L(forma),
                get_Y1L(forma),
                get_X2L(forma),
                get_Y2L(forma),
                get_CorL(forma));
            break;

        case 't':
            fprintf(arq_txt, " Texto ID:%d, X:%f, Y:%f, Borda:%s, Preench:%s, Ancora:'%c', Conteudo:\"%s\"\n",
                get_idT(forma),
                get_xT(forma),
                get_yT(forma),
                get_cbT(forma),
                get_cpT(forma),
                get_aT(forma),
                get_txtT(forma));
            break;
       
    }
}
void processar_qry(char* caminho_qry, char* caminho_svg, char* caminho_txt, FILA chao, FILA arena, PILHA carregadores[], DISPARADOR disparadores[]) {

FILE* arquivo_qry = fopen(caminho_qry, "r");
    if (arquivo_qry == NULL) {
        printf(" não foi possível abrir o arquivo .qry!\n");
        exit(1);
    }
    FILE* arq_txt = fopen(caminho_txt, "w");
    if (arq_txt == NULL) { exit(1); }

    char linha[600];
    char comando[10];

    while (fgets(linha, sizeof(linha), arquivo_qry)) {
     sscanf(linha, "%s", comando);
     if(strcmp (comando, "pd")==0){
    int d;
    float x, y;
    sscanf(linha, "pd %d %f %f", &d, &x, &y);
     disparador_set_posicao(disparadores[d], x, y);
     }
     if (strcmp(comando, "atch") == 0) { 
            int d, cesq, cdir;
            sscanf(linha, "atch %d %d %d", &d, &cesq, &cdir);
            disparador_anexa_carregadores(disparadores[d], carregadores[cesq], carregadores[cdir]);
        }
        if (strcmp(comando, "shft") == 0) { 
            int d, n;
            char lado;
            sscanf(linha, "shft %d %c %d", &d, &lado, &n);
            for (int i = 0; i < n; i++) {
                disparador_selecionar_carga(disparadores[d], lado);
            }
            
            form forma_final = disparador_get_forma_em_posicao(disparadores[d]);
            fprintf(arq_txt, "Forma em posicao de disparo");
            imprimir_dados_forma(arq_txt, forma_final);
        }

    }
}