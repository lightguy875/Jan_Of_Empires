#ifndef NECRO_HPP
#define NECRO_HPP

#include "Bloco.hpp"
/*
    Classe Necromancer, que possui as coisas comuns entre todos os Necromancers.
    Funções que funcionam igualmente, dentre outros métodos e atributos devem ser implementados
    aqui.
*/
class Necromancer  : public ColocavelEmBloco
{ 
    public: 
        int mp; 
        Necromancer();
}; 


/*
    Headers das classes que herdam de Necromancer
*/
   
class Guerreiro : public Necromancer 
{ 
    public:
        Guerreiro();  
}; 

   
class Cavaleiro : public Necromancer 
{ 
    public: 
        Cavaleiro();
}; 

   
class Arqueiro : public Necromancer 
{ 
    public: 
        Arqueiro();
}; 



#endif