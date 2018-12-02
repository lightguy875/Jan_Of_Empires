//// "Copyright 2018 Jan_of_Empires"
/**
 * @file main.cpp
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
#include "../include/Game.hpp"
#include "../include/Graphics.hpp"

/**
 * @brief 
 * 
 * @param argc 
 * @param args 
 * @return int 
 */
int main(int argc, char *args[]) {
    Graphics *graphics = new Graphics();
    Game *game = new Game();

    if (!graphics->init()) {
        printf("Falha ao inicializar!\n");
    } else {
        // Carrega mídia
        if (!graphics->loadMedia()) {
            printf("Nao foi possivel carregar a midia!\n");
        } else {
            game->playGame(GAME_MENU);
        }
        graphics->close();;
    }

    return 0;
}

// #include "../include/Necromancer.hpp"
// #include "../include/Recurso.hpp"
// #include "../include/Pilar.hpp"
// #include "../include/Bloco.hpp"
// #include <iostream>
