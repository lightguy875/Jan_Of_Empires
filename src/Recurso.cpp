#include "../include/Recurso.hpp"
 

Recurso::Recurso(){
    this->tipo = TipoConteudoBloco::RECURSO;
}

Ossos::Ossos(){
    this->qtde = QUANTIDADE_OSSOS_POR_ITEM;
    this->tipo_recurso = TipoRecurso::OSSOS;
}

Metal::Metal(){
    this->qtde = QUANTIDADE_METAL_POR_ITEM;
    this->tipo_recurso = TipoRecurso::METAL;
}

