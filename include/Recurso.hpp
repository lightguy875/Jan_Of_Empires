#ifndef RECUR_HPP
#define RECUR_HPP

#include "Bloco.hpp"

enum class TipoRecurso{
    METAL = 10,
    OSSOS
};

class Recurso  : public ColocavelEmBloco
{ 
    public:
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