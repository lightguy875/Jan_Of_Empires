#include "../include/SDL_menu.hpp"

extern bool Run;
extern SDL_Event Events;
extern SDL_Window *gWindow;
extern SDL_Renderer* gRenderer;
extern SDL_Texture* gTexture;

bool init(){
    bool success = true;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        gWindow = SDL_CreateWindow("Jan Of Empires", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }else{
            //Create renderer for window
           gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
           if( gRenderer == NULL )
           {
               printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
               success = false;
           }
           else
           {
               //Initialize renderer color
               SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

               //Initialize PNG loading
               int imgFlags = IMG_INIT_PNG;
               if( !( IMG_Init( imgFlags ) & imgFlags ) )
               {
                   printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                   success = false;
               }
           }
        }
    }

    return success;
}

bool loadMedia(){
    bool success = true;
    gTexture = loadTexture("../assets/button_rpg.png");
    if (gTexture == NULL)
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "../asset/button_rpg.png", SDL_GetError() );
        success = false;
    }

    return success;
}

void close()
{
    //Deallocate surface
    SDL_DestroyTexture( gTexture );
    gTexture = NULL;

    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}


SDL_Texture* loadTexture( std::string path )
{
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}
