#include "../include/Game.hpp"
#include <cstdio>

Game::Game(){
    gameRunning = GAME_MENU;
}


GameState Game::getGameRunning(){
    return gameRunning;
}

void Game::setGameRunning(GameState gameState){
    gameRunning = gameState;
}

void Game::renderMenu(){
    SDL_Event e;

    while(gameRunning == GAME_MENU){

            //Handle events on queue
            while( SDL_PollEvent( &e ) != 0 ) {
                //User requests quit
                if( e.type == SDL_QUIT )
                {
                    gameRunning = GAME_QUIT;
                }else{
                    for (int i = 0; i < TOTAL_MENU_BUTTONS; ++i)
                    {
                        menuButtons[i].handleEvent( &e , this);
                    }
                }
            }

            SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( renderer );
            menu_screen.render(0,0);
            SDL_RenderPresent( renderer );
    }
}

void Game::renderCredits(){
    SDL_Event e;

    while(gameRunning == GAME_CREDITS){

            //Handle events on queue
            while( SDL_PollEvent( &e ) != 0 ) {
                //User requests quit
                if( e.type == SDL_QUIT )
                {
                    gameRunning = GAME_QUIT;
                }else{
                    creditsBackButton.handleEvent( &e , this);
                }
            }

            SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( renderer );
            credit_screen.render(0,0);
            SDL_RenderPresent( renderer );
    }
}

void Game::renderPlay(){
    SDL_Event e;

    while(gameRunning == GAME_PLAY){

            //Handle events on queue
            while( SDL_PollEvent( &e ) != 0 ) {
                //User requests quit
                if( e.type == SDL_QUIT )
                {
                    gameRunning = GAME_QUIT;
                }
                else if( e.type == SDL_KEYDOWN )
                {
                    if (e.key.keysym.sym == SDLK_ESCAPE)
                    {
                        gameRunning = GAME_PAUSE;
                    }
                }
            }

            SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( renderer );
            SDL_RenderPresent( renderer );
    }
}

void Game::renderPause(){
    SDL_Event e;

    while(gameRunning == GAME_PAUSE){

            //Handle events on queue
            while( SDL_PollEvent( &e ) != 0 ) {
                //User requests quit
                if( e.type == SDL_QUIT )
                {
                    gameRunning = GAME_QUIT;
                }
                pauseButton[0].handleEvent( &e, this);
                pauseButton[1].handleEvent( &e, this);
            }

            SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( renderer );
            pause_screen.render(0,0);
            SDL_RenderPresent( renderer );
    }
}


void Game::playGame(GameState gameState){
    gameRunning = gameState;

    while (gameRunning != GAME_QUIT)
    {
        switch (gameRunning)
        {
        case GAME_MENU:
            renderMenu();
            break;
        case GAME_PLAY:
            renderPlay();
            break;
        case GAME_PAUSE:
            renderPause();
            break;
        case GAME_CREDITS:
            renderCredits();
            break;
        }
    }
}
