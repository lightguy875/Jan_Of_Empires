#include "../include/Necromancer.hpp"
/*
    Setando diferentes valores iniciais de mp
    de acordo com o tipo de necromancer
*/
Necromancer::Necromancer(){
    this->tipo = TipoConteudoBloco::UNIDADE;
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

