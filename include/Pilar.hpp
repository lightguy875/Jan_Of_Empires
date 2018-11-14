#ifndef PILAR_HPP
#define PILAR_HPP

#include "Bloco.hpp"

enum class TipoPilar {
    ESPADA = 7,LANCA, ARCO
};

class Pilar : public ColocavelEmBloco
{ 
    public:
        TipoPilar tipo_pilar;
        Pilar();
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