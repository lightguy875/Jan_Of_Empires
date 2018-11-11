#ifndef RECUR_HPP
#define RECUR_HPP

#include "Bloco.hpp"

class Recurso  : public ColocavelEmBloco
{ 
    public: 
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