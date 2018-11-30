#include "../include/Necromancer.hpp"
/*
    Setando diferentes valores iniciais de mp
    de acordo com o tipo de necromancer
*/
Necromancer::Necromancer(){
    this->tipo = TipoConteudoBloco::UNIDADE;
}

bool Necromancer::handleEvent(SDL_Event * e,int position_x, int position_y){
    if( e->type == SDL_MOUSEBUTTONDOWN )
    {
        //Get mouse position
        int x, y;
        SDL_GetMouseState( &x, &y );
        //Check if mouse is in Button
        bool inside = false;
        if (y > position_y && y < (position_y + 40))
        {
            if (x > position_x && x < (position_x + 40))
            {
                inside = true;
            }
        }
        if (inside)
        {
            switch( e->type )
            {
                case SDL_MOUSEBUTTONDOWN:
                    return true;
                break;
            }
        }
    }
    return false;
}


Guerreiro::Guerreiro(){
    this->tipo_necromancer = TipoNecromancer::GUERREIRO;
    this->mp = MP_INICIAL_GUERREIRO;
}

Cavaleiro::Cavaleiro(){
    this->tipo_necromancer = TipoNecromancer::CAVALEIRO;
    this->mp = MP_INICIAL_CAVALEIRO;
}

Arqueiro::Arqueiro(){
    this->tipo_necromancer = TipoNecromancer::ARQUEIRO;
    this->mp = MP_INICIAL_ARQUEIRO;
}

unsigned short Necromancer::multiplicador(TipoPilar tipo){
    if(this->tipo_necromancer == TipoNecromancer::ARQUEIRO){
        if(tipo==TipoPilar::ESPADA)
            return ARCO_ESPADA_ATQ_MULTIPLICADOR;

        if(tipo==TipoPilar::LANCA)
            return ARCO_LANCA_ATQ_MULTIPLICADOR;

        if(tipo==TipoPilar::ARCO)
            return ARCO_ARCO_ATQ_MULTIPLICADOR;
    }
    if(this->tipo_necromancer == TipoNecromancer::CAVALEIRO){
        if(tipo==TipoPilar::ESPADA)
            return LANCA_ESPADA_ATQ_MULTIPLICADOR;

        if(tipo==TipoPilar::LANCA)
            return LANCA_LANCA_ATQ_MULTIPLICADOR;

        if(tipo==TipoPilar::ARCO)
            return LANCA_ARCO_ATQ_MULTIPLICADOR;
    }
    if(this->tipo_necromancer == TipoNecromancer::GUERREIRO){
        if(tipo==TipoPilar::ESPADA)
            return ESPADA_ESPADA_ATQ_MULTIPLICADOR;

        if(tipo==TipoPilar::LANCA)
            return ESPADA_LANCA_ATQ_MULTIPLICADOR;

        if(tipo==TipoPilar::ARCO)
            return ESPADA_ARCO_ATQ_MULTIPLICADOR;
    }
    return 0;
}

unsigned short Necromancer::multiplicador(TipoNecromancer tipo){
    if(this->tipo_necromancer == TipoNecromancer::ARQUEIRO){
        if(tipo==TipoNecromancer::GUERREIRO)
            return ARCO_ESPADA_ATQ_MULTIPLICADOR;

        if(tipo==TipoNecromancer::CAVALEIRO)
            return ARCO_LANCA_ATQ_MULTIPLICADOR;

        if(tipo==TipoNecromancer::ARQUEIRO)
            return ARCO_ARCO_ATQ_MULTIPLICADOR;
    }
    if(this->tipo_necromancer == TipoNecromancer::CAVALEIRO){
        if(tipo==TipoNecromancer::GUERREIRO)
            return LANCA_ESPADA_ATQ_MULTIPLICADOR;

        if(tipo==TipoNecromancer::CAVALEIRO)
            return LANCA_LANCA_ATQ_MULTIPLICADOR;

        if(tipo==TipoNecromancer::ARQUEIRO)
            return LANCA_ARCO_ATQ_MULTIPLICADOR;
    }
    if(this->tipo_necromancer == TipoNecromancer::GUERREIRO){
        if(tipo==TipoNecromancer::GUERREIRO)
            return ESPADA_ESPADA_ATQ_MULTIPLICADOR;

        if(tipo==TipoNecromancer::CAVALEIRO)
            return ESPADA_LANCA_ATQ_MULTIPLICADOR;

        if(tipo==TipoNecromancer::ARQUEIRO)
            return ESPADA_ARCO_ATQ_MULTIPLICADOR;
    }
    return 0;
}
