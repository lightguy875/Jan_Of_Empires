#include "../include/Graphics.hpp"

Button menuButtons[ TOTAL_MENU_BUTTONS ];
Button pauseButton[2];
Button creditsBackButton;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
Texture menu_screen;
Texture credit_screen;
Texture pause_screen;
Texture round_screen;

bool Graphics::init(){
    bool success = true;

    //Inicializa o  SDL
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ){
        printf( "Erro ao iniciar o SDL \n Erro: %s\n", SDL_GetError() );
        success = false;
    }
    else {
        window = SDL_CreateWindow( "Jan of Empiries", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL ){
            printf( "Janela nao pode ser criada! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else{
            //cria renderer vsync
            renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( renderer == NULL )
            {
                printf( "Nao foi possivel renderizar utilizando SDL! \n Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //inicializa a cor do renderer
                SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //carregamento de png
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "Erro ao iniciar o SDL_Image \n Erro: %s\n", IMG_GetError() );
                    success = false;
                }
            }
        }
    }
    return success;
}

bool Graphics::loadMedia(){
    bool success = true;

    //carrega menu
    if( !menu_screen.loadFromFile( "../assets/menu_screen.png" ) ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }

    //carrega credits
    if( !credit_screen.loadFromFile( "../assets/credit_screen.png" ) ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }

    if( !pause_screen.loadFromFile( "../assets/pause_screen.png" ) ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }

    if( !round_screen.loadFromFile( "../assets/round_screen.png" ) ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }

    menuButtons[0].setPositionSizeType(0,0,800,200, BUTTON_PLAY);
    menuButtons[1].setPositionSizeType(0,200,800,200,BUTTON_CREDITS);
    menuButtons[2].setPositionSizeType(0,400,800,200,BUTTON_QUIT);
    creditsBackButton.setPositionSizeType(0,500,800,100,BUTTON_BACK_CREDITS);
    pauseButton[0].setPositionSizeType(0,0,800,300,BUTTON_BACK_GAME);
    pauseButton[1].setPositionSizeType(0,300,800,300,BUTTON_QUIT);

    return success;
}

void Graphics::close(){
    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    window = NULL;
    renderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}
