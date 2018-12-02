//// "Copyright 2018 Jan_of_Empires"
/**
 * @file Necromancer.hpp
 * @author Alex Siqueira (siqueiralex@github.com)
 * @author Alexander André (Alexander-1995@github.com)
 * @author Arthur Veiga (arthurveiga@github.com)
 * @author Matheus Veleci (matheusvsantos@github.com)
 * @author Luis Luz (lightguy875@github.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-01
 * 
 * @copyright Copyright (c) 2018
 * 
 */
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
        bool handleEvent(SDL_Event * e, int x, int y);

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
