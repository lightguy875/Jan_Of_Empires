//// "Copyright 2018 Jan_of_Empires"
#include "../include/Bloco.hpp"
#include <iostream>

Bloco::Bloco() {
    this->conteudo = NULL;
    this->vazio = true;
}

Bloco::Bloco(ColocavelEmBloco *conteudo) {
    this->conteudo = conteudo;
    this->vazio = false;
}

bool Bloco::preenche(ColocavelEmBloco *c) {
    if (!this->vazio) return false;
    this->conteudo = c;
    this->vazio = false;
    return true;
}

bool Bloco::limpa() {
    if (this->vazio) return false;
    this->conteudo = nullptr;
    this->vazio = true;
    return true;
}


ColocavelEmBloco::ColocavelEmBloco() {
    this->vivo = true;
}

void ColocavelEmBloco::setAtivo(bool a) {
    ativo = a;
}

bool ColocavelEmBloco::mata() {
    if (this->vivo) {
        this->vivo = false;
        this->x = -1;
        this->y = -1;
        return true;
    }
    return false;
}

bool ColocavelEmBloco::revive() {
    if (this->vivo)
        return false;

    this->vivo = true;
    return true;
}
