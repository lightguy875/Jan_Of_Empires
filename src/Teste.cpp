#include "../include/Necromancer.hpp"
#include "../include/Recurso.hpp"
#include "../include/Pilar.hpp"
#include "../include/Bloco.hpp"
#include <iostream>

void checa_bloco(Bloco *b){
    if(b->vazio){
        std::cout << "bloco vazio!" << std::endl;
    }
    else{
        if(b->conteudo->tipo == UNIDADE)
            std::cout << "É uma unidade ";

            if(b->conteudo->sub_tipo == GUERREIRO)
                 std::cout << "do tipo Guerreiro" << std::endl;
            if(b->conteudo->sub_tipo == CAVALEIRO)
                 std::cout << "do tipo Cavaleiro" << std::endl; 
            if(b->conteudo->sub_tipo == ARQUEIRO )
                 std::cout << "do tipo Arqueiro" << std::endl;

        if(b->conteudo->tipo == RECURSO)
            std::cout << "É um recurso ";

            if(b->conteudo->sub_tipo == OSSOS)
                 std::cout << "do tipo Ossos" << std::endl;
            if(b->conteudo->sub_tipo == METAL)
                 std::cout << "do tipo Metal" << std::endl; 

        if(b->conteudo->tipo == PREDIO)
            std::cout << "É um prédio ";

            if(b->conteudo->sub_tipo == ESPADA)
                 std::cout << "do tipo Pilar Espada" << std::endl;
            if(b->conteudo->sub_tipo == LANCA)
                 std::cout << "do tipo Pilar Lanca" << std::endl; 
            if(b->conteudo->sub_tipo == ARCO)
                 std::cout << "do tipo Pilar Arco" << std::endl;
    }
}

int main(){
    Necromancer guerr = Guerreiro();
    Recurso metal = Metal();
    Pilar pilar = PilarArco();

    Bloco bloco = Bloco();
    checa_bloco(&bloco); //vazio

    bloco.preenche(&guerr);
    checa_bloco(&bloco);  //com guerreiro

    bloco.limpa();
    bloco.preenche(&metal);
    checa_bloco(&bloco); // com metal

    bloco.limpa();
    bloco.preenche(&guerr);
    checa_bloco(&bloco); //com guerreiro de novo

    bloco.limpa();
    bloco.preenche(&pilar);
    checa_bloco(&bloco); //com pilar arco

    return 0;
}