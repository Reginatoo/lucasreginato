#ifndef QRY_H
#define QRY_H

#include "fila.h"
#include "pilha.h"

/**
 * @brief processa um arquivo .qry, executando todas as consultas e ações no cenário.
 * @param caminho_qry o caminho completo para o arquivo .qry
 * @param caminho_svg o caminho para o arquivo SVG 
 * @param caminho_txt o caminho para o arquivo onde os resultados serão escritos
 * @param chao o fila com as formas do chão
 * @param arena a fila com as formas da arena
 * @param carregadores o vetor de pilhas de carregadores
 */
void processar_qry(char* caminho_qry, char* caminho_svg, char* caminho_txt, FILA chao, FILA arena, PILHA carregadores[], DISPARADOR disparadores[]);

/**
 * @brief procura o id da forma e o encontra
 * @param f a fila a ser percorrida
 * @param id o id da forma a ser encontrado
 */
void* encontrar_forma_por_id(FILA f, int id);
#endif