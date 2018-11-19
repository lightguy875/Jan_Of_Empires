#ifndef BLOCO_HPP
#define BLOCO_HPP

#include "Utils.hpp"

enum class TipoConteudoBloco{
    UNIDADE=0,PREDIO,RECURSO
};


class ColocavelEmBloco 
{
    public:
        bool vivo;
        unsigned short x, y, time;
        TipoConteudoBloco tipo;
        ColocavelEmBloco();
        bool mata();
        bool revive();
};

class Bloco
{
    public:
        bool vazio;
        ColocavelEmBloco *conteudo;

        Bloco();
        Bloco(ColocavelEmBloco *);
        bool preenche(ColocavelEmBloco *);
        bool limpa();
};
#endif