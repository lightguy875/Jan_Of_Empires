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

};


#endif
