#define CATCH_CONFIG_MAIN // This tells Catch to provide a main()

#include "../lib/catch.hpp"
#include "../include/Necromancer.hpp"
#include "../include/Recurso.hpp"
#include "../include/Pilar.hpp"
#include "../include/Bloco.hpp"
#include "../include/Mapa.hpp"
#include "../include/Player.hpp"
#include "../include/Controlador.hpp"

// TS001
TEST_CASE("Teste da classe bloco","Teste checagem de tipo, sub tipo e bloco vazio")
{
    Bloco bloco = Bloco();
    Necromancer guerr = Guerreiro();


    REQUIRE(bloco.vazio == true);

    REQUIRE(bloco.preenche(&guerr)==true);
    REQUIRE(bloco.preenche(&guerr)==false);
    REQUIRE(bloco.vazio == false);
    REQUIRE((Necromancer *) bloco.conteudo == &guerr);
    REQUIRE(bloco.conteudo->tipo == TipoConteudoBloco::UNIDADE);
    
    Necromancer *n = (Necromancer *) bloco.conteudo;
    
    REQUIRE(n->tipo_necromancer == TipoNecromancer::GUERREIRO);
    REQUIRE(bloco.vazio == false);
    REQUIRE(bloco.limpa() == true);
    REQUIRE(bloco.limpa() == false);
    REQUIRE(bloco.vazio == true);   

    
}

//TS002
TEST_CASE("Teste da classe mapa", "teste inicial do mapa"){
    // vazio
    Mapa mapa = Mapa(25,25);
    REQUIRE(mapa.vazio(2,2) == true);
    REQUIRE(mapa.vazio(-1,2) == false);

    //inserir
    Recurso metal = Metal();
    REQUIRE(mapa.inserir(&metal, 2,3) == true);
    REQUIRE(mapa.inserir(&metal, 2,3) == false);
    REQUIRE(mapa.inserir(&metal, 25,25) == false);
    REQUIRE(mapa.inserir(&metal, 2,-2) == false);
    REQUIRE(metal.x == 2);
    REQUIRE(metal.y == 3);
    REQUIRE(mapa.vazio(2,3) == false);


    //ver
    REQUIRE( mapa.ver(2,3) == &metal);
    REQUIRE( mapa.ver(2,3)->tipo == TipoConteudoBloco::RECURSO);
    REQUIRE( ((Recurso *)mapa.ver(2,3))->tipo_recurso == TipoRecurso::METAL);
    REQUIRE(mapa.ver(2,2) == nullptr);
    REQUIRE(mapa.vazio(2,3) == false);

    //retirar
    Recurso *retorno =  (Recurso *) mapa.retirar(2,3);
    REQUIRE(retorno == &metal);
    REQUIRE(mapa.ver(2,3) == nullptr);
    REQUIRE(mapa.vazio(2,3) == true);

}

