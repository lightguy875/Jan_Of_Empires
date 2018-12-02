//// "Copyright 2018 Jan_of_Empires"
/**
 * @file Controlador.cpp
 * @author Alex Siqueira (siqueiralex@github.com)
 * @author Alexander André (Alexander-1995@github.com)
 * @author Arthur Veiga (arthurveiga@github.com)
 * @author Matheus Veleci (matheusvsantos@github.com)
 * @author Luis Luz (lightguy875@github.com)
 * @brief
 * @version 0.1
 * @date 2018-12-01
 *
 * @copyright Copyright (c) 2018
 *
 */
#include <string>
#include <sstream>
#include <cmath>
#include <iostream>
#include "../include/Controlador.hpp"
#include "../include/common.hpp"

/**
 * @brief Construct a new Controlador:: Controlador object
 *
 */
Controlador::Controlador() : mapa(MAPA_LARGURA, MAPA_ALTURA) {
    this->jogo_terminou = false;
    this->vez = 0;
    this->vezes = 0;
}
/**
 * @brief preenche o mapa com recursos aleatoriamente
 *
 * Assertivas de Entrada
 * nao_preenchido(mapa) == True
 *
 * Assertivas de Saida
 * preenchido(mapa) == True
 */
void Controlador::preenche_recursos_iniciais() {
    unsigned short i;

    for (i = 0; i< METAL_MAPA; i++) {
        Recurso *rec = new Metal();
        while (!this->mapa.inserir(rec, (rand()%MAPA_LARGURA), (rand()%MAPA_ALTURA)));
        this->recursos.push_back(*rec);
    }

    for (i = 0; i< OSSOS_MAPA; i++) {
        Recurso *rec = new Ossos();
        while (!this->mapa.inserir(rec, rand()%MAPA_LARGURA, rand()%MAPA_ALTURA));
        this->recursos.push_back(*rec);
    }
}

/**
 * @brief Função que inicializa o mapa e os jogadores para iniciar uma partida
 *
 * @param recursos_aleatorios = define se devem ou não ser colocados recursos no mapa aleatoriamente
 * @param computador_joga = define se deve configurar o jogo para que o computador jogue ou não
 * @return true se foi possível iniciar o jogo
 * @return false se não foi possivel iniciar o jogo
 * 
 * Assertivas de Entrada:
 *  jogo_nao_iniciado() == True
 * 
 * Assertivas de Saída:
 * Consistente(mapa)==True
 * pronto_pra_jogar(controlador) == True
 */
bool Controlador::novo_jogo(bool recursos_aleatorios, bool computador_joga) {
    this->mapa.inserir(&jogador.guerreiro, X_NECROMANCER_PLAYER, Y_NECROMANCER_PLAYER);
    this->mapa.inserir(&jogador.pilar_espada, X_PILAR_PLAYER, Y_PILAR_PLAYER);
    this->mapa.inserir(&computador.guerreiro, X_NECROMANCER_COMPUTADOR, Y_NECROMANCER_COMPUTADOR);
    this->mapa.inserir(&computador.pilar_espada, X_PILAR_COMPUTADOR, Y_PILAR_COMPUTADOR);

    jogador.guerreiro.setAtivo(true);
    computador.guerreiro.setAtivo(true);

    #ifdef PROD
    ativo_x_jog = X_NECROMANCER_PLAYER;
    ativo_y_jog = Y_NECROMANCER_PLAYER;
    ativo_x_cpu = X_NECROMANCER_COMPUTADOR;
    ativo_y_cpu = Y_NECROMANCER_COMPUTADOR;
    #endif

    if (recursos_aleatorios)
        this->preenche_recursos_iniciais();

    this->computador_joga = computador_joga;

    this->computador.muda_time();
    return true;
}

/**
 * @brief Função em que um jogador cria um pilar
 *
 * @param jog = Jogador que faz a jogada
 * @param pil = Tipo de pilar a ser criado
 * @param x, y = Coordenadas em que o pilar será colocado
 * @return true se foi possível criar o pilar
 * @return false se não foi possível criar o pilar
 * 
 * Assertivas de Entrada:
 *  Jogador_Válido(jog) == True
 *  Tipo_Pilar_Válido(pil) == True
 *
 * Assertivas de Saída:
 * mapa == mapa || adiciona_pilar(mapa)
 */
