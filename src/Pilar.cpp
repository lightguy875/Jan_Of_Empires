//// "Copyright 2018 Jan_of_Empires"
/**
 * @file Pilar.cpp
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
#include "../include/Pilar.hpp"
/*
    Setando diferentes valores iniciais de mp
    de acordo com o tipo de necromancer
*/

/**
 * @brief Construct a new Pilar:: Pilar object
 * 
 */
Pilar::Pilar() {
    this->tipo = TipoConteudoBloco::PREDIO;
}

#ifdef PROD
/**
 * @brief 
 * 
 * @param e 
 * @param position_x 
 * @param position_y 
 * @return true 
 * @return false 
 */
bool Pilar::handleEvent(SDL_Event * e, int position_x, int position_y) {
    if (e->type == SDL_MOUSEBUTTONDOWN) {
        // Get mouse position
        int x, y;
        SDL_GetMouseState(&x, &y);
        // Check if mouse is in Button
        bool inside = false;
        if (y > position_y && y < (position_y + 40)) {
            if (x > position_x && x < (position_x + 40)) {
                inside = true;
            }
        }
        if (inside) {
            switch (e->type) {
                case SDL_MOUSEBUTTONDOWN:
                    return true;
                break;
            }
        }
    }
    return false;
}
#endif

/**
 * @brief Construct a new Pilar Lanca:: Pilar Lanca object
 * 
 */
PilarLanca::PilarLanca() {
    this->tipo_pilar = TipoPilar::LANCA;
    this->hp = HP_INICIAL_PILAR_LANCA;
}

/**
 * @brief Construct a new Pilar Arco:: Pilar Arco object
 * 
 */
PilarArco::PilarArco() {
    this->tipo_pilar = TipoPilar::ARCO;
    this->hp = HP_INICIAL_PILAR_ARCO;
}

/**
 * @brief Construct a new Pilar Espada:: Pilar Espada object
 * 
 */
PilarEspada::PilarEspada() {
    this->tipo_pilar = TipoPilar::ESPADA;
    this->hp = HP_INICIAL_PILAR_ESPADA;
}