//TS003
TEST_CASE("Teste da classe Player", "Inicializacao") {
    // inicialização
    Player p1 = Player();

    // testes referentes a pilar
    // criar pilar
    REQUIRE(p1.pilar_espada.vivo == true);
    REQUIRE(p1.criar_pilar(TipoPilar::ARCO) == false);  // sem metal o suficiente
    p1.metal = METAL_CRIAR_PILAR_ARCO;
    REQUIRE(p1.criar_pilar(TipoPilar::ARCO) == true);
    REQUIRE(p1.tem_pilar(TipoPilar::ARCO) == true);
    REQUIRE(p1.criar_pilar(TipoPilar::LANCA) == false);  // sem metal o suficiente
    REQUIRE(p1.tem_pilar(TipoPilar::LANCA) == false); 
    p1.metal = METAL_CRIAR_PILAR_LANCA;
    REQUIRE(p1.criar_pilar(TipoPilar::LANCA) == true);

    // fortalecer pilar, pilar vivo
    REQUIRE(p1.pilar_espada.hp == HP_INICIAL_PILAR_ESPADA);
    p1.metal = METAL_CRIAR_PILAR_ESPADA;
    p1.criar_pilar(TipoPilar::ESPADA);
    REQUIRE(p1.pilar_espada.hp == 2*HP_INICIAL_PILAR_ESPADA);
    REQUIRE(p1.pilar_arco.hp == HP_INICIAL_PILAR_ARCO);
    p1.metal = METAL_CRIAR_PILAR_ARCO;
    p1.criar_pilar(TipoPilar::ARCO);
    REQUIRE(p1.pilar_arco.hp == 2*HP_INICIAL_PILAR_ARCO);
    REQUIRE(p1.pilar_lanca.hp == HP_INICIAL_PILAR_LANCA);
    p1.metal = METAL_CRIAR_PILAR_LANCA;
    p1.criar_pilar(TipoPilar::LANCA);
    REQUIRE(p1.pilar_lanca.hp == 2*HP_INICIAL_PILAR_LANCA);

    // testes referentes a necromancer
    REQUIRE(p1.guerreiro.vivo == true);  // guerreiro vivo?

    // para criar necromancer, pilares vivos
    REQUIRE(p1.criar_necromancer(TipoNecromancer::ARQUEIRO) == false);  // sem ossos o suficiente
    p1.ossos = OSSOS_CRIAR_ARQUEIRO;
    REQUIRE(p1.criar_necromancer(TipoNecromancer::ARQUEIRO) == true);
    REQUIRE(p1.tem_necromancer(TipoNecromancer::ARQUEIRO) == true); 
    REQUIRE(p1.criar_necromancer(TipoNecromancer::CAVALEIRO) == false);  // sem ossos o suficiente
    REQUIRE(p1.tem_necromancer(TipoNecromancer::CAVALEIRO) == false);
    p1.ossos = OSSOS_CRIAR_CAVALEIRO;
    REQUIRE(p1.criar_necromancer(TipoNecromancer::CAVALEIRO) == true);

    // para fortalecer necromancer, pilares vivos
    REQUIRE(p1.guerreiro.mp == MP_INICIAL_GUERREIRO);
    p1.ossos = OSSOS_CRIAR_GUERREIRO;
    REQUIRE(p1.criar_necromancer(TipoNecromancer::GUERREIRO) == true);
    REQUIRE(p1.guerreiro.mp == 2*MP_INICIAL_GUERREIRO);
    REQUIRE(p1.arqueiro.mp == MP_INICIAL_ARQUEIRO);
    p1.ossos = OSSOS_CRIAR_ARQUEIRO;
    REQUIRE(p1.criar_necromancer(TipoNecromancer::ARQUEIRO) == true);
    REQUIRE(p1.arqueiro.mp == 2*MP_INICIAL_ARQUEIRO);
    REQUIRE(p1.cavaleiro.mp == MP_INICIAL_CAVALEIRO);
    p1.ossos = OSSOS_CRIAR_CAVALEIRO;
    REQUIRE(p1.criar_necromancer(TipoNecromancer::CAVALEIRO) == true);
    REQUIRE(p1.cavaleiro.mp == 2*MP_INICIAL_CAVALEIRO);

    // mata todos os pilares
    p1.pilar_arco.mata();
    p1.pilar_espada.mata();
    p1.pilar_lanca.mata();

    // para fortalecer necromancer, pilares mortos
    REQUIRE(p1.guerreiro.mp == 2*MP_INICIAL_GUERREIRO);
    p1.ossos = OSSOS_CRIAR_GUERREIRO;
    REQUIRE(p1.criar_necromancer(TipoNecromancer::GUERREIRO) == false);  // não existe pilar
    REQUIRE(p1.guerreiro.mp == 2*MP_INICIAL_GUERREIRO);
    REQUIRE(p1.arqueiro.mp == 2*MP_INICIAL_ARQUEIRO);
    p1.ossos = OSSOS_CRIAR_ARQUEIRO;
    REQUIRE(p1.criar_necromancer(TipoNecromancer::ARQUEIRO) == false);  // não existe pilar
    REQUIRE(p1.arqueiro.mp == 2*MP_INICIAL_ARQUEIRO);
    REQUIRE(p1.cavaleiro.mp == 2*MP_INICIAL_CAVALEIRO);
    p1.ossos = OSSOS_CRIAR_CAVALEIRO;
    REQUIRE(p1.criar_necromancer(TipoNecromancer::CAVALEIRO) == false);  // não existe pilar
    REQUIRE(p1.cavaleiro.mp == 2*MP_INICIAL_CAVALEIRO);

    // mata todos os necromancers
    p1.arqueiro.mata();
    p1.cavaleiro.mata();
    p1.guerreiro.mata();

    // para criar necromancer, pilares mortos
    REQUIRE(p1.criar_necromancer(TipoNecromancer::GUERREIRO) == false);  // sem ossos o suficiente e não existe pilar
    p1.ossos = OSSOS_CRIAR_GUERREIRO;
    REQUIRE(p1.criar_necromancer(TipoNecromancer::GUERREIRO) == false);  // não existe pilar
    REQUIRE(p1.criar_necromancer(TipoNecromancer::ARQUEIRO) == false);  // sem ossos o suficiente e não existe pilar
    p1.ossos = OSSOS_CRIAR_ARQUEIRO;
    REQUIRE(p1.criar_necromancer(TipoNecromancer::ARQUEIRO) == false);  // não existe pilar
    REQUIRE(p1.criar_necromancer(TipoNecromancer::CAVALEIRO) == false);  // sem ossos o suficiente e não existe pilar
    p1.ossos = OSSOS_CRIAR_CAVALEIRO;
    REQUIRE(p1.criar_necromancer(TipoNecromancer::CAVALEIRO) == false);  // não existe pilar
    p1.ossos = 0;
}

