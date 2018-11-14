#include "../include/Mapa.hpp"

Mapa::Mapa(unsigned short X, unsigned short Y){
    this->tam_x = X;
    this->tam_y = Y;
    int i,j;
    for(i=0; i<X; i++)
        for(j=0; j<Y; j++)
            this->mapa[std::make_pair(i,j)] = Bloco();
}

bool Mapa::posicao_valida(unsigned short X, unsigned short Y){
    return X < this->tam_x && Y < this->tam_y;
}

bool Mapa::vazio(unsigned short X, unsigned short Y){
    if ( !this->posicao_valida(X,Y) ) return false;

    return this->mapa[std::make_pair(X,Y)].vazio;
}

bool Mapa::inserir(ColocavelEmBloco *item,unsigned short X, unsigned short Y){
    if( !this->vazio(X, Y) ) return false;

    this->mapa[std::make_pair(X,Y)].preenche(item);
    return true;
}

ColocavelEmBloco* Mapa::ver(unsigned short X, unsigned short Y){
    if( this->vazio(X, Y) || !this->posicao_valida(X,Y)) return nullptr;

    ColocavelEmBloco *conteudo = this->mapa[std::make_pair(X,Y)].conteudo;
    //this->mapa[std::make_pair(X,Y)].limpa();

    return conteudo;
}