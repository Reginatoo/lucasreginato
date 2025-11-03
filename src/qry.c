#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qry.h"
#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "disparador.h"
#include "fila.h" 
#include "pilha.h"
#include "colisao.h"
#include "svg.h"

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

int get_id_da_forma(void* forma) {
    if (forma == NULL) return -1; 

    switch (get_tipo_da_forma(forma)) {
        case 'c': return get_idC(forma);
        case 'r': return get_idR(forma);
        case 'l': return get_idL(forma);
        case 't': return get_idT(forma);
    }
    
    return -1;
}

float get_area_da_forma(void* forma) {
    if (forma == NULL) return 0;
    switch (get_tipo_da_forma(forma)) {
        case 'c': return get_areaC(forma);
        case 'r': return get_areaR(forma);
        case 'l': return get_areaL(forma);
        case 't': return get_areaT(forma);
    }
    return 0;
}

float get_x_da_forma(void* forma) {
    if (forma == NULL) return 0;
    switch (get_tipo_da_forma(forma)) {
        case 'c': return get_XC(forma);
        case 'r': return get_XR(forma);
        case 'l': return get_X1L(forma); 
        case 't': return get_xT(forma);
    }
    return 0;
}

float get_y_da_forma(void* forma) {
    if (forma == NULL) return 0;
    switch (get_tipo_da_forma(forma)) {
        case 'c': return get_YC(forma);
        case 'r': return get_YR(forma);
        case 'l': return get_Y1L(forma); 
        case 't': return get_yT(forma);
    }
    return 0;
}

void set_corb_da_forma(void* forma, char* nova_cor) {
    if (forma == NULL) return;
    switch (get_tipo_da_forma(forma)) {
        case 'c': set_cbC(forma, nova_cor); break;
        case 'r': set_cbR(forma, nova_cor); break;
        case 'l': set_CorL(forma, nova_cor); break;
        case 't': set_cbT(forma, nova_cor);  break; 
    }
}

char* get_corp_da_forma(void* forma) {
    if (forma == NULL) return "black";
    switch (get_tipo_da_forma(forma)) {
        case 'c': return get_cpC(forma);
        case 'r': return get_cpR(forma);
        case 't': return get_cpT(forma);
    }
    return "black"; 
} 

void set_cp_da_forma(void* forma, char* nova_cor) {
    if (forma == NULL) return;
    switch (get_tipo_da_forma(forma)) {
        case 'c': set_cpC(forma, nova_cor); break;
        case 'r': set_cpR(forma, nova_cor); break;
        // Linhas não têm cor de preenchimento
        case 't': set_cpT(forma, nova_cor); break;
    }
}

void destruir_forma_generica(void* forma) {
    if (forma == NULL) return;
    switch (get_tipo_da_forma(forma)) {
        case 'c': kill_circ(forma); break;
        case 'r': kill_retang(forma); break;
        case 'l': kill_linha(forma); break;
        case 't': kill_texto(forma); break;
    }
}

void set_id_da_forma(void* forma, int id) {
    if (forma == NULL) return;
    switch (get_tipo_da_forma(forma)) {
        case 'c': set_idC(forma, id); break;
        case 'r': set_idR(forma, id); break;
        case 'l': set_idL(forma, id); break;
        case 't': set_idT(forma, id); break;
    }
}

int maior_id_global = 0; 

form clone_forma(void* forma) {
    if (forma == NULL) return NULL;
    
    char tipo = get_tipo_da_forma(forma);
    
    switch (tipo) {
        case 'c': 
            return clone_circulo(forma); 
        case 'r': 
            return clone_retangulo(forma);
        case 'l': 
            return clone_linha(forma);
        case 't': 
            return clone_texto(forma);
        default:
            return NULL;
    }
}

char* get_corb_da_forma(void* forma) {
    if (forma == NULL) return "black";
    switch (get_tipo_da_forma(forma)) {
        case 'c': return get_cbC(forma);
        case 'r': return get_cbR(forma);
        case 'l': return get_CorL(forma);
        case 't': return get_cbT(forma);
    }
    return "black";
}

void set_posicao_da_forma(void* forma, float x, float y) {
    if (forma == NULL) return;
    char tipo = get_tipo_da_forma(forma);
    
    switch (tipo) {
        case 'c': 
            set_posicaoC(forma, x, y); 
            break;
        case 'r': 
            set_posicaoR(forma, x, y); 
            break;
        case 'l': 
            set_posicaoL(forma, x, y); 
            break;
        case 't': 
            set_posicaoT(forma, x, y); 
            break;
    }
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
                    get_idC(forma), get_XC(forma), get_YC(forma), get_RC(forma),
                    get_cbC(forma), get_cpC(forma));
            break;
        case 'r':
            fprintf(arq_txt, " Retangulo ID:%d, X:%f, Y:%f, W:%f, H:%f, Borda:%s, Preench:%s\n",
                    get_idR(forma), get_XR(forma), get_YR(forma), get_WR(forma), get_HR(forma),
                    get_cbR(forma), get_cpR(forma));
            break;
           case 'l':
            fprintf(arq_txt, " Linha ID:%d, X1:%f, Y1:%f, X2:%f, Y2:%f, Cor:%s\n",
                    get_idL(forma), get_X1L(forma), get_Y1L(forma), get_X2L(forma), get_Y2L(forma),
                    get_CorL(forma));
            break;

        case 't':
            fprintf(arq_txt, " Texto ID:%d, X:%f, Y:%f, Borda:%s, Preench:%s, Ancora:'%c', Conteudo:\"%s\"\n",
                    get_idT(forma), get_xT(forma), get_yT(forma), get_cbT(forma), get_cpT(forma),
                    get_aT(forma), get_txtT(forma));
            break;
        
    }
}

