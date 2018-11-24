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
        bool computador_joga;
        unsigned short vez;


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
        void muda_vez();
        void verifica_combate(unsigned short, unsigned short);
        void realiza_combate(unsigned short , unsigned short ,unsigned short , unsigned short);
        bool gerou_combate(unsigned short, unsigned short, unsigned short);

        //temporarios
        void print_recursos();
        void print_mapa();
};


#endif