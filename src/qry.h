#ifndef QRY_H
#define QRY_H

#include "fila.h"
#include "pilha.h"
#include "disparador.h" 

/**
 * @brief Processa um arquivo .qry
 * @param caminho_qry Caminho do arquivo .qry
 * @param caminho_svg_base Caminho do SVG base 
 * @param caminho_svg_final Caminho para o SVG final a ser criado
 * @param caminho_txt Caminho para o arquivo .txt de log
 * @param chao Fila de formas no chão 
 * @param arena Fila de formas na arena 
 * @param carregadores vetor de pilhas 
 * @param disparadores vetor de disparadores 
 * @param cx Coordenada X do chão 
 * @param cy Coordenada Y do chão 
 * @param cw Largura do chão 
 * @param ch Altura do chão 
 * @param ccor Cor do chão 
 */
void processar_qry(char* caminho_qry, char* caminho_svg_base, char* caminho_svg_final, char* caminho_txt, 
FILA chao, FILA arena, PILHA carregadores[], DISPARADOR disparadores[], float cx, float cy, float cw, float ch, char* ccor); 
/**
 * @brief procura o id da forma e o encontra
 * @param f a fila a ser percorrida
 * @param id o id da forma a ser encontrado
 */
void* encontrar_forma_por_id(FILA f, int id);
/**
 * @brief Obtém o caractere que representa o tipo de uma forma genérica.
 * @param forma Ponteiro para a forma.
 * @return O caractere do tipo ('c', 'r', 'l', 't') ou '\0' se a forma for nula.
 */
char get_tipo_da_forma(void* forma);
/**
 * @brief Libera a memória de uma forma genérica, independentemente do seu tipo.
 * @param forma Ponteiro para a forma a ser destruída.
 */
void destruir_forma_generica(void* forma);
#endif