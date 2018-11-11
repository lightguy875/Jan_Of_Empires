#ifndef PILAR_HPP
#define PILAR_HPP

#include "Bloco.hpp"

class Pilar : public ColocavelEmBloco
{ 
    public: 
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