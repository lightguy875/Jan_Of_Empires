//// "Copyright 2018 Jan_of_Empires"
/**
 * @file Recurso.hpp
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
#ifndef RECUR_HPP
#define RECUR_HPP

#include "Bloco.hpp"
#include "Utils.hpp"

enum class TipoRecurso{
    METAL = 10,
    OSSOS
};

class Recurso  : public ColocavelEmBloco
{ 
    public:
        unsigned short qtde;
        TipoRecurso tipo_recurso;
        Recurso();
}; 


   
class Metal : public Recurso
{ 
    public: 
        Metal();  
}; 

   
class Ossos : public Recurso 
{ 
    public: 
        Ossos();
}; 



#endif