#include "../include/Game.hpp"
#include "../include/Controlador.hpp"
#include <cstdio>
#include <string>
#include <sstream>

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

void boxWarning(string text){
    const SDL_MessageBoxColorScheme colorScheme = {
        { /* .colors (.r, .g, .b) */
            /* [SDL_MESSAGEBOX_COLOR_BACKGROUND] */
            { 255,   0,   0 },
            /* [SDL_MESSAGEBOX_COLOR_TEXT] */
            {   0, 255,   0 },
            /* [SDL_MESSAGEBOX_COLOR_BUTTON_BORDER] */
            { 255, 255,   0 },
            /* [SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND] */
            {   0,   0, 255 },
            /* [SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED] */
            { 255,   0, 255 }
        }
    };
    const SDL_MessageBoxData messageboxdata = {
        SDL_MESSAGEBOX_INFORMATION, /* .flags */
        NULL, /* .window */
        "Atencao", /* .title */
        text.c_str(), /* .message */
        0, /* .numbuttons */
        NULL, /* .buttons */
        &colorScheme /* .colorScheme */
    };
    int buttonid;
    if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
        SDL_Log("error displaying message box");
    }
}

int boxPilar(){
    const SDL_MessageBoxButtonData buttons[] = {
        { /* .flags, .buttonid, .text */        0, 0, "Cancelar" },
        { 0, 1, "Fortalecer Pilar" },
        { 0, 2, "Fortalecer Necromancer" },
    };
    const SDL_MessageBoxColorScheme colorScheme = {
        { /* .colors (.r, .g, .b) */
            /* [SDL_MESSAGEBOX_COLOR_BACKGROUND] */
            { 255,   0,   0 },
            /* [SDL_MESSAGEBOX_COLOR_TEXT] */
            {   0, 255,   0 },
            /* [SDL_MESSAGEBOX_COLOR_BUTTON_BORDER] */
            { 255, 255,   0 },
            /* [SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND] */
            {   0,   0, 255 },
            /* [SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED] */
            { 255,   0, 255 }
        }
    };
    const SDL_MessageBoxData messageboxdata = {
        SDL_MESSAGEBOX_INFORMATION, /* .flags */
        NULL, /* .window */
        "Central de Controle do Pilar", /* .title */
        "Selecione uma opção:", /* .message */
        SDL_arraysize(buttons), /* .numbuttons */
        buttons, /* .buttons */
        &colorScheme /* .colorScheme */
    };
    int buttonid;
    if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
        SDL_Log("error displaying message box");
    }
    if (buttonid == -1) {
        SDL_Log("no selection");
        return CANCEL;
    } else {
        switch (buttonid)
        {
        case 1:
            return BUTTON_FORT_PILAR;
            break;
        case 2:
            return BUTTON_FORT_NECRO;
            break;
        }
        SDL_Log("selection was %s", buttons[buttonid].text);
    }
    return CANCEL;
}

void action_pilar_option(int option, Controlador * controlador, TipoPilar tipo_p, TipoNecromancer tipo_n ){
    switch (option){
    case BUTTON_FORT_PILAR:
        if (controlador->vez == 0){
            if (controlador->fortalecer_pilar(&controlador->jogador,tipo_p)){
                boxWarning("Pilar fortalecido!");
            }else{
                boxWarning("Recursos insuficientes!");
            }
        }else{
            if (controlador->fortalecer_pilar(&controlador->computador,tipo_p)){
                boxWarning("Pilar fortalecido!");
            }else{
                boxWarning("Recursos insuficientes!");
            }
        }
        break;
    case BUTTON_FORT_NECRO:
        if (controlador->vez == 0){
            if (controlador->fortalecer_necromancer(&controlador->jogador,tipo_n)){
                boxWarning("Necromancer fortalecido!");
            }else{
                boxWarning("Recursos insuficientes!");
            }
        }else{
            if (controlador->fortalecer_necromancer(&controlador->computador,tipo_n)){
                boxWarning("Necromancer fortalecido!");
            }else{
                boxWarning("Recursos insuficientes!");
            }
        }
        break;
    }
}

void Game::renderStatus(int time){
    std::ostringstream time_s;
    if (time == 0){
        time_s << "TIME: " << 1;
    }else{
        time_s << "TIME: " << 2;
    }
    std::string t = time_s.str();

    textRound.loadFromRenderedText(t);
    textRound.render(38,568);
}

