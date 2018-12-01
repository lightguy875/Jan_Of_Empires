//// "Copyright 2018 Jan_of_Empires"
/**
 * @file Bloco.cpp
 * @author Alex Siqueira (siqueiralex@github.com)
 * @author Alexander André (Alexander-1995@github.com)
 * @author Arthur Veiga (arthurveiga@github.com)
 * @author Matheus Veleci (matheusvsantos@github.com)
 * @author Luis Luz (lightguy875@github.com)
 * @brief 
 * @date 2018-12-01
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "../include/Bloco.hpp"
#include <iostream>

/**
 * @brief Construct a new Bloco:: Bloco object
 * 
 */
Bloco::Bloco() {
    this->conteudo = NULL;
    this->vazio = true;
}

/**
 * @brief Construct a new Bloco:: Bloco object
 * 
 * @param conteudo 
 */
Bloco::Bloco(ColocavelEmBloco *conteudo) {
    this->conteudo = conteudo;
    this->vazio = false;
}

/**
 * @brief 
 * 
 * @param c 
 * @return true 
 * @return false 
 */
bool Bloco::preenche(ColocavelEmBloco *c) {
    if (!this->vazio) return false;
    this->conteudo = c;
    this->vazio = false;
    return true;
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Bloco::limpa() {
    if (this->vazio) return false;
    this->conteudo = nullptr;
    this->vazio = true;
    return true;
}

/**
 * @brief Construct a new Colocavel Em Bloco:: Colocavel Em Bloco object
 * 
 */
ColocavelEmBloco::ColocavelEmBloco() {
    this->vivo = true;
}

/**
 * @brief 
 * 
 * @param a 
 */
void ColocavelEmBloco::setAtivo(bool a) {
    ativo = a;
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool ColocavelEmBloco::mata() {
    if (this->vivo) {
        this->vivo = false;
        this->x = -1;
        this->y = -1;
        return true;
    }
    return false;
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool ColocavelEmBloco::revive() {
    if (this->vivo)
        return false;

    this->vivo = true;
    return true;
}
