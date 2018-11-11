#include "../include/Pilar.hpp"
/*
    Setando diferentes valores iniciais de mp
    de acordo com o tipo de necromancer
*/
Pilar::Pilar(){
    this->tipo = TipoConteudoBloco::PREDIO;
}

PilarLanca::PilarLanca(){
    this->tipo_pilar = TipoPilar::LANCA;
}

PilarArco::PilarArco(){
    this->tipo_pilar = TipoPilar::ARCO;
}

PilarEspada::PilarEspada(){
    this->tipo_pilar = TipoPilar::ESPADA;
}