#include <iostream>

/*
    Classe Necromancer, que possui as coisas comuns entre todos os Necromancers.
    Funções que funcionam igualmente, dentre outros métodos e atributos devem ser implementados
    aqui.
*/
class Necromancer 
{ 
    public: 
        int mp; 
        
        /*  
            C++ obriga que métodos virtuais tenham implementação, por isso as chaves {}
            mas eles serão futuramente implementados de formas diferentes nas classes
            que herdam de Necromancer (no .cpp) 
        */
        virtual void print_name(){}
}; 


/*
    Headers das classes que herdam de Necromancer
*/
   
class Guerreiro : public Necromancer 
{ 
    public:
        Guerreiro();  
        void print_name();
}; 

   
class Cavaleiro : public Necromancer 
{ 
    public: 
        Cavaleiro();
        void print_name();   
}; 

   
class Arqueiro : public Necromancer 
{ 
    public: 
        Arqueiro();
        void print_name();
}; 