// TS004
TEST_CASE("Teste da classe Controlador - Basico", "Regras Básicas"){
    Controlador contr;
    REQUIRE(contr.novo_jogo(false,false)==true);

    /******************* TESTES DE CRIAÇÃO E FORTALECIMENTO *******************/
    // testes de criação e fortalecimento referentes a pilar
    // fortalecer pilar, pilar morto
    REQUIRE(contr.jogador.pilar_arco.hp == HP_INICIAL_PILAR_ARCO);
    contr.jogador.metal = METAL_CRIAR_PILAR_ARCO;
    REQUIRE(contr.fortalecer_pilar(&contr.jogador, TipoPilar::ARCO) == false);
    REQUIRE(contr.jogador.pilar_arco.hp == HP_INICIAL_PILAR_ARCO);
    REQUIRE(contr.jogador.pilar_lanca.hp == HP_INICIAL_PILAR_LANCA);
    contr.jogador.metal = METAL_CRIAR_PILAR_LANCA;
    REQUIRE(contr.fortalecer_pilar(&contr.jogador, TipoPilar::LANCA) == false);
    REQUIRE(contr.jogador.pilar_lanca.hp == HP_INICIAL_PILAR_LANCA);

    // criar pilar
    REQUIRE(contr.criar_pilar(&contr.jogador, TipoPilar::ESPADA, 1, 1) == false);  // sem metal o suficiente
    contr.jogador.metal = METAL_CRIAR_PILAR_ESPADA;
    REQUIRE(contr.criar_pilar(&contr.jogador, TipoPilar::ESPADA, 1, 1) == false); // já existe o pilar
    contr.jogador.metal = 0;    
    REQUIRE(contr.criar_pilar(&contr.jogador, TipoPilar::ARCO, 3, 3) == false);  // sem metal o suficiente
    contr.jogador.metal = METAL_CRIAR_PILAR_ARCO;
    REQUIRE(contr.criar_pilar(&contr.jogador, TipoPilar::ARCO, 1, 1) == false); // já existe alguma unidade na posição colocada
    REQUIRE(contr.criar_pilar(&contr.jogador, TipoPilar::ARCO, 3, 3) == true);
    REQUIRE(contr.criar_pilar(&contr.jogador, TipoPilar::LANCA, 4, 5) == false);  // sem metal o suficiente
    contr.jogador.metal = METAL_CRIAR_PILAR_LANCA;
    REQUIRE(contr.criar_pilar(&contr.jogador, TipoPilar::ARCO, 3, 3) == false); // já existe alguma unidade na posição colocada
    REQUIRE(contr.criar_pilar(&contr.jogador, TipoPilar::LANCA, 4, 5) == true);

    // fortalecer pilar, pilar vivo
    REQUIRE(contr.jogador.pilar_espada.hp == HP_INICIAL_PILAR_ESPADA);
    contr.jogador.metal = METAL_CRIAR_PILAR_ESPADA;
    REQUIRE(contr.fortalecer_pilar(&contr.jogador, TipoPilar::ESPADA) == true);
    REQUIRE(contr.jogador.pilar_espada.hp == 2*HP_INICIAL_PILAR_ESPADA);
    REQUIRE(contr.jogador.pilar_arco.hp == HP_INICIAL_PILAR_ARCO);
    contr.jogador.metal = METAL_CRIAR_PILAR_ARCO;
    REQUIRE(contr.fortalecer_pilar(&contr.jogador, TipoPilar::ARCO) == true);
    REQUIRE(contr.jogador.pilar_arco.hp == 2*HP_INICIAL_PILAR_ARCO);
    REQUIRE(contr.jogador.pilar_lanca.hp == HP_INICIAL_PILAR_LANCA);
    contr.jogador.metal = METAL_CRIAR_PILAR_LANCA;
    REQUIRE(contr.fortalecer_pilar(&contr.jogador, TipoPilar::LANCA) == true);
    REQUIRE(contr.jogador.pilar_lanca.hp == 2*HP_INICIAL_PILAR_LANCA);

    // testes de criação e fortalecimento referentes a necromancer
    REQUIRE(contr.jogador.guerreiro.vivo == true);  // guerreiro vivo? sim

    // para fortalecer necromancer, necromancers mortos, pilares vivos
    REQUIRE(contr.jogador.arqueiro.mp == MP_INICIAL_ARQUEIRO);
    contr.jogador.ossos = OSSOS_CRIAR_ARQUEIRO;
    REQUIRE(contr.fortalecer_necromancer(&contr.jogador, TipoNecromancer::ARQUEIRO) == false);
    REQUIRE(contr.jogador.arqueiro.mp == MP_INICIAL_ARQUEIRO);
    REQUIRE(contr.jogador.cavaleiro.mp == MP_INICIAL_CAVALEIRO);
    contr.jogador.ossos = OSSOS_CRIAR_CAVALEIRO;
    REQUIRE(contr.fortalecer_necromancer(&contr.jogador, TipoNecromancer::CAVALEIRO) == false);
    REQUIRE(contr.jogador.cavaleiro.mp == MP_INICIAL_CAVALEIRO);

    // para criar necromancer, pilares vivos
    contr.jogador.ossos = 0;
    REQUIRE(contr.criar_necromancer(&contr.jogador, TipoNecromancer::ARQUEIRO, 2, 2) == false);  // sem ossos o suficiente
    contr.jogador.ossos = OSSOS_CRIAR_ARQUEIRO;
    REQUIRE(contr.criar_necromancer(&contr.jogador, TipoNecromancer::ARQUEIRO, 2, 2) == true);
    REQUIRE(contr.criar_necromancer(&contr.jogador, TipoNecromancer::CAVALEIRO, 4, 4) == false);  // sem ossos o suficiente
    contr.jogador.ossos = OSSOS_CRIAR_CAVALEIRO;
    REQUIRE(contr.criar_necromancer(&contr.jogador, TipoNecromancer::CAVALEIRO, 4, 4) == true);

    // para fortalecer necromancer, necromancers vivos, pilares vivos
    REQUIRE(contr.jogador.guerreiro.mp == MP_INICIAL_GUERREIRO);
    contr.jogador.ossos = OSSOS_CRIAR_GUERREIRO;
    REQUIRE(contr.fortalecer_necromancer(&contr.jogador, TipoNecromancer::GUERREIRO) == true);
    REQUIRE(contr.jogador.guerreiro.mp == 2*MP_INICIAL_GUERREIRO);
    REQUIRE(contr.jogador.arqueiro.mp == MP_INICIAL_ARQUEIRO);
    contr.jogador.ossos = OSSOS_CRIAR_ARQUEIRO;
    REQUIRE(contr.fortalecer_necromancer(&contr.jogador, TipoNecromancer::ARQUEIRO) == true);
    REQUIRE(contr.jogador.arqueiro.mp == 2*MP_INICIAL_ARQUEIRO);
    REQUIRE(contr.jogador.cavaleiro.mp == MP_INICIAL_CAVALEIRO);
    contr.jogador.ossos = OSSOS_CRIAR_CAVALEIRO;
    REQUIRE(contr.fortalecer_necromancer(&contr.jogador, TipoNecromancer::CAVALEIRO) == true);
    REQUIRE(contr.jogador.cavaleiro.mp == 2*MP_INICIAL_CAVALEIRO);

    /******************* TESTES DE DELEÇÃO *******************/
    // testes de deleção referentes a pilar
    // matar pilares
    REQUIRE(contr.matar(0, 3) == false); // espaço vazio
    REQUIRE(contr.matar(3, 3) == true); // mata pilar do arco
    REQUIRE(contr.matar(4, 5) == true); // mata pilar da lança

    // testes de deleção referentes a necromancer
    // matar necromancers
    REQUIRE(contr.matar(0, 3) == false); // espaço vazio
    REQUIRE(contr.matar(2, 2) == true); // mata necromancer arqueiro
    REQUIRE(contr.matar(4, 4) == true); // mata necromancer cavaleiro

    // para criar necromancer, necromancers mortos, pilares mortos
    contr.jogador.ossos = 0;
    REQUIRE(contr.criar_necromancer(&contr.jogador, TipoNecromancer::ARQUEIRO, 2, 2) == false);  // sem ossos o suficiente
    contr.jogador.ossos = OSSOS_CRIAR_ARQUEIRO;
    REQUIRE(contr.criar_necromancer(&contr.jogador, TipoNecromancer::ARQUEIRO, 2, 2) == false);
    REQUIRE(contr.criar_necromancer(&contr.jogador, TipoNecromancer::CAVALEIRO, 4, 4) == false);  // sem ossos o suficiente
    contr.jogador.ossos = OSSOS_CRIAR_CAVALEIRO;
    REQUIRE(contr.criar_necromancer(&contr.jogador, TipoNecromancer::CAVALEIRO, 4, 4) == false);

    // para fortalecer necromancer, necromancers mortos, pilares mortos
    contr.jogador.ossos = 0;
    REQUIRE(contr.jogador.arqueiro.mp == 2*MP_INICIAL_ARQUEIRO);
    contr.jogador.ossos = OSSOS_CRIAR_ARQUEIRO;
    REQUIRE(contr.fortalecer_necromancer(&contr.jogador, TipoNecromancer::ARQUEIRO) == false);
    REQUIRE(contr.jogador.arqueiro.mp == 2*MP_INICIAL_ARQUEIRO);
    REQUIRE(contr.jogador.cavaleiro.mp == 2*MP_INICIAL_CAVALEIRO);
    contr.jogador.ossos = OSSOS_CRIAR_CAVALEIRO;
    REQUIRE(contr.fortalecer_necromancer(&contr.jogador, TipoNecromancer::CAVALEIRO) == false);
    REQUIRE(contr.jogador.cavaleiro.mp == 2*MP_INICIAL_CAVALEIRO);

    // teste para matar recurso (isso não pode acontecer)
    Recurso r;
    r.tipo_recurso = TipoRecurso::METAL;
    REQUIRE(contr.mapa.inserir(&r, 6, 6) == true);
    REQUIRE(contr.matar(6, 6) == false); // não é possível matar recurso

    // pra debugar
    //contr.print_mapa();
}