void processar_qry(char* caminho_qry, char* caminho_svg_base, char* caminho_svg_final, char* caminho_txt, 
                   FILA chao, FILA arena, PILHA carregadores[], DISPARADOR disparadores[],
                   float cx, float cy, float cw, float ch, char* ccor) {
                       
    FILE* arq_qry = fopen(caminho_qry, "r");
    if (arq_qry == NULL) {
        printf(" não foi possível abrir o arquivo .qry!\n");
        exit(1);
    }
    FILE* arq_txt = fopen(caminho_txt, "w");
    if (arq_txt == NULL) { exit(1); }

    char linha[600];
    char comando[10];
    float pontuacao_total = 0;
    int instrucoes_executadas = 0;
    int disparos_total = 0;
    int formas_esmagadas = 0;
    int formas_clonadas = 0;

    while (fgets(linha, sizeof(linha), arq_qry)){
        sscanf(linha, "%s", comando);

        if(strcmp (comando, "pd")==0){
            int d;
            float x, y;
            sscanf(linha, "pd %d %f %f", &d, &x, &y);
            disparador_set_posicao(disparadores[d], x, y);
            instrucoes_executadas++;
        }

        if (strcmp(comando, "lc") == 0) {
            int c, n;
            sscanf(linha, "lc %d %d", &c, &n);

            fprintf(arq_txt, "Carregando %d formas no carregador %d:\n", n, c);

            for (int i = 0; i < n; i++) {
                if (fila_esta_vazia(chao)) {
                    fprintf(arq_txt, "  > O chao ficou vazio. Carregamento interrompido.\n");
                    break;
                }
                form forma_movida = remover_da_fila(chao);
                int id_atual = get_id_da_forma(forma_movida);
                if (id_atual > maior_id_global) {
                    maior_id_global = id_atual;
                }
                inserir_na_pilha(carregadores[c], forma_movida);
                imprimir_dados_forma(arq_txt, forma_movida); 
            }
        }
        
        if (strcmp(comando, "atch") == 0){ 
            int d, cesq, cdir;
            sscanf(linha, "atch %d %d %d", &d, &cesq, &cdir);
            disparador_anexar_carregadores(disparadores[d], carregadores[cesq], carregadores[cdir]);
            instrucoes_executadas++;
        }
        
        if (strcmp(comando, "shft") == 0){ 
            int d, n;
            char lado;
            sscanf(linha, "shft %d %c %d", &d, &lado, &n);
            for (int i = 0; i < n; i++) {
                disparador_selecionar_carga(disparadores[d], lado);
            }
            instrucoes_executadas++;
            
            form forma_final = disparador_get_forma_em_posicao(disparadores[d]);
            if (forma_final != NULL) {
                fprintf(arq_txt, "Forma em posicao de disparo \n");
                imprimir_dados_forma(arq_txt, forma_final);
            } else {
                fprintf(arq_txt, "Nenhuma forma em posicao de disparo apos o SHFT.\n");
            }
        }
        
        if (strcmp(comando, "dsp") == 0){
            int d;
            float dx, dy;
            char modo;
            sscanf(linha, "dsp %d %f %f %c", &d, &dx, &dy, &modo); 

            form forma_disparada = disparador_disparar(disparadores[d]);
            if (forma_disparada != NULL) {
                float dispx = disparador_get_x(disparadores[d]);
                float dispy = disparador_get_y(disparadores[d]);
                float final_x, final_y;
                
                final_x = dispx + dx;
                final_y = dispy + dy;

                if (modo == 'v') {
                    form linha_visu = cria_linha(-1, dispx, dispy, final_x, final_y, "MediumVioletRed");
                    inserir_na_fila(chao, linha_visu);
                }
                
                inserir_na_fila(arena, forma_disparada);
                set_posicao_da_forma(forma_disparada, final_x, final_y);
                fprintf(arq_txt, "Forma disparada \n");
                imprimir_dados_forma(arq_txt, forma_disparada);
                disparos_total++;
                instrucoes_executadas++;
                
            }
        }
        
        if (strcmp(comando, "rjd") == 0) {
            int d;
            char lado; 
            float dx, dy, ix, iy;
            sscanf(linha, "rjd %d %c %f %f %f %f", &d, &lado, &dx, &dy, &ix, &iy);
            
            PILHA carregador_ativo;
            int i = 0;

            if (lado == 'd') { 
                carregador_ativo = disparador_get_carregador_esquerdo(disparadores[d]);
                fprintf(arq_txt, "Disparando todas as formas do carregador ESQUERDO (disparador %d):\n", d);
            } else if (lado == 'e') { 
                carregador_ativo = disparador_get_carregador_direito(disparadores[d]);
                fprintf(arq_txt, "Disparando todas as formas do carregador DIREITO (disparador %d):\n", d);
            }

            while (carregador_ativo != NULL && !pilha_esta_vazia(carregador_ativo)) {
                
                form forma_disparada = remover_da_pilha(carregador_ativo); 
                                
                if (forma_disparada != NULL) {
                    float dispx = disparador_get_x(disparadores[d]);
                    float dispy = disparador_get_y(disparadores[d]);
                    float final_x = dispx + dx + (i * ix);
                    float final_y = dispy + dy + (i * iy);
                    inserir_na_fila(arena, forma_disparada);
                    set_posicao_da_forma(forma_disparada, final_x, final_y);
                    imprimir_dados_forma(arq_txt, forma_disparada);
                }
                disparos_total++;
                i++;
            }
            instrucoes_executadas++;
        }

        if (strcmp(comando, "calc") == 0) {
            float pontuacao_round = 0;
            fprintf(arq_txt, "Processando colisoes na arena:\n");

            while (tamanho_fila(arena) >= 2) {
                form I = remover_da_fila(arena);
                form J = remover_da_fila(arena);

                if (verifica_sobreposicao(I, J)) {
                    float areaI = get_area_da_forma(I);
                    float areaJ = get_area_da_forma(J);
                    int idI = get_id_da_forma(I);
                    int idJ = get_id_da_forma(J);

                    fprintf(arq_txt, "  > Verificando ID %d (area %.2f) vs ID %d (area %.2f): SOBREPOSICAO\n", idI, areaI, idJ, areaJ);

                    if (areaI < areaJ) {
                        pontuacao_round += areaI;
                        float x_esmagado = get_x_da_forma(I);
                        float y_esmagado = get_y_da_forma(I);
                        destruir_forma_generica(I);
                        inserir_na_fila(chao, J);
                        formas_esmagadas++;

                        form asterisco = cria_texto(-1, x_esmagado, y_esmagado, "none", "red", 'm', "*", "Arial", "bold", "12");
                        inserir_na_fila(chao, asterisco);

                        fprintf(arq_txt, "    >> Resultado: Forma ID %d esmagada. Pontos: %.2f. Forma ID %d volta para o chao.\n", idI, areaI, idJ);
                    
                    } else if (areaI > areaJ) {
                        char* cor_preenchimento_I = get_corp_da_forma(I);
                        set_corb_da_forma(J, cor_preenchimento_I);

                        inserir_na_fila(chao, I);
                        inserir_na_fila(chao, J);

                        form clone = clone_forma(I);
                        set_id_da_forma(clone, ++maior_id_global);
                        set_corb_da_forma(clone, get_corp_da_forma(I)); 
                        set_cp_da_forma(clone, get_corb_da_forma(I)); 
                        inserir_na_fila(chao, clone);
                        formas_clonadas++;
                        fprintf(arq_txt, "    >> Resultado: Forma ID %d modificou ID %d e se clonou. Todas voltam para o chao.\n", idI, idJ);
                    } else { 
                        fprintf(arq_txt, "    >> Resultado: Areas iguais. Ambas voltam para o chao sem alteracao.\n");
                        inserir_na_fila(chao, I);
                        inserir_na_fila(chao, J);
                    }
                } else {
                    fprintf(arq_txt, "  > Verificando ID %d vs ID %d: SEM sobreposicao. Ambas voltam para o chao.\n", get_id_da_forma(I), get_id_da_forma(J));
                    inserir_na_fila(chao, I);
                    inserir_na_fila(chao, J);
                }
            }
            
            if (tamanho_fila(arena) == 1) {
                form sobra = remover_da_fila(arena);
                fprintf(arq_txt, "  > Forma ID %d sobrou na arena e voltou para o chao.\n", get_id_da_forma(sobra));
                inserir_na_fila(chao, sobra);
            }
            pontuacao_total += pontuacao_round;
            fprintf(arq_txt, "Pontuacao do Round: %.2f\nPontuacao Total Acumulada: %.2f\n", pontuacao_round, pontuacao_total);
            instrucoes_executadas++;
        }

    }
    desenhar_svg(caminho_svg_final, chao, arena, cx, cy, cw, ch, ccor);

    fprintf(arq_txt, "\n\nRELATORIO FINAL:\n");
    fprintf(arq_txt, "Pontuacao Final: %.2f\n", pontuacao_total);
    fprintf(arq_txt, "Numero Total de Instrucoes Executadas: %d\n", instrucoes_executadas);
    fprintf(arq_txt, "Numero Total de Disparos: %d\n", disparos_total);
    fprintf(arq_txt, "Numero Total de Formas Esmagadas: %d\n", formas_esmagadas);
    fprintf(arq_txt, "Numero Total de Formas Clonadas: %d\n", formas_clonadas);

    fclose(arq_qry);
    fclose(arq_txt);
    }