//// "Copyright 2018 Jan_of_Empires"
/**
 * @file Game.hpp
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
#include "common.hpp"


#ifndef SDL_INCLUDES
#define SDL_INCLUDES
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#endif

#ifndef GAME_STRUCTURE
#define GAME_STRUCTURE

enum GameState {
    GAME_MENU,
    GAME_CREDITS,
    GAME_QUIT,
    GAME_PLAY,
    GAME_PAUSE,
    GAME_ROUND_PAUSE,
    GAME_GANHOU,
};

class Game{
    public:
    Game();
    void playGame(GameState gameState);
    GameState getGameRunning();
    void setGameRunning(GameState gameState);

    private:
    GameState gameRunning;
    void renderMenu();
    void renderCredits();
    void renderPause();
    void renderPlay();
    void renderRoundPause();
    void renderStatus(int time);
    void renderGanhou();

};


#endif
