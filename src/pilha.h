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
 * @brief Verifica se a pilha está vazia
 * @param p A pilha a ser verificada
 * @return Retorna 1 se a pilha estiver vazia, 0 caso contrário
 */
int pilha_esta_vazia(PILHA p);

/**
 * @brief Libera toda a memória ocupada pela pilha e seus elementos
 * @param q Ponteiro para a pilha que será destruído
 */
void kill_pilha(PILHA q, void (*destruir_forma)(form f));


#endif