void handle_events_elements(Controlador * controlador,SDL_Event * e) {
    Mapa mapa = controlador->mapa;
    int i, j;
    for(j=0; j<14; j++){
        for(i=0; i<20; i++){
            if(!mapa.vazio(i,j)){
                if(mapa.ver(i,j)->tipo == TipoConteudoBloco::UNIDADE){
                    if(((Necromancer *)mapa.ver(i,j))->tipo_necromancer == TipoNecromancer::GUERREIRO)
                        ((Necromancer *)mapa.ver(i,j))->handleEvent(e,i*40,j*40);
                    else if(((Necromancer *)mapa.ver(i,j))->tipo_necromancer == TipoNecromancer::ARQUEIRO)
                        ((Necromancer *)mapa.ver(i,j))->handleEvent(e,i*40,j*40);
                    else if(((Necromancer *)mapa.ver(i,j))->tipo_necromancer == TipoNecromancer::CAVALEIRO)
                        ((Necromancer *)mapa.ver(i,j))->handleEvent(e,i*40,j*40);
                }
                if(mapa.ver(i,j)->tipo == TipoConteudoBloco::PREDIO){
                    if(((Pilar *)mapa.ver(i,j))->tipo_pilar == TipoPilar::ESPADA){
                         if (((Pilar *)mapa.ver(i,j))->handleEvent(e,i*40,j*40) && ((Pilar *)mapa.ver(i,j))->time == controlador->vez){
                            action_pilar_option(boxPilar(),controlador, TipoPilar::ESPADA, TipoNecromancer::GUERREIRO);
                         }
                    }else if(((Pilar *)mapa.ver(i,j))->tipo_pilar == TipoPilar::LANCA){
                        if (((Pilar *)mapa.ver(i,j))->handleEvent(e,i*40,j*40) && ((Pilar *)mapa.ver(i,j))->time == controlador->vez){
                           action_pilar_option(boxPilar(),controlador, TipoPilar::LANCA, TipoNecromancer::CAVALEIRO);
                        }
                    }else if(((Pilar *)mapa.ver(i,j))->tipo_pilar == TipoPilar::ARCO){
                        if (((Pilar *)mapa.ver(i,j))->handleEvent(e,i*40,j*40) && ((Pilar *)mapa.ver(i,j))->time == controlador->vez){
                            action_pilar_option(boxPilar(),controlador, TipoPilar::ARCO, TipoNecromancer::ARQUEIRO);
                        }
                    }
                }
            }
        }
    }
}

void movimentar_ativo(Controlador * controlador,SDL_Event * e){
    if( e->type == SDL_MOUSEBUTTONDOWN )
    {
        int x, y;
        SDL_GetMouseState( &x, &y );
        switch( e->type ) {
            case SDL_MOUSEBUTTONDOWN:
                if (controlador->vez == 0){
                    if (controlador->movimentar(&controlador->jogador, ativo_x_jog,ativo_y_jog, x/40, y/40)){
                        ativo_x_jog = x/40;
                        ativo_y_jog = y/40;
                    }
                }else{
                    if (controlador->movimentar(&controlador->computador, ativo_x_cpu,ativo_y_cpu, x/40, y/40)){
                        ativo_x_cpu = x/40;
                        ativo_y_cpu = y/40;
                    }
                }
            break;
        }
    }
}

void Game::renderPlay(){
    SDL_Event e;
    Controlador controlador;
    controlador.novo_jogo(true,false);
    // Personage archer_play;
    // archer_play.setPositionX(0+PLAYER_AREA_START_X);
    // archer_play.setPositionY(0+PLAYER_AREA_START_Y);
    // archer_play.setWidthHeight(archer.getWidth(),archer.getHeight());
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
                movimentar_ativo(&controlador, &e);
                handle_events_elements(&controlador, &e);
                // archer_play.handleEvent(&e);
            }

            SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( renderer );
            map_screen.render(0,0);
            controlador.print_mapa();
            controlador.print_recursos();
            if (controlador.vez == 0){
                controlador.jogador.print_recursos("Jogador 1");
            }else{
                controlador.computador.print_recursos("Jogador 2");
            }
            renderStatus(controlador.vez);
            // archer_play.render(&archer);
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

void Game::renderRoundPause(){
    SDL_Event e;

    while(gameRunning == GAME_ROUND_PAUSE){

            //Handle events on queue
            while( SDL_PollEvent( &e ) != 0 ) {
                //User requests quit
                if( e.type == SDL_QUIT )
                {
                    gameRunning = GAME_QUIT;
                }
            }

            SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( renderer );
            round_screen.render(0,0);
            SDL_RenderPresent( renderer );
            SDL_Delay(3000);
            gameRunning = GAME_PLAY;
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
        case GAME_ROUND_PAUSE:
            renderRoundPause();
            break;
        case GAME_CREDITS:
            renderCredits();
            break;
        }
    }
}
