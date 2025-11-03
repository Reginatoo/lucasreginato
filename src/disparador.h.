#ifndef DISPARADOR_H
#define  DISPARADOR_H

typedef void* DISPARADOR;
typedef void* FORMA;
typedef void* CARREGADOR;

#include "pilha.h"
/**
 * @brief Cria um novo disparador numa dada posição 
 * @return Um ponteiro para o Disparador criado
 */
DISPARADOR cria_disparador();

/**
 * @brief Anexa os carregadores ao disparador
 * @param d O disparador onde os carregadores serão anexados
 * @param carregador_esquerdo A Pilha que será o carregador esquerdo
 * @param carregador_direito A Pilha que será o carregador direito
 */
void disparador_anexar_carregadores(DISPARADOR d, CARREGADOR carregador_esquerdo, CARREGADOR carregador_direito);

/**
 * @brief  seleção da carga direita ou esquerda 
 * @param d O disparador a ser operado
 * @param lado O lado do qual carregar
 */
void disparador_selecionar_carga(DISPARADOR d, char lado);

/**
 * @brief Define a posição de um disparador
 * @param d o disparador a ser consultado
 * @param x a coordenada x do disparador
 * @param y a coordenada y do disparador
 */
void disparador_set_posicao(DISPARADOR d, float x, float y);

/**
 * @brief Dispara a forma que está na posição de disparo 
 * @param d O disparador que vai atirar
 * @return A Forma que foi disparada
 */
FORMA disparador_disparar(DISPARADOR d);

 /**
 * @brief Obtém a coordenada x da posição de um disparador
 * @param d O disparador a ser consultado
 * @return A coordenada x do disparador
 */
float disparador_get_x(DISPARADOR d);

 /**
 * @brief Obtém a coordenada y da posição de um disparador
 * @param d O disparador a ser consultado
 * @return A coordenada y do disparador
 */
float disparador_get_y(DISPARADOR d);

/**
 * @brief Obtém a forma que está atualmente na posição de disparo, sem a remover
 * @param d O disparador a ser consultado
 * @return A forma que está em posição
 */
FORMA disparador_get_forma_em_posicao(DISPARADOR d);

/**
 * @brief Obtém o carregador que está anexado no lado esquerdo do disparador
 * @param d O disparador a ser consultado
 * @return A PILHA que representa o carregador esquerdo
 */
PILHA disparador_get_carregador_esquerdo(DISPARADOR d);

/**
 * @brief Obtém o carregador que está anexado no lado direito do disparador
 * @param d O disparador a ser consultado
 * @return A PILHA que representa o carregador direito
 */
PILHA disparador_get_carregador_direito(DISPARADOR d);
/**
 * @brief Libera toda a memória associada a um disparador
 * @param d O disparador a ser destruído
 */
void kill_disparador(DISPARADOR d);




#endif