bool Controlador::criar_pilar(Player *jog, TipoPilar pil, unsigned short x, unsigned short y) {
    if (jog->pilar(pil)->vivo) return false;
    if (!this->mapa.vazio(x, y)) return false;
    if (!jog->criar_pilar(pil)) return false;
    this->mapa.inserir(jog->pilar(pil), x, y);

    return true;
}

/**
 * @brief Funcao em que um jogador cria um necromancer
 *
 * @param jog = Jogador que faz a jogada
 * @param nec = Tipo de necromancer a ser criado
 * @param x, y = Coordenadas em que o necromancer será colocado
 * @return true se foi posseivel criar
 * @return false se não foi possível criar
 * 
 * Assertivas de Entrada:
 *  Jogador_Válido(jog) == True
 *  Tipo_Necromancer_Válido(nec) == True
 *
 * Assertivas de Saída:
 * mapa == mapa || adiciona_necromancer(mapa)
 *
 */
bool Controlador::criar_necromancer(Player *jog, TipoNecromancer nec, unsigned short x, unsigned short y) {
    if (jog->necromancer(nec)->vivo) return false;
    if (!this->mapa.vazio(x, y)) return false;
    if (!jog->criar_necromancer(nec)) return false;

    this->mapa.inserir(jog->necromancer(nec), x, y);

    return true;
}

/**
 * @brief Funcão em que um jogador fortalece um pilar
 *
 * @param jog = Jogador que faz a jogada
 * @param pil = Tipo de pilar a ser fortalecido
 * @return true se foi possível fortalecer
 * @return false se não foi possível fortalecer
 * 
 * Assertivas de Entrada:
 *  Jogador_Válido(jog) == True
 *  Tipo_Pilar_Válido(pil) == True
 *
 * Assertivas de Saída:
 * mapa == mapa
 *
 */
bool Controlador::fortalecer_pilar(Player *jog, TipoPilar pil) {
    if (!jog->pilar(pil)->vivo) return false;

    return jog->criar_pilar(pil);
}

/**
 * @brief Função em que um jogador fortalecer um necromancer
 *
 * @param jog = Jogador que faz a jogada
 * @param nec = Tipo de necromancer a ser fortalcido
 * @return true se foi posseivel fortalcer
 * @return false se não foi possível fortalecer
 * 
 * Assertivas de Entrada:
 *  Jogador_Válido(jog) == True
 *  Tipo_Necromacner_Válido(nec) == True
 *
 * Assertivas de Saída:
 * mapa == mapa
 *
 */
bool Controlador::fortalecer_necromancer(Player *jog, TipoNecromancer nec) {
    if (!jog->necromancer(nec)->vivo) return false;

    return jog->criar_necromancer(nec);
}

/**
 * @brief Função para matar uma peça (Necromancer ou Pilar)
 *
 * @param X, Y = Coordenadas da peça a ser morta
 * @return true se foi possível matar
 * @return false se não foi possível matar
 *
 * Assertivas de Entrada:
 * inicializado(mapa) == True
 *
 * Assertivas de Saída:
 * mapa == mapa || menos_uma_peça(mapa)
 */
bool Controlador::matar(unsigned short X, unsigned short Y) {
    if (this->mapa.vazio(X, Y))
        return false;
    if (this->mapa.ver(X, Y)->tipo == TipoConteudoBloco::RECURSO)
        return false;
    ColocavelEmBloco * vitima = this->mapa.retirar(X, Y);
    vitima->mata();
    return true;
}

/**
 * @brief função que avalia se um movimento é possível de acordo com as regras do jogo
 *
 * @param jog = Jogador que pretende realizar a jogada
 * @param x_orig, y_orig = Coordenadas de origem do movimento
 * @param x_dest, y_dest = Coordendas de destino do movimento
 * @return true se será possível movimentar
 * @return false se não será possível movimentar
 *
 * Assertivas de Entrada:
 * inicializado(controlador) == True
 * Jogador_Valido(jog) == True
 *
 * Assertivas de Saída:
 * mapa == mapa
 */
