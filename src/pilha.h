#ifndef PILHA_H
#define PILHA_H


typedef void* PILHA;
typedef void* form;
/**
 * @brief cria uma nova pilha vazia
 * @return retorna ponteiro para nova pilha criada
 */
PILHA criar_pilha();
/**
 * @brief insere um novo elemento na pilha
 * @param f a forma a ser inserida
 * @return O ponteiro para a forma a ser guardada
 */
void inserir_na_pilha(PILHA p, form f );
/**
 * @brief remove um elemento da pilha
 * @return O ponteiro para a forma a ser removida
 */
form remover_da_pilha(PILHA p);
/**
 * @brief obtem a ultima forma da pilha sem remove-la
 * @param q a pilha a ser consultada
 * @return O ponteiro para a forma no final da pilha
 */
form get_ultimo_elementoP(PILHA p);

/**
 * @brief Libera toda a memória ocupada pela pilha e seus elementos
 * @param q Ponteiro para a pilha que será destruído
 */

void kill_pilha(PILHA q);


#endif