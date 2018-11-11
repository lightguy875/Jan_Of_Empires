#include "../include/Pilar.hpp"
/*
    Setando diferentes valores iniciais de mp
    de acordo com o tipo de necromancer
*/
Pilar::Pilar(){
    this->tipo = PREDIO;
}

PilarLanca::PilarLanca(){
    this->sub_tipo = LANCA;
}

PilarArco::PilarArco(){
    this->sub_tipo = ARCO;
}

PilarEspada::PilarEspada(){
    this->sub_tipo = ESPADA;
}