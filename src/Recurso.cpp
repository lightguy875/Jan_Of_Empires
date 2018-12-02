//// "Copyright 2018 Jan_of_Empires"
/**
 * @file Recurso.cpp
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
#include "../include/Recurso.hpp"

/**
 * @brief Construct a new Recurso:: Recurso object
 * 
 */
Recurso::Recurso() {
    this->tipo = TipoConteudoBloco::RECURSO;
}

/**
 * @brief Construct a new Ossos:: Ossos object
 * 
 */
Ossos::Ossos() {
    this->qtde = QUANTIDADE_OSSOS_POR_ITEM;
    this->tipo_recurso = TipoRecurso::OSSOS;
}

/**
 * @brief Construct a new Metal:: Metal object
 * 
 */
Metal::Metal() {
    this->qtde = QUANTIDADE_METAL_POR_ITEM;
    this->tipo_recurso = TipoRecurso::METAL;
}

