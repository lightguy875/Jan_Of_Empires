//// "Copyright 2018 Jan_of_Empires"
/**
 * @file Mapa.cpp
 * @author Alex Siqueira (siqueiralex@github.com)
 * @author Alexander André (Alexander-1995@github.com)
 * @author Arthur Veiga (arthurveiga@github.com)
 * @author Matheus Veleci (matheusvsantos@github.com)
 * @author Luis Luz (lightguy875@github.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-01
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "../include/Mapa.hpp"

/**
 * @brief Construct a new Mapa:: Mapa object
 * 
 * @param X = tamanho do eixo X do mapa
 * @param Y = tamanho do eixo Y do mapa 
 */
Mapa::Mapa(unsigned short X, unsigned short Y) {
    this->tam_x = X;
    this->tam_y = Y;
    int i, j;
    for (i = 0; i < X; i++)
        for (j = 0; j < Y; j++)
            this->mapa[std::make_pair(i, j)] = Bloco();
}

/**
 * @brief verifica se um par X/Y corresponde a uma posição válida
 * 
 * @param X, Y = posição a ser verificada 
 * @return true se é válida
 * @return false se não é válida
 *
 * Assertivas de Entrada:
 * inicializado(mapa) == True
 * 
 * Assertivas de Saída:
 * mantem_consistente(mapa) == True
 */
bool Mapa::posicao_valida(unsigned short X, unsigned short Y) {
    return X < this->tam_x && Y < this->tam_y;
}

/**
 * @brief verifica se um par X/Y corresponde a uma posição vazia do mapa
 * 
 * @param X, Y = posição a ser verificada 
 * @return true se está vazia
 * @return false se não está vazia
 *
 * Assertivas de Entrada:
 * inicializado(mapa) == True
 * 
 * Assertivas de Saída:
 * mantem_consistente(mapa) == True
 */
bool Mapa::vazio(unsigned short X, unsigned short Y) {
    if (!this->posicao_valida(X, Y)) return false;

    return this->mapa[std::make_pair(X, Y)].vazio;
}

/**
 * @brief Insere conteudo em um bloco
 * 
 * @param item = ponteiro pro item a ser colocado no bloco
 * @param X, Y = posição do bloco a ser preenchida 
 * @return true se foi possivel inserir
 * @return false se não foi possível inserir
 *
 * Assertivas de Entrada:
 * inicializado(mapa) == True
 * item_valido(item) == True 
 *
 * Assertivas de Saída:
 * mapa == mapa || com_item_inserido(mapa)
 */
bool Mapa::inserir(ColocavelEmBloco *item, unsigned short X, unsigned short Y) {
    if (!this->vazio(X, Y)) return false;

    this->mapa[std::make_pair(X, Y)].preenche(item);
    item->x = X;
    item->y = Y;
    return true;
}

/**
 * @brief consulta conteúdo de bloco
 * 
 * @param X, Y = posição do bloco 
 * @return ColocavelEmBloco* = ponteiro para o conteúdo do bloco
 *
 * Assertivas de Entrada:
 * inicializado(mapa) == True
 * posição_válida_e_não_vazia(X,Y) == True
 *
 * Assertivas de Saída:
 * mapa == nao_alterado(mapa)
 */
ColocavelEmBloco* Mapa::ver(unsigned short X, unsigned short Y) {
    if (this->vazio(X, Y) || !this->posicao_valida(X, Y)) return nullptr;
    ColocavelEmBloco *conteudo = this->mapa[std::make_pair(X, Y)].conteudo;

    return conteudo;
}

/**
 * @brief retira conteúdo de bloco
 * 
 * @param X, Y = posição do bloco 
 * @return ColocavelEmBloco* = ponteiro para o conteúdo do bloco
 *
 * Assertivas de Entrada:
 * inicializado(mapa) == True
 * posição_válida_e_não_vazia(X,Y) == True
 *
 * Assertivas de Saída:
 * mapa == com_conteudo_retirado(mapa)
 */
ColocavelEmBloco* Mapa::retirar(unsigned short X, unsigned short Y) {
    if (this->vazio(X, Y) || !this->posicao_valida(X, Y)) return nullptr;
    ColocavelEmBloco *conteudo = this->mapa[std::make_pair(X, Y)].conteudo;
    this->mapa[std::make_pair(X, Y)].limpa();

    return conteudo;
}
