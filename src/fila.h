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
 * @brief obtem a primeira no da fila sem remove-la
 * @param q a fila a ser consultada
 * @return O ponteiro para a forma no início da fila
 */
void* get_primeiro_no(FILA q);

/**
 * @brief obtem o proxima no da fila sem remove-la
 * @param q a fila a ser consultada
 * @return O ponteiro para a forma no início da fila
 */
void* get_proximo_no(void* no);

/**
 * @brief obtem a forma do no
 * @param q a fila a ser consultada
 * @return retorna a forma do no
 */
void* get_info_do_no(void* no);

/**
 * @brief Destroi a fila e todos os seus elementos.
 * @param q A fila a ser destruída.
 * @param destruir_forma Uma função que sabe como libertar a memória de uma forma.
 */
void kill_fila(FILA q, void (*destruir_forma)(form f));


#endif