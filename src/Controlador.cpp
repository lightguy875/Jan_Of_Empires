#include "../include/Controlador.hpp"
#include <iostream>

Controlador::Controlador() : mapa(MAPA_LARGURA, MAPA_ALTURA){

}
void Controlador::preenche_recursos_iniciais(){
    unsigned short i;
    
    for(i = 0; i< METAL_MAPA; i++){
        Recurso *rec = new Metal();
        while(!this->mapa.inserir(rec,rand()%MAPA_LARGURA, rand()%MAPA_ALTURA));
        this->recursos.push_back(*rec);
    }
    
    for(i = 0; i< OSSOS_MAPA; i++){
        Recurso *rec = new Ossos();
        while(!this->mapa.inserir(rec,rand()%MAPA_LARGURA, rand()%MAPA_ALTURA));
        this->recursos.push_back(*rec);
    }   
}

bool Controlador::novo_jogo(bool recursos_aleatorios){

    this->mapa.inserir(&jogador.guerreiro, X_NECROMANCER_PLAYER, Y_NECROMANCER_PLAYER);
    this->mapa.inserir(&jogador.pilar_espada, X_PILAR_PLAYER, Y_PILAR_PLAYER);
    this->mapa.inserir(&computador.guerreiro, X_NECROMANCER_COMPUTADOR, Y_NECROMANCER_COMPUTADOR);
    this->mapa.inserir(&computador.pilar_espada, X_PILAR_COMPUTADOR, Y_PILAR_COMPUTADOR);    

    if(recursos_aleatorios)
        this->preenche_recursos_iniciais();
    
    this->computador.muda_time();
    return true;
}


bool Controlador::criar_pilar(Player *jog,TipoPilar pil, unsigned short x, unsigned short y){
    if(jog->pilar(pil)->vivo) return false;
    if(!this->mapa.vazio(x,y)) return false;
    if(!jog->criar_pilar(pil)) return false;

    this->mapa.inserir(jog->pilar(pil), x, y);

    return true;
}

bool Controlador::criar_necromancer(Player *jog, TipoNecromancer nec, unsigned short x, unsigned short y){
    if(jog->necromancer(nec)->vivo) return false;
    if(!this->mapa.vazio(x,y)) return false;
    if(!jog->criar_necromancer(nec)) return false;
    
    this->mapa.inserir(jog->necromancer(nec), x, y);
    
    return true;
}

bool Controlador::fortalecer_pilar(Player *jog,TipoPilar pil){
    if(!jog->pilar(pil)->vivo) return false;

    return jog->criar_pilar(pil);
}

bool Controlador::fortalecer_necromancer(Player *jog,TipoNecromancer nec){
    if(!jog->necromancer(nec)->vivo) return false;

    return jog->criar_necromancer(nec);
}






void Controlador::print_recursos(){
    
    for (auto v : this->recursos){
        if(v.tipo_recurso == TipoRecurso::METAL)
            std::cout << "Metal";
        else if(v.tipo_recurso == TipoRecurso::OSSOS)
            std::cout << "Ossos";

        std::cout << " X:" << v.x << " Y:" << v.y << std::endl;
    }
}

void Controlador::print_mapa(){
    int i, j;

    std::cout << "  ";
    for(j=0; j<MAPA_ALTURA; j++){
        std::cout <<" "<< j;
        if(j<10)std::cout <<" ";
    }
    std::cout << std::endl;


    for(i=0; i<MAPA_LARGURA; i++){
        std::cout << i << " ";
        for(j=0; j<MAPA_ALTURA; j++){
            if(this->mapa.vazio(i,j)) std::cout << "   ";
            else{
                if(mapa.ver(i,j)->tipo == TipoConteudoBloco::RECURSO){
                    if(((Recurso *)mapa.ver(i,j))->tipo_recurso == TipoRecurso::METAL)
                        std::cout << " M ";
                    else if(((Recurso *)mapa.ver(i,j))->tipo_recurso == TipoRecurso::OSSOS)
                        std::cout << " O ";
                }
                if(mapa.ver(i,j)->tipo == TipoConteudoBloco::UNIDADE){
                    if(((Necromancer *)mapa.ver(i,j))->tipo_necromancer == TipoNecromancer::GUERREIRO)
                        std::cout << "NG" << mapa.ver(i,j)->time;
                    else if(((Necromancer *)mapa.ver(i,j))->tipo_necromancer == TipoNecromancer::ARQUEIRO)
                        std::cout << "NA" << mapa.ver(i,j)->time;
                    else if(((Necromancer *)mapa.ver(i,j))->tipo_necromancer == TipoNecromancer::CAVALEIRO)
                        std::cout << "NC" << mapa.ver(i,j)->time;
                }
                if(mapa.ver(i,j)->tipo == TipoConteudoBloco::PREDIO){
                    if(((Pilar *)mapa.ver(i,j))->tipo_pilar == TipoPilar::ESPADA)
                        std::cout << "PE" << mapa.ver(i,j)->time;
                    else if(((Pilar *)mapa.ver(i,j))->tipo_pilar == TipoPilar::LANCA)
                        std::cout << "PL" << mapa.ver(i,j)->time;
                    else if(((Pilar *)mapa.ver(i,j))->tipo_pilar == TipoPilar::ARCO)
                        std::cout << "PA" << mapa.ver(i,j)->time;
                }
            }
        }
        std::cout << std::endl;
    }
}
















// TO DO
// bool Controlador::carregar_jogo(){
//     return true;
// }


// bool Controlador::salvar_jogo(){    
//     return true;
// }
