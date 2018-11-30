#ifndef NECRO_HPP
#define NECRO_HPP

#ifndef SDL_INCLUDES
#define SDL_INCLUDES
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#endif


#include "Bloco.hpp"
#include "Pilar.hpp"
#include "Utils.hpp"
/*
    Classe Necromancer, que possui as coisas comuns entre todos os Necromancers.
    Funções que funcionam igualmente, dentre outros métodos e atributos devem ser implementados
    aqui.
*/

enum class TipoNecromancer{
    GUERREIRO = 4, CAVALEIRO, ARQUEIRO
};

class Necromancer  : public ColocavelEmBloco
{
    public:
        unsigned short mp;
        TipoNecromancer tipo_necromancer;
        Necromancer();
        unsigned short multiplicador(TipoPilar tipo);
        unsigned short multiplicador(TipoNecromancer tipo);
        void handleEvent(SDL_Event * e, int x, int y);

};


/*
    Headers das classes que herdam de Necromancer
*/

class Guerreiro : public Necromancer
{
    public:
        Guerreiro();
};


class Cavaleiro : public Necromancer
{
    public:
        Cavaleiro();
};


class Arqueiro : public Necromancer
{
    public:
        Arqueiro();
};



#endif
