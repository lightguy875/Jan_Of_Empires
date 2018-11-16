#include "../include/SDL_menu.hpp"

Graphics::Graphics(){
    window = NULL;
    renderer = NULL;
    m_pTexture = NULL;
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        window = SDL_CreateWindow("Jan Of Empires", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }else{
            //Create renderer for window
           renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
           if( renderer == NULL )
           {
               printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
           }
           else
           {
               int imgFlags = IMG_INIT_PNG;
               if( !( IMG_Init( imgFlags ) & imgFlags ) )
               {
                   printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
               }else{
                   m_pTexture = loadTexture("../assets/button_rpg.bmp");
                   if (m_pTexture == NULL)
                   {
                       printf( "Unable to load image %s! SDL Error: %s\n", "../asset/button_rpg.png", SDL_GetError() );
                   }else{
                        g_running = true;
                   }
               }
           }
        }
    }
}

void Graphics::close()
{
    //Deallocate surface
    SDL_DestroyTexture( m_pTexture );
    m_pTexture = NULL;

    //Destroy window
    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    window = NULL;
    renderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}




SDL_Texture* Graphics::loadTexture( std::string path )
{
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}

bool Graphics::getGRunning(){
    return g_running;
}

void Graphics::setGRunning(bool state){
    g_running = state;
}


void Graphics::start_menu(){
    while (g_running)
    {
        while (SDL_PollEvent(&Events) != 0)
        {
            if (Events.type == SDL_QUIT)
                g_running = false;
        }
        SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        //Clear screen
        SDL_RenderClear( renderer );
        //Render texture to screen
        SDL_RenderCopy( renderer, m_pTexture, NULL, NULL );
        //Update screen
        SDL_RenderPresent( renderer );
    }
}
