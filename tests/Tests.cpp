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
TEST_CASE("Teste do bloco","Teste checagem de tipo, sub tipo e bloco vazio")
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
TEST_CASE("Teste do mapa", "teste inicial do mapa"){
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


TEST_CASE("Teste do Player", "Inicializacao") {
    // inicialização
    Player p1 = Player();

    // testes referentes a pilar
    REQUIRE(p1.pilar_espada.vivo == true);
    REQUIRE(p1.criar_pilar(TipoPilar::ARCO) == false);  // sem metal o suficiente
    p1.metal = METAL_CRIAR_PILAR_ARCO;
    REQUIRE(p1.criar_pilar(TipoPilar::ARCO) == true);
    REQUIRE(p1.criar_pilar(TipoPilar::LANCA) == false);  // sem metal o suficiente
    p1.metal = METAL_CRIAR_PILAR_LANCA;
    REQUIRE(p1.criar_pilar(TipoPilar::LANCA) == true);

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
    REQUIRE(p1.criar_necromancer(TipoNecromancer::CAVALEIRO) == false);  // sem ossos o suficiente
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
TEST_CASE("Teste do Controlador", "Bla"){
    Controlador contr;
    REQUIRE(contr.novo_jogo(false)==true);
    contr.jogador.metal=100;
    contr.jogador.ossos=100;
    REQUIRE(contr.criar_pilar(&contr.jogador, TipoPilar::ARCO, 3,3)==true);
    REQUIRE(contr.criar_necromancer(&contr.jogador, TipoNecromancer::ARQUEIRO, 2,2)==true);
    
    // pra debugar
    // contr.print_mapa();
}






