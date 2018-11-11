#define CATCH_CONFIG_MAIN // This tells Catch to provide a main()

#include "../lib/catch.hpp"
#include "../include/Necromancer.hpp"
#include "../include/Recurso.hpp"
#include "../include/Pilar.hpp"
#include "../include/Bloco.hpp"

TEST_CASE("Teste do bloco","Teste checagem de tipo e sub tipo")
{

    Bloco bloco = Bloco();

    REQUIRE(bloco.vazio == true);

    Necromancer guerr = Guerreiro();
    bloco.preenche(&guerr);
    REQUIRE(bloco.vazio == false);
    REQUIRE(bloco.conteudo->tipo == TipoConteudoBloco::UNIDADE);
    
    Necromancer *n = (Necromancer *) bloco.conteudo;
    REQUIRE(n->tipo_necromancer == TipoNecromancer::GUERREIRO);

    bloco.limpa();
    REQUIRE(bloco.vazio == true);

}

