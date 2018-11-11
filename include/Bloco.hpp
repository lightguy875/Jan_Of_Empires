#ifndef BLOCO_HPP
#define BLOCO_HPP

#include "Utils.hpp"

class ColocavelEmBloco 
{
    public:
        int tipo;
        int sub_tipo;
};

class Bloco
{
    public:
        bool vazio;
        ColocavelEmBloco *conteudo;

        Bloco();
        Bloco(ColocavelEmBloco *);
        bool preenche(ColocavelEmBloco *);
        bool retira(ColocavelEmBloco *);
        bool limpa();
};
#endif