bool Controlador::pode_movimentar(Player *jog, unsigned short x_orig, unsigned short y_orig, unsigned short x_dest, unsigned short y_dest) {
    if (!(this->mapa.posicao_valida(x_orig, y_orig) && this->mapa.posicao_valida(x_dest, y_dest)))
        return false;
    if (abs(x_dest - x_orig) > RANGE_MOVIMENTO || abs(y_dest - y_orig) > RANGE_MOVIMENTO)
        return false;
    if (this->mapa.vazio(x_orig, y_orig))
        return false;
    if (this->mapa.ver(x_orig, y_orig)->tipo != TipoConteudoBloco::UNIDADE)
        return false;
    if (this->mapa.ver(x_orig, y_orig)->time != jog->time)
        return false;
    if (this->mapa.vazio(x_dest, y_dest))
        return true;
    if (this->mapa.ver(x_dest, y_dest)->tipo == TipoConteudoBloco::UNIDADE)
        return false;
    if (this->mapa.ver(x_dest, y_dest)->tipo == TipoConteudoBloco::PREDIO)
        return false;

    return true;
}

/**
 * @brief Função em que jogador realiza movimentação de peças
 *
 * @param jog = Jogador que pretende realizar a movimentação
 * @param x_orig, y_orig = Coordenadas de origem do movimento
 * @param x_dest, y_dest = Coordendas de destino do movimento
 * @return true se foi possível movimentar
 * @return false se não foi possível movimentar
 *
 * Assertivas de Entrada:
 * inicializado(controlador) == True
 * Jogador_Valido(jog) == True
 *
 * Assertivas de Saída:
 * mapa == mapa || com_peça_movimentada(mapa)
 */
bool Controlador::movimentar(Player *jog, unsigned short x_orig, unsigned short y_orig, unsigned short x_dest, unsigned short y_dest) {
    if ( !this->pode_movimentar(jog, x_orig, y_orig, x_dest, y_dest) )
        return false;
    ColocavelEmBloco * unidade_movida = this->mapa.retirar(x_orig, y_orig);
    if (!this->mapa.vazio(x_dest, y_dest)) {
        if (this->mapa.ver(x_dest, y_dest)->tipo == TipoConteudoBloco::RECURSO) {
            Recurso * rec = ((Recurso *) mapa.retirar(x_dest, y_dest));
            jog->captar_recurso(rec->tipo_recurso);
            for (std::list<Recurso>::iterator i = this->recursos.begin(); i != this->recursos.end(); ++i)
                if (i->x == x_dest && i->y == y_dest) {
// std::cout << "recurso retirado de  " <<i->x << " " << i->y << std::endl;
                    this->recursos.erase(i);
                    break;
                }
        }
    }
    this->mapa.inserir(unidade_movida, x_dest, y_dest);

    this->processa_jogada();
    return true;
}

/**
 * @brief Função que avalia se uma movimentação gerou combate, ou seja, duas peças inimigas estão vizinhas
 *
 * @param time = time que tem a vez
 * @param x, y = posição pra avaliar se tem uma peça inimiga
 * @return true se tem peça inimiga na posiçåõ passada
 * @return false se não tem peça inimiga na posiçåõ passada
 *
 * Assertivas de Entrada:
 * inicializado(jogo) == True
 * 
 * Assertiva de Saída:
 * mapa == mapa
 */
bool Controlador::gerou_combate(unsigned short time, unsigned short x, unsigned short y) {
    if (!this->mapa.posicao_valida(x, y))
        return false;
    if (this->mapa.vazio(x, y))
        return false;
    if (this->mapa.ver(x, y)->tipo == TipoConteudoBloco::RECURSO)
        return false;

    return this->mapa.ver(x, y)->time != time;
}

/**
 * @brief realiza combate entre peças em duas peças inimigas, tirando vida da peça vítima
 *
 * @param x_atac, y_atac = Coordenada do atancante
 * @param x_vit, y_vit = Coordenadas da vítima
 *
 * Assertivas de Entrada:
 * peças_vizinhas(posicao_atacante,posicao_vitima) == True
 *
 * Assertivas de Saída:
 * mapa == mapa || menos_uma_peça(mapa)
 */
