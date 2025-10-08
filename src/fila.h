#ifndef FILA_H
#define FILA_H


typedef void* FILA;
typedef void* form;
/**
 * @brief cria uma nova fila vazia
 * @return retorna ponteiro para nova fila criada
 */
FILA criar_fila();
/**
 * @brief insere um novo elemento na fila
 * @param f a forma a ser inserida
 * @return O ponteiro para a forma a ser guardada
 */
void inserir_na_fila(FILA q, form f );
/**
 * @brief remove um elemento da fila
 * @return O ponteiro para a forma a ser removida
 */
form remover_da_fila(FILA q);
/**
 * @brief obtem a primeira forma da lista sem remove-la
 * @param q a fila a ser consultada
 * @return O ponteiro para a forma no início da fila
 */
form get_primeiro_elementoF(FILA q);

/**
 * @brief Libera toda a memória ocupada pela fila e seus elementos
 * @param q Ponteiro para a fila que será destruído
 */

void kill_fila(FILA q);


#endif