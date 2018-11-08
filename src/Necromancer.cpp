#include "../include/Necromancer.hpp"
/*
    Setando diferentes valores iniciais de mp
    de acordo com o tipo de necromancer
*/
Guerreiro::Guerreiro(){
    this->mp = 30;
}

Cavaleiro::Cavaleiro(){
    this->mp = 50;
}

Arqueiro::Arqueiro(){
    this->mp = 60;
}



void Cavaleiro::print_name(){
    std::cout<< "CAVALEIRO"<<std::endl;
}

void Guerreiro::print_name(){
    std::cout<< "GUERREIRO"<<std::endl;
}

void Arqueiro::print_name(){
    std::cout<< "ARQUEIRO"<<std::endl;
}
/*

    para rodar o teste:
    $ g++ Necromancer.cpp
    $ ./a.out

*/

int main(){
    Guerreiro g = Guerreiro();
    g.print_name();
    std::cout << "mp do guerreiro: " << g.mp << std::endl;
    

    Arqueiro a = Arqueiro();
    a.print_name();
    std::cout << "mp do arqueiro: " << a.mp << std::endl;
    
    Cavaleiro c = Cavaleiro();
    c.print_name();
    std::cout << "mp do cavaleiro: " << c.mp << std::endl;

    return 0;
}