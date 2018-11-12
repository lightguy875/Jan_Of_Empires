#define CATCH_CONFIG_MAIN // This tells Catch to provide a main()

#include "../lib/catch.hpp"
#include "../include/Necromancer.hpp"
#include "../include/Recurso.hpp"
#include "../include/Pilar.hpp"
#include "../include/Bloco.hpp"
#include "../include/Mapa.hpp"

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

TEST_CASE("Teste do mapa", "teste inicial do mapa"){

    Mapa mapa = Mapa(25,25);
    REQUIRE(mapa.vazio(2,2) == true);
    REQUIRE(mapa.vazio(-1,2) == false);

    Recurso metal = Metal();
    REQUIRE(mapa.inserir(&metal, 2,2) == true);
    REQUIRE(mapa.inserir(&metal, 2,2) == false);
    REQUIRE(mapa.inserir(&metal, 25,25) == false);
    REQUIRE(mapa.inserir(&metal, 2,-2) == false);
    REQUIRE(mapa.vazio(2,2) == false);

    REQUIRE( mapa.ver(2,2) == &metal);
    REQUIRE( mapa.ver(2,2)->tipo == TipoConteudoBloco::RECURSO);
    REQUIRE( ((Recurso *)mapa.ver(2,2))->tipo_recurso == TipoRecurso::METAL);
    REQUIRE(mapa.ver(2,3) == nullptr);
}