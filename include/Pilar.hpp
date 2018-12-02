//// "Copyright 2018 Jan_of_Empires"
/**
 * @file Pilar.hpp
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
#ifndef PILAR_HPP
#define PILAR_HPP

#include "Bloco.hpp"
#include "Utils.hpp"
#include "common.hpp"


enum class TipoPilar {
    ESPADA = 7,LANCA, ARCO
};

class Pilar : public ColocavelEmBloco
{
    public:
        unsigned short hp;
        TipoPilar tipo_pilar;
        Pilar();
        bool handleEvent(SDL_Event * e, int position_x, int position_y);
};


class PilarEspada : public Pilar
{
    public:
        PilarEspada();
};


class PilarLanca : public Pilar
{
    public:
        PilarLanca();
};


class PilarArco: public Pilar
{
    public:
        PilarArco();
};
#endif
