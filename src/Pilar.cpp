//// "Copyright 2018 Jan_of_Empires"
#include "../include/Pilar.hpp"
/*
    Setando diferentes valores iniciais de mp
    de acordo com o tipo de necromancer
*/
Pilar::Pilar() {
    this->tipo = TipoConteudoBloco::PREDIO;
}

#ifdef PROD
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

PilarLanca::PilarLanca() {
    this->tipo_pilar = TipoPilar::LANCA;
    this->hp = HP_INICIAL_PILAR_LANCA;
}

PilarArco::PilarArco() {
    this->tipo_pilar = TipoPilar::ARCO;
    this->hp = HP_INICIAL_PILAR_ARCO;
}

PilarEspada::PilarEspada() {
    this->tipo_pilar = TipoPilar::ESPADA;
    this->hp = HP_INICIAL_PILAR_ESPADA;
}
