//// "Copyright 2018 Jan_of_Empires"
/**
 * @file Controlador.hpp
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
#ifndef CTRL_HPP
#define CTRL_HPP
#include <string>
#include <list>
#include <cmath>
#include "Recurso.hpp"
#include "Mapa.hpp"
#include "Player.hpp"
#include "Utils.hpp"

class Controlador {

    private:
        void preenche_recursos_iniciais();

    public:
        Mapa mapa;
        Player jogador;
        Player computador;
        Posicao cursor;
        std::list<Recurso> recursos;
        bool jogo_terminou;
        int ganhou;
        bool computador_joga;
        unsigned short vez;
        int vezes;


        Controlador();
        bool novo_jogo(bool,bool);
        bool salvar_jogo(std::string path);
        bool carregar_jogo(std::string path);


        bool criar_pilar(Player*, TipoPilar, unsigned short, unsigned short);
        bool fortalecer_pilar(Player*, TipoPilar);

        bool criar_necromancer(Player*, TipoNecromancer, unsigned short, unsigned short);
        bool fortalecer_necromancer(Player*, TipoNecromancer);

        bool matar(unsigned short, unsigned short);
        bool pode_movimentar(Player*, unsigned short,unsigned short,unsigned short,unsigned short);
        bool movimentar(Player*, unsigned short,unsigned short,unsigned short,unsigned short);
        void processa_jogada();
        bool alguem_ganhou();
        void muda_vez();
        void verifica_combate(unsigned short, unsigned short);
        void realiza_combate(unsigned short , unsigned short ,unsigned short , unsigned short);
        bool gerou_combate(unsigned short, unsigned short, unsigned short);
        void jogada_pc();
        void pc_movimenta_necromancer(TipoNecromancer tip);
        //temporarios
        void print_recursos();
        void print_mapa();
};


#endif
