//// "Copyright 2018 Jan_of_Empires"
/**
 * @file Player.cpp
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
#include "../include/Player.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include "../include/common.hpp"

/**
 * @brief Construct a new Player:: Player object
 * 
 */
Player::Player() {
    this->metal = 0;
    this->ossos = 0;
    this->time = 0;

    this->guerreiro = Guerreiro();
    this->pilar_espada = PilarEspada();

    this->arqueiro = Arqueiro();
    this->arqueiro.mata();

    this->cavaleiro = Cavaleiro();
    this->cavaleiro.mata();

    this->pilar_arco = PilarArco();
    this->pilar_arco.mata();

    this->pilar_lanca = PilarLanca();
    this->pilar_lanca.mata();

    this->guerreiro.time = 0;
    this->arqueiro.time = 0;
    this->cavaleiro.time = 0;
    this->pilar_espada.time = 0;
    this->pilar_arco.time = 0;
    this->pilar_lanca.time = 0;
}

/**
 * @brief 
 * 
 */
void Player::muda_time() {
    if (this->time == 0)
        this->time = 1;
    else
        this->time = 0;

    this->guerreiro.time = this->time;
    this->arqueiro.time = this->time;
    this->cavaleiro.time = this->time;
    this->pilar_espada.time = this->time;
    this->pilar_arco.time = this->time;
    this->pilar_lanca.time = this->time;
}

/**
 * @brief 
 * 
 * @param rec 
 * @return true 
 * @return false 
 */
bool Player::captar_recurso(TipoRecurso rec) {
    if (rec == TipoRecurso::METAL) {
        this->metal = this->metal + QUANTIDADE_METAL_POR_ITEM;
    }
    if (rec == TipoRecurso::OSSOS) {
        this->ossos = this->ossos + QUANTIDADE_OSSOS_POR_ITEM;
    }
    return true;
}

/**
 * @brief 
 * 
 * @param pil 
 * @return Pilar* 
 */
Pilar* Player::pilar(TipoPilar pil) {
    if (pil == TipoPilar::ARCO)
        return &this->pilar_arco;

    if (pil == TipoPilar::LANCA)
        return &this->pilar_lanca;

    if (pil == TipoPilar::ESPADA)
        return &this->pilar_espada;

    return nullptr;
}

/**
 * @brief 
 * 
 * @param nec 
 * @return Necromancer* 
 */
Necromancer* Player::necromancer(TipoNecromancer nec) {
    if (nec == TipoNecromancer::GUERREIRO)
        return &this->guerreiro;

    if (nec == TipoNecromancer::ARQUEIRO)
        return &this->arqueiro;

    if (nec == TipoNecromancer::CAVALEIRO)
        return &this->cavaleiro;

    return nullptr;
}

/**
 * @brief 
 * 
 * @param pil 
 * @return true 
 * @return false 
 */
bool Player::tem_pilar(TipoPilar pil) {
    return this->pilar(pil)->vivo;
}

/**
 * @brief 
 * 
 * @param nec 
 * @return true 
 * @return false 
 */
bool Player::tem_necromancer(TipoNecromancer nec) {
    return this->necromancer(nec)->vivo;
}

/**
 * @brief 
 * 
 * @param pil 
 * @return true 
 * @return false 
 */
bool Player::criar_pilar(TipoPilar pil) {
    if (pil == TipoPilar::ARCO) {
        if (this->metal < METAL_CRIAR_PILAR_ARCO)
            return false;

        this->metal -= METAL_CRIAR_PILAR_ARCO;
        if (!this->pilar_arco.vivo) {
            this->pilar_arco.revive();
            this->pilar_arco.hp = HP_INICIAL_PILAR_ARCO;
        } else {
            this->pilar_arco.hp += HP_INICIAL_PILAR_ARCO;
        }
    }

    if (pil == TipoPilar::LANCA) {
        if (this->metal < METAL_CRIAR_PILAR_LANCA)
            return false;

        this->metal -= METAL_CRIAR_PILAR_LANCA;
        if (!this->pilar_lanca.vivo) {
            this->pilar_lanca.revive();
            this->pilar_lanca.hp = HP_INICIAL_PILAR_LANCA;
        } else {
            this->pilar_lanca.hp += HP_INICIAL_PILAR_LANCA;
        }
    }

    if (pil == TipoPilar::ESPADA) {
        if (this->metal < METAL_CRIAR_PILAR_ESPADA)
            return false;

        this->metal -= METAL_CRIAR_PILAR_ESPADA;
        if (!this->pilar_espada.vivo) {
            this->pilar_espada.revive();
            this->pilar_espada.hp = HP_INICIAL_PILAR_ESPADA;
        } else {
            this->pilar_espada.hp += HP_INICIAL_PILAR_ESPADA;
        }
    }
    return true;
}