void Controlador::realiza_combate(unsigned short x_atac, unsigned short y_atac, unsigned short x_vit, unsigned short y_vit ) {
    unsigned short dano_golpe;
    std::cout<<  "realizando combate em: "<< x_atac << " " << y_atac << " "<< x_vit << " " << y_vit <<std::endl;
    Necromancer *atacante = (Necromancer *)this->mapa.ver(x_atac, y_atac);

    ColocavelEmBloco *vitima = this->mapa.ver(x_vit, y_vit);
    TipoNecromancer tipo_vitima_nec = ((Necromancer *) vitima)->tipo_necromancer;
    TipoPilar tipo_vitima_pil = ((Pilar *) vitima)->tipo_pilar;
    switch ((int) this->mapa.ver(x_vit, y_vit)->tipo) {
        case (int) TipoConteudoBloco::UNIDADE:
            dano_golpe = DANO_DE_ATQ * atacante->multiplicador(tipo_vitima_nec);
            if (((Necromancer *) vitima)->mp <= dano_golpe) {
                this->matar(x_vit, y_vit);
                ((Necromancer *) vitima)->mp = 0;
            } else {
                ((Necromancer *) vitima)->mp = ((Necromancer *) vitima)->mp - dano_golpe;
            }
            break;
        case (int) TipoConteudoBloco::PREDIO:
            dano_golpe = DANO_DE_ATQ * atacante->multiplicador(tipo_vitima_pil);
            if (((Pilar *) vitima)->hp <= dano_golpe) {
                this->matar(x_vit, y_vit);
            } else {
                ((Pilar *) vitima)->hp = ((Pilar *) vitima)->hp - dano_golpe;
            }
            break;
        default:
            break;
    }
    return;
}

/**
 * @brief Verifica, a partir de uma coordenada, se aquela peça está gerando combate com algum inimigo vizinho
 *
 * @param x, y =  coordenadas da peça atacante
 *
 * Assertivas de Entrada:
 * Tem_peça(x,y) == True
 *
 * Assertiva de Saída:
 * mapa == com_ate_6_combates(mapa)
 */
void Controlador::verifica_combate(unsigned short x, unsigned short y) {
    // std::cout<<  "verificando combate em: "<< x << " " << y << std::endl;
    unsigned short time = this->mapa.ver(x, y)->time;
    // Só é combate se tiver na vez do atacante
    if (time != this->vez)
        return;
    // procura adversarios vizinhos e realiza combate se tiver
    for (int i=x-RANGE_COMBATE; i <= x+RANGE_COMBATE; i++)
        for (int j = y-RANGE_COMBATE; j <= y+RANGE_COMBATE; j++)
            if (this->gerou_combate(time, i, j))
                this->realiza_combate(x, y, i, j);
}

/**
 * @brief Troca o turno, ou seja, que jogador detém a jogada
 *
 * Assertivas de Entrada:
 * inicializado(controlador) == True
 *
 * Assertiva de Saida:
 * vez == 1 ou 0
 */
void Controlador::muda_vez() {
    if (this->vez == 0) {
        this->vez = 1;
        return;
    }

    this->vez = 0;
}

/**
 * @brief Verifica se alguem ganhou, seja por ter perdido todas as pecas ou por terem acabado os recursos (por pontuaçåõ)
 *
 * @return true se alguem ganhou
 * @return false se ninguém ganhou
 *
 * Assertivas de Entrada:
 * inicializado(controlador) == True
 *
 * Assertivas de Saída:
 * pode_ser_alterado(jogo_terminou) == true
 * pode_ser_alterado(ganhou) == True
 */
bool Controlador::alguem_ganhou() {
    if (this->recursos.size() == 0) {
        if (this->jogador.pontuacao() > this->computador.pontuacao()) {
            this->jogo_terminou = true;
            this->ganhou = 0;
            return true;
        }
        if (this->jogador.pontuacao() < this->computador.pontuacao()) {
            this->jogo_terminou = true;
            this->ganhou = 1;
            return true;
        }

        this->jogo_terminou = true;
        this->ganhou = -1;
        return true;
    }

    if (this->jogador.perdeu_jogo()) {
        this->jogo_terminou = true;
        this->ganhou = 1;
        return true;
    }
    if (this->computador.perdeu_jogo()) {
        this->jogo_terminou = true;
        this->ganhou = 0;
        return true;
    }

    return false;
}

/**
 * @brief função que processa as posseiveis consequências de uma movimentação
 *
 * Assertivas de Entrada
 * inicializado(controlador) ==  True
 *
 * Assertivas de Saída:
 * mapa == mapa
 * pode_ser_alterado(jogo_terminou) == true
 * pode_ser_alterado(ganhou) == True
 */
