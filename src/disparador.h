#ifndef DISPARADOR_H
#define  DISPARADOR_H

typedef void* DISPARADOR;
typedef void* FORMA;
typedef void* CARREGADOR;

#include "pilha.h";
/**
 * @brief Cria um novo disparador numa dada posição (comando 'pd').
 * @param id O identificador único do disparador.
 * @param x A coordenada x da posição do disparador.
 * @param y A coordenada y da posição do disparador.
 * @return Um ponteiro para o Disparador criado.
 */
DISPARADOR cria_disparador(int id, float x, float y);

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
 * @brief Libera toda a memória associada a um disparador
 * @param d O disparador a ser destruído
 */
void kill_disparador(DISPARADOR d);




#endif