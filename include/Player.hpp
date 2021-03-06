//// "Copyright 2018 Jan_of_Empires"
/**
 * @file Player.hpp
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
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Necromancer.hpp"
#include "Pilar.hpp"
#include "Recurso.hpp"
#include "Utils.hpp"

class Player{
       
    public:  
        unsigned short time;
        unsigned short metal;
        unsigned short ossos; 
                
        Player();
        Guerreiro guerreiro;
        Cavaleiro cavaleiro;
        Arqueiro arqueiro;
        PilarEspada pilar_espada;
        PilarArco pilar_arco;
        PilarLanca pilar_lanca;

        bool criar_necromancer(TipoNecromancer);
        bool criar_pilar(TipoPilar);
        bool tem_pilar(TipoPilar);
        bool tem_necromancer(TipoNecromancer);
        Pilar* pilar(TipoPilar);
        Necromancer* necromancer(TipoNecromancer);

        bool captar_recurso(TipoRecurso);
        void muda_time();
        bool perdeu_jogo();
        unsigned short pontuacao();

        void print_recursos(const char *);
};

#endif