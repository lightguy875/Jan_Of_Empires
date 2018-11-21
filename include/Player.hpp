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
};

#endif