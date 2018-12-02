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
 * @param conteudo =  conteudo a ser colocado no bloco inicializado
 */
Bloco::Bloco(ColocavelEmBloco *conteudo) {
    this->conteudo = conteudo;
    this->vazio = false;
}

/**
 * @brief coloca conteudo no bloco
 * 
 * @param c  = ponteiro para o conteudo a ser colocado
 * @return true se foi possivel colocar
 * @return false  se não foi possível colocar
 * 
 * Assertivas de Entrada:
 * inicializado(bloco) == True
 * conteudo_valido(c) == True
 *
 * Assertivas de Saida:
 * bloco == bloco || preenchido(bloco)
 */
bool Bloco::preenche(ColocavelEmBloco *c) {
    if (!this->vazio) return false;
    this->conteudo = c;
    this->vazio = false;
    return true;
}

/**
 * @brief Limpa o conteudo do bloco
 * 
 * @return true se foi possivel limpar
 * @return false se nao foi possivel limpar
 * 
 * Assertivas de Entrada:
 * inicializado(bloco) == True
 *
 * Assertivas de Saída:
 * limpo(bloco) == True
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
 * @brief altera o conteudo da variavel ativo de uma peça que herda de Colocavel em Bloco .
 * 
 * @param a = valor a ser colocado na variavel
 * Assertivas de Entrada:
 * inicializada(peca) == True
 *
 * Assertivas de Saída:
 * peca.ativo == a
 */
void ColocavelEmBloco::setAtivo(bool a) {
    ativo = a;
}

/**
 * @brief Mata uma peça que herda de Colocavel em bloco
 * 
 * @return true se foi possível matar
 * @return false se não foi possível matar
 *
 * Assertivas de Entrada:
 * inicializada(peca) == True
 *
 * Assertivas de Saída:
 * morta(peca) == True
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
 * @brief Ressucita uma peça que herda de Colocavel em bloco
 * 
 * @return true se foi possível reviver
 * @return false se não foi possível reviver
 *
 * Assertivas de Entrada:
 * inicializada(peca) == True
 *
 * Assertivas de Saída:
 * viva(peca) == True
 */
bool ColocavelEmBloco::revive() {
    if (this->vivo)
        return false;

    this->vivo = true;
    return true;
}
