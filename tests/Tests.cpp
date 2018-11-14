#define CATCH_CONFIG_MAIN // This tells Catch to provide a main()

#include "../lib/catch.hpp"
#include "../include/Necromancer.hpp"
#include "../include/Recurso.hpp"
#include "../include/Pilar.hpp"
#include "../include/Bloco.hpp"
#include "../include/Mapa.hpp"
#include "../include/Player.hpp"

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
    REQUIRE(mapa.inserir(&metal, 2,2) == true);
    REQUIRE(mapa.inserir(&metal, 2,2) == false);
    REQUIRE(mapa.inserir(&metal, 25,25) == false);
    REQUIRE(mapa.inserir(&metal, 2,-2) == false);
    REQUIRE(mapa.vazio(2,2) == false);


    //ver
    REQUIRE( mapa.ver(2,2) == &metal);
    REQUIRE( mapa.ver(2,2)->tipo == TipoConteudoBloco::RECURSO);
    REQUIRE( ((Recurso *)mapa.ver(2,2))->tipo_recurso == TipoRecurso::METAL);
    REQUIRE(mapa.ver(2,3) == nullptr);
    REQUIRE(mapa.vazio(2,2) == false);

    //retirar
    Recurso *retorno =  (Recurso *) mapa.retirar(2,2);
    REQUIRE(retorno == &metal);
    REQUIRE(mapa.ver(2,2) == nullptr);
    REQUIRE(mapa.vazio(2,2) == true);

}

TEST_CASE("Teste do Player", "Inicializacao"){
    Player p1 = Player();
    p1.ossos = 30;
    REQUIRE(p1.criar_necromancer(TipoNecromancer::GUERREIRO)==true);

}