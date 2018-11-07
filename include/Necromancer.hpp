#include <iostream>

class Necromancer 
{ 
    public: 
      int mp; 
}; 
   
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
