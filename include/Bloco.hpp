//// "Copyright 2018 Jan_of_Empires"
/**
 * @file Bloco.hpp
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
#ifndef INCLUDE_BLOCO_HPP_
#define INCLUDE_BLOCO_HPP_

#include "Utils.hpp"

enum class TipoConteudoBloco {
    UNIDADE = 0, PREDIO, RECURSO
};


class ColocavelEmBloco {
    public:
        bool vivo;
        unsigned short x, y, time;
        TipoConteudoBloco tipo;
        ColocavelEmBloco();
        bool mata();
        bool revive();
        bool ativo;
        void setAtivo(bool a);
};

class Bloco {
    public:
        bool vazio;
        ColocavelEmBloco *conteudo;

        Bloco();
        Bloco(ColocavelEmBloco *);
        bool preenche(ColocavelEmBloco *);
        bool limpa();
};
#endif  // INCLUDE_BLOCO_HPP_ 