// US003 e TS005
TEST_CASE("Teste da classe Controlador - Recursos/Movimentação", "Pegando Recursos"){
    
    Controlador contr;
    REQUIRE(contr.novo_jogo(false,false)==true);
 
    //insere recurso no mapa   
    Recurso *rec = new Metal();
    contr.mapa.inserir(rec, 2, 2);
    contr.recursos.push_back(*rec);
    Recurso *os = new Ossos();
    contr.mapa.inserir(os, 3, 3);
    contr.recursos.push_back(*os);

    // movimentação e captação de recursos - funcionamento normal
    // contr.print_recursos();
    // contr.jogador.print_recursos("Jogador");
    // contr.print_mapa();

    REQUIRE(contr.pode_movimentar(&contr.jogador, 1, 1, 2, 2) == true);
    REQUIRE(contr.movimentar(&contr.jogador, 1, 1, 2, 2) == true);
    
    // contr.jogador.print_recursos("Jogador");
    // contr.print_recursos();
    // contr.print_mapa();
    REQUIRE(contr.pode_movimentar(&contr.jogador, 2, 2, 3, 3) == true);
    REQUIRE(contr.movimentar(&contr.jogador, 2, 2, 3, 3) == true);
    
    // contr.jogador.print_recursos("Jogador");
    // contr.print_recursos();
    // contr.print_mapa();

    // organizar jogo para mais situações de teste
    REQUIRE(contr.pode_movimentar(&contr.jogador, 3, 3, 1, 1) == true);
    REQUIRE(contr.movimentar(&contr.jogador, 3, 3, 1, 1) == true);
    // contr.print_recursos();
    // contr.print_mapa();
    contr.jogador.metal = METAL_CRIAR_PILAR_ARCO;
    contr.jogador.ossos = OSSOS_CRIAR_ARQUEIRO;
    REQUIRE(contr.criar_pilar(&contr.jogador, TipoPilar::ARCO, 0, 1) == true);
    REQUIRE(contr.criar_necromancer(&contr.jogador, TipoNecromancer::ARQUEIRO, 0, 2) == true);

    // testes dos casos de movimento que tornam o retorno falso
    REQUIRE(contr.pode_movimentar(&contr.jogador, 1, 1, -1, -1) == false); // posição válida
    REQUIRE(contr.movimentar(&contr.jogador, 1, 1, -1, -1) == false);
    REQUIRE(contr.pode_movimentar(&contr.jogador, 1, 1, 5, 5) == false); // movimentar além da range de movimento
    REQUIRE(contr.movimentar(&contr.jogador, 1, 1, 5, 5) == false);
    REQUIRE(contr.pode_movimentar(&contr.jogador, 0, 1, 0, 2) == false); // bloco selecionado é vazio
    REQUIRE(contr.movimentar(&contr.jogador, 0, 1, 0, 2) == false);
    REQUIRE(contr.pode_movimentar(&contr.jogador, 13, 13, 13, 12) == false); // não é do mesmo time
    REQUIRE(contr.movimentar(&contr.jogador, 13, 13, 13, 12) == false);
    REQUIRE(contr.pode_movimentar(&contr.jogador, 1, 1, 0, 0) == false); // bloco onde quero mover não é vazio: pilar
    REQUIRE(contr.movimentar(&contr.jogador, 1, 1, 0, 0) == false);
    REQUIRE(contr.pode_movimentar(&contr.jogador, 1, 1, 0, 2) == false); // bloco onde quero mover não é vazio: unidade
    REQUIRE(contr.movimentar(&contr.jogador, 1, 1, 0, 2) == false);

    // contr.print_recursos();
    // contr.print_mapa();
}   


