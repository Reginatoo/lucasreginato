#ifndef COLISAO_H
#define COLISAO_H

#include "fila.h" // Para o typedef 'form'

/**
 * @brief Verifica se duas formas genéricas se sobrepõem
 * * @param forma_i A primeira forma
 * @param forma_j A segunda forma
 * @return Retorna 1 se houver sobreposição, 0 caso contrário
 */
int verifica_sobreposicao(form forma_i, form forma_j);

#endif