void Controlador::processa_jogada() {
    unsigned short time;

    // Varre todo o mapa procurando unidades vizinhas pra "combater"
    for (int i = 0; i < MAPA_LARGURA; i++) {
        for (int j = 0; j < MAPA_ALTURA; j++) {
            if (!this->mapa.vazio(i, j) && mapa.ver(i, j)->tipo == TipoConteudoBloco::UNIDADE) {
                this->verifica_combate(i, j);
            }
        }
    }
    if (this->alguem_ganhou()) {
        return;
    }


    if (this->vezes++ == 1) {
        this->muda_vez();
        this->vezes = 0;
        
        if (this->computador_joga) {
            this->jogada_pc();
            this->muda_vez();
        }

    }

    if (!jogador.arqueiro.vivo && !jogador.cavaleiro.vivo && !jogador.guerreiro.vivo && jogador.ossos < OSSOS_CRIAR_ARQUEIRO){
        this->vez = 1;
    }else if (!jogador.arqueiro.vivo && !jogador.cavaleiro.vivo && !jogador.guerreiro.vivo && jogador.ossos >= OSSOS_CRIAR_ARQUEIRO){
        int position_x = (rand()%MAPA_LARGURA),position_y=(rand()%MAPA_ALTURA);
        while(!mapa.vazio(position_x,position_y)){
            position_x = (rand()%MAPA_LARGURA);
            position_y = (rand()%MAPA_ALTURA);
        }
        if (jogador.pilar_arco.vivo){
            criar_necromancer(&jogador, TipoNecromancer::ARQUEIRO,position_x,position_y);
            #ifdef PROD
            ativo_x_jog = position_x;
            ativo_y_jog = position_y;
            #endif
        }else if (jogador.pilar_espada.vivo){
            criar_necromancer(&jogador, TipoNecromancer::GUERREIRO,position_x,position_y);
            #ifdef PROD
            ativo_x_jog = position_x;
            ativo_y_jog = position_y;
            #endif
        }else if (jogador.pilar_lanca.vivo){
            criar_necromancer(&jogador, TipoNecromancer::CAVALEIRO,position_x,position_y);
            #ifdef PROD
            ativo_x_jog = position_x;
            ativo_y_jog = position_y;
            #endif
        }
    }

    if (!computador.arqueiro.vivo && !computador.cavaleiro.vivo && !computador.guerreiro.vivo && computador.ossos < OSSOS_CRIAR_ARQUEIRO){
        this->vez = 0;
    }else if (!computador.arqueiro.vivo && !computador.cavaleiro.vivo && !computador.guerreiro.vivo && computador.ossos >= OSSOS_CRIAR_ARQUEIRO){
        int position_x = (rand()%MAPA_LARGURA),position_y=(rand()%MAPA_ALTURA);
        while(!mapa.vazio(position_x,position_y)){
            position_x = (rand()%MAPA_LARGURA);
            position_y = (rand()%MAPA_ALTURA);
        }
        if (computador.pilar_arco.vivo){
            criar_necromancer(&computador, TipoNecromancer::ARQUEIRO,position_x,position_y);
            #ifdef PROD
            ativo_x_cpu = position_x;
            ativo_y_cpu = position_y;
            #endif
        }else if (computador.pilar_espada.vivo){
            criar_necromancer(&computador, TipoNecromancer::GUERREIRO,position_x,position_y);
            #ifdef PROD
            ativo_x_cpu = position_x;
            ativo_y_cpu = position_y;
            #endif
        }else if (computador.pilar_lanca.vivo){
            criar_necromancer(&computador, TipoNecromancer::CAVALEIRO,position_x,position_y);
            #ifdef PROD
            ativo_x_cpu = position_x;
            ativo_y_cpu = position_y;
            #endif
        }
    }
}

/**
 * @brief heuristica de movimentação automática do necromacner
 *
 * @param tip = tipo de Necromancer pra ser movimentado
 *
 * Assertivas de Entrada
 * inicializado(controlador) ==  True
 * vez_computador() == True

 * Assertivas de Saída:
 * mapa == mapa + movimentação_computador()
 */
void Controlador::pc_movimenta_necromancer(TipoNecromancer tip){
    int nec_x = this->computador.necromancer(tip)->x;
    int nec_y = this->computador.necromancer(tip)->y;

    // se tiver recurso pega ele
    for (auto v : this->recursos) {
        if( abs(v.x - nec_x) < 3 && abs(v.y - nec_y) < 3 ){
            this->movimentar(&(this->computador), nec_x, nec_y, v.x, v.y);
            break;
        }
    }
    
    // depois movimenta aleatório
    nec_x = this->computador.necromancer(tip)->x;
    nec_y = this->computador.necromancer(tip)->y;
    int pos_x = this->computador.necromancer(tip)->x + (rand()%5) -2;
    int pos_y = this->computador.necromancer(tip)->y + (rand()%5) -2;

    this->movimentar(&(this->computador), nec_x, nec_y, pos_x, pos_y);

}


