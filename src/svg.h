#ifndef SVG_H
#define SVG_H

#include "fila.h" 
/**
 * @brief desenha o cenario em um svg
 * @param caminho_svg o caminho completo para o svg
 * @param chao a fila onde as formas do chão serão armazenadas
 * @param arena a fila onde as formas da arena serão armazenadas
 * @param chao_x propriedade do retangulo do chao
 * @param chao_y propriedade do retangulo do chao
 * @param chao_w a largura do chao
 * @param chao_h a altura do chão
 * @param chao_cor a cor do chão
 * @param arena_x propriedade do retangulo da arena
 * @param arena_y propriedade do retangulo da arena
 * @param arena_w a largura da arena
 * @param arena_h a altura da arena
 * @param arena_cor a cor da arena
 */
void desenha_svg(char* caminho_svg, FILA chao, FILA arena, float chao_x, float chao_y, float chao_w, float chao_h, char chao_cor[], float arena_x, float arena_y, float arena_w, float arena_h, char arena_cor[]);



#endif 