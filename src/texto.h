#ifndef TEXTO_H
#define TEXTO_H

typedef void* TEXTO;
/**
     * 
     * @brief Função para criar a estrutura de um texto
     * 
     * @param id ID do texto
     * @param x Eixo x da localização do texto
     * @param y Eixo y da localização do texto
     * @param cp cor do preenchimento 
     * @param a Char para indicar onde fica a âncora do texto
     * @param ctd conteudo do texto
     * @param familia A família da fonte 
     * @param peso O peso da fonte
     * @param tam O tamanho da fonte 

     * @return Retorna um ponteiro do tipo void para essa estrutura
     */

TEXTO cria_texto(int id, float x, float y, char* cb, char* cp, char a, char* txt, char* familia_atual, char* peso_atual, char* tam_atual);
 /**
 * @brief obtem o ID do texto
 * @param r o texto a ser consultado
 * @return int o valor do ID do texto
 */
int get_idT(TEXTO t);
/**
 * @brief obtem a coordenada x do texto
 * @param r o texto a ser consultado
 * @return float o valor da coordenada x do texto
 */
float get_xT(TEXTO t);
/**
 * @brief obtem a coordenada y do texto
 * @param r o texto a ser consultado
 * @return float o valor da coordenada y do texto
 */
float get_yT(TEXTO t);

/**
 * @brief obtem a cor de dentro do texto
 * @param r o texto a ser consultado
 * @return float o valor da cor de dentro do texto
 */
char* get_cpT(TEXTO t);

/**
 * @brief Obtém o caractere de ancoragem do texto.
 * A âncora define o ponto de alinhamento do texto (início, meio ou fim).
 * @param t O objeto de texto a ser consultado.
 * @return O caractere que representa a âncora ('i', 'm' ou 'f').
 */
char get_aT(TEXTO t);

/**
 * @brief Obtém o conteúdo textual de um objeto de texto.
 * @param t O objeto de texto a ser consultado.
 * @return Um ponteiro para a string que contém o texto.
 */
char* get_txtT(TEXTO t);

/**
 * @brief Calcula a área do texto
 * @param c O texto a ser consultado
 * @return A área do texto
 */
float get_areaT(TEXTO t);
/**
 * @brief obtem a cor da borda do texto
 * @param T o Ttexto a ser consultado
 * @return float o valor da cor da borda do texto
 */
char* get_cbT(TEXTO t);

/**
 * @brief Obtém o valor da espessura da borda do texto
 * @param t O objeto de texto a ser consultado
 * @return O valor numérico da espessura da borda
 */
char* get_ebT(TEXTO t);

/**
 * @brief Obtém o tamanho da fonte do texto
 * @param t O objeto de texto a ser consultado
 * @return O valor numérico do tamanho da fonte
 */
char* get_tamT(TEXTO t);



/**
 * @brief atualiza a coordenada x do texto
 * @param c o texto a ser consultado
 * @param x o novo valor para coordenada x
 */
void set_xT(TEXTO t, float x);

/**
 * @brief atualiza a coordenada y do texto
 * @param c o texto a ser consultado
 * @param y o novo valor para coordenada y
 */
void set_yT(TEXTO t, float y);

char* get_familiaT(TEXTO t);
char* get_pesoT(TEXTO t);


/**
 * @brief destroi a estrutura do texto e libera a memoria
 * @param c o texto a ser consultado
 */
void kill_texto(TEXTO t);

#endif