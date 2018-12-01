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
 * @param X 
 * @param Y 
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
 * @brief 
 * 
 * @param X 
 * @param Y 
 * @return true 
 * @return false 
 */
bool Mapa::posicao_valida(unsigned short X, unsigned short Y) {
    return X < this->tam_x && Y < this->tam_y;
}

/**
 * @brief 
 * 
 * @param X 
 * @param Y 
 * @return true 
 * @return false 
 */
bool Mapa::vazio(unsigned short X, unsigned short Y) {
    if (!this->posicao_valida(X, Y)) return false;

    return this->mapa[std::make_pair(X, Y)].vazio;
}

/**
 * @brief 
 * 
 * @param item 
 * @param X 
 * @param Y 
 * @return true 
 * @return false 
 */
bool Mapa::inserir(ColocavelEmBloco *item, unsigned short X, unsigned short Y) {
    if (!this->vazio(X, Y)) return false;

    this->mapa[std::make_pair(X, Y)].preenche(item);
    item->x = X;
    item->y = Y;
    return true;
}

/**
 * @brief 
 * 
 * @param X 
 * @param Y 
 * @return ColocavelEmBloco* 
 */
ColocavelEmBloco* Mapa::ver(unsigned short X, unsigned short Y) {
    if (this->vazio(X, Y) || !this->posicao_valida(X, Y)) return nullptr;
    ColocavelEmBloco *conteudo = this->mapa[std::make_pair(X, Y)].conteudo;

    return conteudo;
}

/**
 * @brief 
 * 
 * @param X 
 * @param Y 
 * @return ColocavelEmBloco* 
 */
ColocavelEmBloco* Mapa::retirar(unsigned short X, unsigned short Y) {
    if (this->vazio(X, Y) || !this->posicao_valida(X, Y)) return nullptr;
    ColocavelEmBloco *conteudo = this->mapa[std::make_pair(X, Y)].conteudo;
    this->mapa[std::make_pair(X, Y)].limpa();

    return conteudo;
}