// TS006
TEST_CASE("Teste da classe Controlador - Combate", "Regras de Combate"){
    SECTION("Player ataca Computador") {
        Controlador contr;
        REQUIRE(contr.novo_jogo(false,false) == true);
        // setup para teste de funções de combate
        REQUIRE(contr.matar(19, 13) == true);
        REQUIRE(contr.matar(18, 12) == true);
        REQUIRE(contr.movimentar(&contr.jogador, 1, 1, 2, 1) == true);
        contr.jogador.metal = METAL_CRIAR_PILAR_ARCO
                                + METAL_CRIAR_PILAR_LANCA;
        REQUIRE(contr.criar_pilar(&contr.jogador, TipoPilar::ARCO, 0, 1) == true);
        REQUIRE(contr.criar_pilar(&contr.jogador, TipoPilar::LANCA, 0, 2) == true);
        contr.computador.metal = METAL_CRIAR_PILAR_ARCO
                                + METAL_CRIAR_PILAR_ESPADA 
                                + METAL_CRIAR_PILAR_LANCA;
        contr.computador.ossos = OSSOS_CRIAR_ARQUEIRO
                                + OSSOS_CRIAR_CAVALEIRO
                                + OSSOS_CRIAR_GUERREIRO;
        REQUIRE(contr.criar_pilar(&contr.computador, TipoPilar::ESPADA, 5, 0) == true);
        REQUIRE(contr.criar_pilar(&contr.computador, TipoPilar::ARCO, 5, 1) == true);
        REQUIRE(contr.criar_pilar(&contr.computador, TipoPilar::LANCA, 5, 2) == true);
        // espada vs espada
        // obs: todos os mecanismos de combate são chamados a partir de movimentar.
        // movimentar chama processa_jogada, que chama verifica_combate, que chama realiza_combate
        REQUIRE(contr.criar_necromancer(&contr.computador, TipoNecromancer::GUERREIRO, 3, 1) == true);
        REQUIRE(contr.gerou_combate(contr.mapa.ver(2,1)->time, 3, 1) == true);
        REQUIRE(contr.computador.guerreiro.mp == MP_INICIAL_GUERREIRO);
        REQUIRE(contr.computador.guerreiro.vivo == true);
        contr.realiza_combate(2, 1, 3, 1);
        REQUIRE(contr.computador.guerreiro.mp == MP_INICIAL_GUERREIRO - ESPADA_ESPADA_ATQ_MULTIPLICADOR*DANO_DE_ATQ);
        REQUIRE(contr.computador.guerreiro.vivo == true);
        // contr.computador.guerreiro.mp = ESPADA_ESPADA_ATQ_MULTIPLICADOR*DANO_DE_ATQ;
        // contr.realiza_combate(2, 1, 3, 1);
        // REQUIRE(contr.computador.guerreiro.mp == 0);
        // REQUIRE(contr.computador.guerreiro.vivo == false);
        // REQUIRE(contr.gerou_combate(contr.mapa.ver(2,1)->time, 3, 1) == false);
        contr.print_mapa();

        // espada vs arco
        // REQUIRE(contr.criar_necromancer(&contr.computador, TipoNecromancer::ARQUEIRO, 3, 1));
        // REQUIRE(contr.criar_necromancer(&contr.computador, TipoNecromancer::ARQUEIRO, 3, 1));
        

        // // espada vs lança
        // REQUIRE(contr.criar_necromancer(&contr.computador, TipoNecromancer::CAVALEIRO, 3, 2));

        contr.print_mapa();
    }
    SECTION("Computador ataca Player") {

    }
}



