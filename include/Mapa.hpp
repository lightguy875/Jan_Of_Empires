#ifndef MAPA_HPP
#define MAPA_HPP
#include <tuple>
#include <map>
#include "Bloco.hpp"

typedef std::pair<unsigned short, unsigned short> Posicao;
typedef std::map< Posicao , Bloco> MapaDeBlocos;

class Mapa{

    private:
        unsigned short tam_x;
        unsigned short tam_y;  

    public:  
        Posicao cursor;
        MapaDeBlocos mapa; 
        Mapa(unsigned short,unsigned short);
        bool posicao_valida(unsigned short,unsigned short);      
        bool vazio(unsigned short,unsigned short);
        bool inserir(ColocavelEmBloco *, unsigned short, unsigned short);
        ColocavelEmBloco* ver(unsigned short, unsigned short);
        ColocavelEmBloco* retirar(unsigned short, unsigned short); 
        
};

#endif