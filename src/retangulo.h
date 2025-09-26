#ifndef retangulo_h
#define retangulo_h
    
    typedef void* RETANGULO;

    /**
     * @brief função para criar p retangulo
     * @param id ID do retangulo
     * @param x coordenada x do retangulo
     * @param y coordenada y do retangulo
     * @param l largura do retangulo
     * @param h altura do retangulo
     * @param cb cor da borda do retangulo
     * @param cd cor de dentro do retangulo
     */

    RETANGULO cria_retangulo(int id, float x, float y, float l, float h, char cb, char cd);
    /**
 * @brief obtem o ID do retangulo
 * @param r o retangulo a ser consultado
 * @return int o valor do ID do retangulo
 */
int get_idR(RETANGULO r);

/**
 * @brief obtem a coordenada x do retangulo
 * @param r o retangulo a ser consultado
 * @return float o valor da coordenada x do retangulo
 */
float get_XR(RETANGULO r);

/**
 * @brief obtem a coordenada y do retangulo
 * @param r o retangulo a ser consultado
 * @return float o valor da coordenada y do retangulo
 */
float get_YR(RETANGULO r);

/**
 * @brief obtem a largura do retangulo
 * @param r o retangulo a ser consultado
 * @return float o valor da largura do retangulo
 */
float get_lR(RETANGULO r);

/**
 * @brief obtem a altura do retangulo
 * @param r o retangulo a ser consultado
 * @return float o valor da altura do retangulo
 */
float get_hR(RETANGULO r);

/**
 * @brief obtem a cor da borda do retangulo
 * @param r o retangulo a ser consultado
 * @return float o valor da cor da borda do retangulo
 */
char get_cbR(RETANGULO r);

/**
 * @brief obtem a cor de dentro do retangulo
 * @param r o retangulo a ser consultado
 * @return float o valor da cor de dentro do retangulo
 */
char get_cdR(RETANGULO r);

/**
 * @brief atualiza o id do retangulo.
 * @param r o retangulo a ser consultado
 * @param id o novo valor para o id do retangulo
 */
void set_idR(RETANGULO r, int id);

/**
 * @brief atualiza a coordenada x do retangulo.
 * @param r o retangulo a ser consultado
 * @param x o novo valor para coordenada x
 */
void set_XR(RETANGULO r, float x);

/**
 * @brief atualiza a coordenada y do retangulo.
 * @param r o retangulo a ser consultado
 * @param y o novo valor para coordenada y 
 */
void set_YR(RETANGULO r, float y);

/**
 * @brief atualiza a largura do retangulo.
 * @param r o retangulo a ser consultado
 * @param r o novo valor para a largura
 */
void set_lR(RETANGULO r, float L);

/**
 * @brief atualiza a altura do retangulo.
 * @param r o retangulo a ser consultado
 * @param r o novo valor para a altura
 */
void set_hR(RETANGULO r, float h);

/**
 * @brief atualiza a cor da borda do retangulo
 * @param r o retangulo a ser consultado
 * @param cb o nova string da cor da borda do retangulo
 */
void set_cbR(RETANGULO r, const char* cb);

/**
 * @brief atualiza a cor de dentro do retangulo
 * @param r o retangulo a ser consultado
 * @param cd a nova string da cor de dentro do retangulo
 */
void set_cdR(RETANGULO r, const char* cb);

/**
 * @brief destroi a estrutura do retangulo e libera a memoria
 * @param r o retangulo a ser consultado
 */
void kill_retang(RETANGULO r);

#endif