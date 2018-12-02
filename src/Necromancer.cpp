//// "Copyright 2018 Jan_of_Empires"
/**
 * @file Necromancer.cpp
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
#include "../include/Necromancer.hpp"

/**
 * @brief retorna no multiplicador de ataque do necromancer contra um pilar
 * 
 * @param tipo = tipo de necromancer inimigo
 * @return unsigned short = numero multiplicador
 *
 * Assertivas de Entrada:
 * tipo_valido(tipo) == True
 *
 * Assertivas de Saída:
 * multiplicador > 0
 */
unsigned short Necromancer::multiplicador(TipoPilar tipo) {
    if (this->tipo_necromancer == TipoNecromancer::ARQUEIRO) {
        if (tipo == TipoPilar::ESPADA)
            return ARCO_ESPADA_ATQ_MULTIPLICADOR;

        if (tipo == TipoPilar::LANCA)
            return ARCO_LANCA_ATQ_MULTIPLICADOR;

        if (tipo == TipoPilar::ARCO)
            return ARCO_ARCO_ATQ_MULTIPLICADOR;
    }
    if (this->tipo_necromancer == TipoNecromancer::CAVALEIRO) {
        if (tipo == TipoPilar::ESPADA)
            return LANCA_ESPADA_ATQ_MULTIPLICADOR;

        if (tipo == TipoPilar::LANCA)
            return LANCA_LANCA_ATQ_MULTIPLICADOR;

        if (tipo == TipoPilar::ARCO)
            return LANCA_ARCO_ATQ_MULTIPLICADOR;
    }
    if (this->tipo_necromancer == TipoNecromancer::GUERREIRO) {
        if (tipo == TipoPilar::ESPADA)
            return ESPADA_ESPADA_ATQ_MULTIPLICADOR;

        if (tipo == TipoPilar::LANCA)
            return ESPADA_LANCA_ATQ_MULTIPLICADOR;

        if (tipo == TipoPilar::ARCO)
            return ESPADA_ARCO_ATQ_MULTIPLICADOR;
    }
    return 0;
}

/**
 * @brief retorna no multiplicador de ataque do necromancer contra um outro necromancer
 * 
 * @param tipo = tipo de necromancer inimigo
 * @return unsigned short = numero multiplicador
 *
 * Assertivas de Entrada:
 * tipo_valido(tipo) == True
 *
 * Assertivas de Saída:
 * multiplicador > 0
 */
unsigned short Necromancer::multiplicador(TipoNecromancer tipo) {
    if (this->tipo_necromancer == TipoNecromancer::ARQUEIRO) {
        if (tipo == TipoNecromancer::GUERREIRO)
            return ARCO_ESPADA_ATQ_MULTIPLICADOR;

        if (tipo == TipoNecromancer::CAVALEIRO)
            return ARCO_LANCA_ATQ_MULTIPLICADOR;

        if (tipo == TipoNecromancer::ARQUEIRO)
            return ARCO_ARCO_ATQ_MULTIPLICADOR;
    }
    if (this->tipo_necromancer == TipoNecromancer::CAVALEIRO) {
        if (tipo == TipoNecromancer::GUERREIRO)
            return LANCA_ESPADA_ATQ_MULTIPLICADOR;

        if (tipo == TipoNecromancer::CAVALEIRO)
            return LANCA_LANCA_ATQ_MULTIPLICADOR;

        if (tipo == TipoNecromancer::ARQUEIRO)
            return LANCA_ARCO_ATQ_MULTIPLICADOR;
    }
    if (this->tipo_necromancer == TipoNecromancer::GUERREIRO) {
        if (tipo == TipoNecromancer::GUERREIRO)
            return ESPADA_ESPADA_ATQ_MULTIPLICADOR;

        if (tipo == TipoNecromancer::CAVALEIRO)
            return ESPADA_LANCA_ATQ_MULTIPLICADOR;

        if (tipo == TipoNecromancer::ARQUEIRO)
            return ESPADA_ARCO_ATQ_MULTIPLICADOR;
    }
    return 0;
}


/**
 * @brief Construct a new Guerreiro:: Guerreiro object
 * 
 */
Guerreiro::Guerreiro() {
    this->tipo_necromancer = TipoNecromancer::GUERREIRO;
    this->mp = MP_INICIAL_GUERREIRO;
}

/**
 * @brief Construct a new Cavaleiro:: Cavaleiro object
 * 
 */
Cavaleiro::Cavaleiro() {
    this->tipo_necromancer = TipoNecromancer::CAVALEIRO;
    this->mp = MP_INICIAL_CAVALEIRO;
}

/**
 * @brief Construct a new Arqueiro:: Arqueiro object
 * 
 */
Arqueiro::Arqueiro() {
    this->tipo_necromancer = TipoNecromancer::ARQUEIRO;
    this->mp = MP_INICIAL_ARQUEIRO;
}

/**
 * @brief Construct a new Necromancer:: Necromancer object
 * 
 */
Necromancer::Necromancer() {
    this->tipo = TipoConteudoBloco::UNIDADE;
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
bool Necromancer::handleEvent(SDL_Event * e, int position_x, int position_y) {
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
