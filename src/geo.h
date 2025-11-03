#ifndef GEO_H
#define GEO_H

#include "fila.h" 
/**
 * @brief Processa um arquivo .geo, lendo todas as formas e as definições do cenário
 * @param caminho_geo O caminho completo para o arquivo .geo
 * @param chao A fila onde as formas do chão serão armazenadas
 * @param arena A fila onde as formas da arena serão armazenadas
 * @param chao_x Ponteiro para a variável que guardará a coordenada x do chão
 * @param chao_y Ponteiro para a variável que guardará a coordenada y do chão
 * @param chao_w Ponteiro para a variável que guardará a largura do chão
 * @param chao_h Ponteiro para a variável que guardará a altura do chão
 * @param chao_cor Array de char que guardará a cor do chão
 * @param arena_x Ponteiro para a variável que guardará a coordenada x da arena
 * @param arena_y Ponteiro para a variável que guardará a coordenada y da arena
 * @param arena_w Ponteiro para a variável que guardará a largura da arena
 * @param arena_h Ponteiro para a variável que guardará a altura da arena
 * @param arena_cor Array de char que guardará a cor da arena
 */
void processar_geo(char* caminho_geo, FILA chao, FILA arena, float* chao_x, float* chao_y, float* chao_w, float* chao_h, char chao_cor[], float* arena_x, float* arena_y, float* arena_w, float* arena_h, char arena_cor[]);


#endif