#ifndef SVG_H
#define SVG_H

#include <stdio.h>
#include "fila.h" 

/**
 * @brief Gera um ficheiro SVG 
 * @param caminho_svg O nome/caminho do ficheiro SVG a ser criado
 * @param chao Fila de formas no chão
 * @param arena Fila de formas na arena
 * @param cx Coordenada X do chão
 * @param cy Coordenada Y do chão
 * @param cw Largura do chão
 * @param ch Altura do chão
 * @param ccor Cor da borda do chão
 */
void desenhar_svg(char* caminho_svg, FILA chao, FILA arena,
                  float cx, float cy, float cw, float ch, char* ccor); 

#endif