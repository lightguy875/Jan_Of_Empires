#include "../include/SDL_menu.hpp"
//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
bool Run = true;
SDL_Event Events;
//The window we'll be rendering to
SDL_Window *gWindow = NULL;

//The surface contained by the window
SDL_Surface *gScreenSurface = NULL;

//Current displayed PNG image
SDL_Surface *gPNGSurface = NULL;

int main(int argc, char *args[])
{
    //Start up SDL and create window
    if (!init( &gWindow , &gScreenSurface ,SCREEN_WIDTH , SCREEN_HEIGHT))
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        //Load media
        if (!loadMedia( &gPNGSurface, &gScreenSurface))
        {
            printf("Failed to load media!\n");
        }
        else
        {
            while (Run)
            {
                while (SDL_PollEvent(&Events) != 0)
                {
                    if (Events.type == SDL_QUIT)
                        Run = false;
                }
                SDL_BlitSurface(gPNGSurface, NULL, gScreenSurface, NULL);
                SDL_UpdateWindowSurface(gWindow);
                //SDL_UpdateWindowSurface(gWindow);
                // draw pretty pictures to the window :3
                SDL_Delay(100);
            }

            //Free resources and close SDL
            close(&gPNGSurface, &gWindow);
        }
    }
   

    return 0;
}