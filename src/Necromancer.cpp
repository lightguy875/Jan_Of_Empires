#include "../include/Necromancer.hpp"
/*
    Setando diferentes valores iniciais de mp
    de acordo com o tipo de necromancer
*/
Necromancer::Necromancer(){
    this->tipo_bloco = UNIDADE;
}

Guerreiro::Guerreiro(){
    this->sub_tipo = GUERREIRO;
    this->mp = 30;
}

Cavaleiro::Cavaleiro(){
    this->sub_tipo = CAVALEIRO;
    this->mp = 50;
}

Arqueiro::Arqueiro(){
    this->sub_tipo = ARQUEIRO;
    this->mp = 60;
}