/**
 * @brief 
 * 
 * @param nec 
 * @return true 
 * @return false 
 */
bool Player::criar_necromancer(TipoNecromancer nec) {
    if (nec == TipoNecromancer::GUERREIRO) {
        if (!this->pilar_espada.vivo)
            return false;
        if (this->ossos < OSSOS_CRIAR_GUERREIRO)
            return false;

        this->ossos -= OSSOS_CRIAR_GUERREIRO;
        if (!this->guerreiro.vivo) {
            this->guerreiro.revive();
            this->guerreiro.mp = MP_INICIAL_GUERREIRO;
        } else {
            this->guerreiro.mp += MP_INICIAL_GUERREIRO;
        }
    }

    if (nec == TipoNecromancer::CAVALEIRO) {
        if (!this->pilar_lanca.vivo)
            return false;
        if (this->ossos < OSSOS_CRIAR_CAVALEIRO)
            return false;

        this->ossos -= OSSOS_CRIAR_CAVALEIRO;

        if (!this->cavaleiro.vivo) {
            this->cavaleiro.revive();
            this->cavaleiro.mp = MP_INICIAL_CAVALEIRO;
        } else {
            this->cavaleiro.mp += MP_INICIAL_CAVALEIRO;
        }
    }

    if (nec == TipoNecromancer::ARQUEIRO) {
        if (!this->pilar_arco.vivo)
            return false;
        if (this->ossos < OSSOS_CRIAR_ARQUEIRO)
            return false;

        this->ossos -= OSSOS_CRIAR_ARQUEIRO;
        if (!this->arqueiro.vivo) {
            this->arqueiro.revive();
            this->arqueiro.mp = MP_INICIAL_ARQUEIRO;
        } else {
            this->arqueiro.mp += MP_INICIAL_ARQUEIRO;
        }
    }

    return true;
}

/**
 * @brief 
 * 
 * @param nome 
 */
void Player::print_recursos(const char* nome) {
    using namespace std;

    #ifdef PROD
    std::ostringstream metal_s, bones_s;

    metal_s << "METAL: " << this->metal;
    std::string m = metal_s.str();

    bones_s << "BONES: " << this->ossos;
    std::string o = bones_s.str();

    textMetal .loadFromRenderedText(m);
    textMetal .render(444, 568);
    textBones.loadFromRenderedText(o);
    textBones.render(654, 568);
    #else
    cout << nome << " tem: ";
    cout << this->metal << " de metal, ";
    cout << this->ossos << " de ossos" << endl;
    #endif
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Player::perdeu_jogo() {
    return !(this->guerreiro.vivo || this->pilar_espada.vivo ||
    this->arqueiro.vivo || this->pilar_arco.vivo ||
    this->cavaleiro.vivo || this->pilar_lanca.vivo);
}

/**
 * @brief 
 * 
 * @return unsigned short 
 */
unsigned short Player::pontuacao() {
    unsigned short total = 0;

    if (this->pilar_espada.vivo)
        total+=this->pilar_espada.hp;
    if (this->pilar_arco.vivo)
        total+=this->pilar_arco.hp;
    if (this->pilar_lanca.vivo)
        total+=this->pilar_lanca.hp;
    if (this->guerreiro.vivo)
        total+=this->guerreiro.mp;
    if (this->arqueiro.vivo)
        total+=this->arqueiro.mp;
    if (this->cavaleiro.vivo)
        total+=this->cavaleiro.mp;

    return total;
}
