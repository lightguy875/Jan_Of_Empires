#include "../include/Player.hpp"


Player::Player(){
    
    this->metal = 0;
    this->ossos = 0;

    // É com esses dois que o Jogador começa mesmo??
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
}

bool Player::captar_recurso(TipoRecurso rec){
    if(rec == TipoRecurso::METAL){
        this->metal = this->metal + QUANTIDADE_METAL_POR_ITEM;
    }
    if(rec == TipoRecurso::OSSOS){
        this->ossos = this->ossos + QUANTIDADE_OSSOS_POR_ITEM;
    }
    return true;
}

bool Player::criar_pilar(TipoPilar pil){
    if(pil == TipoPilar::ARCO){
        // FALTA TESTAR SE TEM RECURSO E DEBITAR
        if(!this->pilar_arco.vivo){
            this->pilar_arco.revive();
            this->pilar_arco.hp = HP_INICIAL_PILAR_ARCO;
        }else{
            this->pilar_arco.hp += HP_INICIAL_PILAR_ARCO;
        }
    }
    
    if(pil == TipoPilar::LANCA){
        // FALTA TESTAR SE TEM RECURSO E DEBITAR
        if(!this->pilar_lanca.vivo){
            this->pilar_lanca.revive();
            this->pilar_lanca.hp = HP_INICIAL_PILAR_LANCA;
        }else{
            this->pilar_lanca.hp += HP_INICIAL_PILAR_LANCA;
        }
    }

    if(pil == TipoPilar::ESPADA){
        // FALTA TESTAR SE TEM RECURSO E DEBITAR
        if(!this->pilar_espada.vivo){
            this->pilar_espada.revive();
            this->pilar_espada.hp = HP_INICIAL_PILAR_ESPADA;
        }else{
            this->pilar_espada.hp += HP_INICIAL_PILAR_ESPADA;
        }
    }
    return true;  
}

bool Player::criar_necromancer(TipoNecromancer nec){
    if(nec == TipoNecromancer::GUERREIRO){
        // FALTA TESTAR SE TEM RECURSO E DEBITAR
        if(!this->guerreiro.vivo){
            this->guerreiro.revive();
            this->guerreiro.mp = MP_INICIAL_GUERREIRO;
        }else{
            this->guerreiro.mp += MP_INICIAL_GUERREIRO;
        }
    }
    
    if(nec == TipoNecromancer::CAVALEIRO){
        // FALTA TESTAR SE TEM RECURSO E DEBITAR

        if(!this->cavaleiro.vivo){
            this->cavaleiro.revive();
            this->cavaleiro.mp = MP_INICIAL_CAVALEIRO;
        }else{
            this->cavaleiro.mp += MP_INICIAL_CAVALEIRO;
        }
    }

    if(nec == TipoNecromancer::ARQUEIRO){
        // FALTA TESTAR SE TEM RECURSO E DEBITAR
        if(!this->arqueiro.vivo){
            this->arqueiro.revive();
            this->arqueiro.mp = MP_INICIAL_ARQUEIRO;
        }else{
            this->arqueiro.mp += MP_INICIAL_ARQUEIRO;
        }
    }

    return true;  
}
