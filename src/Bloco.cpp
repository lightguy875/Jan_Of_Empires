#include "../include/Bloco.hpp"
#include <iostream>

Bloco::Bloco(){
    this->conteudo = NULL;
    this->vazio = true;
}

Bloco::Bloco(ColocavelEmBloco *conteudo){
    this->conteudo = conteudo;
    this->vazio = false;
}

bool Bloco::preenche(ColocavelEmBloco *c){
    if(!this->vazio) return false;
    this->conteudo = c;
    this->vazio = false;
    return true;
}

bool Bloco::retira(ColocavelEmBloco *c){
    if(this->vazio) return false;
    c = this->conteudo;
    this->conteudo = NULL;
    this->vazio=true;
    return true;
}

bool Bloco::limpa(){
    if(this->vazio) return false;
    this->conteudo = NULL;
    this->vazio=true; 
    return true;
}