/**
 * @brief heuristica de jogada automática do computador
 *
 * Assertivas de Entrada
 * inicializado(controlador) ==  True
 * vez_computador() == True

 * Assertivas de Saída:
 * mapa == mapa + movimentação_computador()
 */
void Controlador::jogada_pc(){
    int position_x = rand()%MAPA_LARGURA; 
    int position_y = rand()%MAPA_ALTURA;

    while(!mapa.vazio(position_x,position_y)){
        position_x = rand()%MAPA_LARGURA;
        position_y = rand()%MAPA_ALTURA;
    }

    // tenta criar todos os necromancers
    this->criar_necromancer(&(this->computador), TipoNecromancer::ARQUEIRO, position_x, position_y);
    this->criar_necromancer(&(this->computador), TipoNecromancer::GUERREIRO, position_x, position_y);
    this->criar_necromancer(&(this->computador), TipoNecromancer::CAVALEIRO, position_x, position_y);

    while(!mapa.vazio(position_x,position_y)){
            position_x = rand()%MAPA_LARGURA;
            position_y = rand()%MAPA_ALTURA;
    }

    // tenta criar todos os pilares
    this->criar_pilar(&(this->computador), TipoPilar::ARCO, position_x, position_y);
    this->criar_pilar(&(this->computador), TipoPilar::ESPADA, position_x, position_y);
    this->criar_pilar(&(this->computador), TipoPilar::LANCA, position_x, position_y);


    if( this->computador.tem_necromancer(TipoNecromancer::ARQUEIRO) ){
        this->pc_movimenta_necromancer(TipoNecromancer::ARQUEIRO);
    }
    else if( this->computador.tem_necromancer(TipoNecromancer::GUERREIRO) ){
        this->pc_movimenta_necromancer(TipoNecromancer::GUERREIRO);
    }
    else if( this->computador.tem_necromancer(TipoNecromancer::CAVALEIRO) ){
        this->pc_movimenta_necromancer(TipoNecromancer::CAVALEIRO);
    }

}


/**
 * @brief
 *
 */
void Controlador::print_recursos() {
    using namespace std;
    #ifdef PROD
    std::ostringstream xp;
    unsigned short x = 0, y = 0;

    if (vez == 0) {
        if (jogador.guerreiro.ativo) {
            x = jogador.guerreiro.mp;
            y = jogador.pilar_espada.hp;
        } else if (jogador.arqueiro.ativo) {
            x = jogador.arqueiro.mp;
            y = jogador.pilar_arco.hp;
        } else if (jogador.cavaleiro.ativo) {
            x = jogador.cavaleiro.mp;
            y = jogador.pilar_lanca.hp;
        }
    } else {
        if (computador.guerreiro.ativo) {
            x = computador.guerreiro.mp;
            y = computador.pilar_espada.hp;
        } else if (computador.arqueiro.ativo) {
            x = computador.arqueiro.mp;
            y = computador.pilar_arco.hp;
        } else if (computador.cavaleiro.ativo) {
            x = computador.cavaleiro.mp;
            y = computador.pilar_lanca.hp;
        }
    }
    if (x == 0 && y == 0) {
        textHP.loadFromRenderedText("Select Neoc.");
        textHP.render(180, 568);
    } else {
        xp << "HP_N: " << x << "        HP_P: " << y;
        std::string xp_s = xp.str();
        textHP.loadFromRenderedText(xp_s);
        textHP.render(180, 568);
    }
    #else
    std::cout<<  "Quantidade de  recursos no mapa: "<< this->recursos.size() << std::endl;
    for (auto v : this->recursos) {
        if (v.tipo_recurso == TipoRecurso::METAL)
            std::cout << "Metal";
        else if (v.tipo_recurso == TipoRecurso::OSSOS)
            std::cout << "Ossos";

        std::cout << " X:" << v.x << " Y:" << v.y << std::endl;
    }
    #endif
}



/**
 * @brief
 *
 */
