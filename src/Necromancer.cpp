#include "../include/Necromancer.hpp"

Guerreiro::Guerreiro(){
    this->mp = 30;
}

Cavaleiro::Cavaleiro(){
    this->mp = 50;
}

Arqueiro::Arqueiro(){
    this->mp = 60;
}

int main(){
    Guerreiro g = Guerreiro();
    Cavaleiro c = Cavaleiro();
    Arqueiro a = Arqueiro();

    std::cout << "mp do guerreiro: " << g.mp << std::endl;
    std::cout << "mp do arqueiro: " << a.mp << std::endl;
    std::cout << "mp do cavaleiro: " << c.mp << std::endl;
    return 0;
}