void Controlador::print_mapa() {
    #ifdef PROD
    int i, j, ossos_c = 0, metal_c = 0;
    for (j = 0; j < MAPA_ALTURA; j++) {
        for (i = 0; i < MAPA_LARGURA; i++) {
            if (!this->mapa.vazio(i, j)) {
                if (mapa.ver(i, j)->tipo == TipoConteudoBloco::RECURSO) {
                    if (((Recurso *)mapa.ver(i, j))->tipo_recurso == TipoRecurso::METAL) {
                        metal[metal_c++].render(i*40, j*40);
                    } else if (((Recurso *)mapa.ver(i, j))->tipo_recurso == TipoRecurso::OSSOS) {
                        bones[ossos_c++].render(i*40, j*40);
                    }
                }
                if (mapa.ver(i, j)->tipo == TipoConteudoBloco::UNIDADE) {
                    if (((Necromancer *)mapa.ver(i, j))->tipo_necromancer == TipoNecromancer::GUERREIRO) {
                        knight[mapa.ver(i, j)->time].render(i*40, j*40);
                    } else if (((Necromancer *)mapa.ver(i, j))->tipo_necromancer == TipoNecromancer::ARQUEIRO) {
                        archer[mapa.ver(i, j)->time].render(i*40, j*40);
                    } else if (((Necromancer *)mapa.ver(i, j))->tipo_necromancer == TipoNecromancer::CAVALEIRO) {
                        solider[mapa.ver(i, j)->time].render(i*40, j*40);
                    }
                }
                if (mapa.ver(i, j)->tipo == TipoConteudoBloco::PREDIO) {
                    if (((Pilar *)mapa.ver(i, j))->tipo_pilar == TipoPilar::ESPADA) {
                         pilar_knight[mapa.ver(i, j)->time].render(i*40, j*40);
                    } else if (((Pilar *)mapa.ver(i, j))->tipo_pilar == TipoPilar::LANCA) {
                        pilar_solider[mapa.ver(i, j)->time].render(i*40, j*40);
                    } else if (((Pilar *)mapa.ver(i, j))->tipo_pilar == TipoPilar::ARCO) {
                        pilar_archer[mapa.ver(i, j)->time].render(i*40, j*40);
                    }
                }
            }
        }
    }
    #else
    int i, j;

       std::cout << "  ";
       for (i=0; i < MAPA_LARGURA; i++) {
           std::cout <<" "<< i;
           if (i < 10) std::cout <<" ";
       }
       std::cout << std::endl;


       for (j = 0; j < MAPA_ALTURA; j++) {
           std::cout << j << " ";
           for (i = 0; i < MAPA_LARGURA; i++) {
               if (this->mapa.vazio(i, j)) std::cout << "   ";
               else {
                   if (mapa.ver(i, j)->tipo == TipoConteudoBloco::RECURSO) {
                       if (((Recurso *)mapa.ver(i, j))->tipo_recurso == TipoRecurso::METAL)
                           std::cout << " M ";
                       else if (((Recurso *)mapa.ver(i, j))->tipo_recurso == TipoRecurso::OSSOS)
                           std::cout << " O ";
                   }
                   if (mapa.ver(i, j)->tipo == TipoConteudoBloco::UNIDADE) {
                       if (((Necromancer *)mapa.ver(i, j))->tipo_necromancer == TipoNecromancer::GUERREIRO)
                           std::cout << "NG" << mapa.ver(i, j)->time;
                       else if (((Necromancer *)mapa.ver(i, j))->tipo_necromancer == TipoNecromancer::ARQUEIRO)
                           std::cout << "NA" << mapa.ver(i, j)->time;
                       else if (((Necromancer *)mapa.ver(i, j))->tipo_necromancer == TipoNecromancer::CAVALEIRO)
                           std::cout << "NC" << mapa.ver(i, j)->time;
                   }
                   if (mapa.ver(i, j)->tipo == TipoConteudoBloco::PREDIO) {
                       if (((Pilar *)mapa.ver(i,j))->tipo_pilar == TipoPilar::ESPADA)
                           std::cout << "PE" << mapa.ver(i, j)->time;
                       else if (((Pilar *)mapa.ver(i, j))->tipo_pilar == TipoPilar::LANCA)
                           std::cout << "PL" << mapa.ver(i, j)->time;
                       else if (((Pilar *)mapa.ver(i, j))->tipo_pilar == TipoPilar::ARCO)
                           std::cout << "PA" << mapa.ver(i, j)->time;
                   }
               }
           }
           std::cout << std::endl;
       }
    #endif
}

