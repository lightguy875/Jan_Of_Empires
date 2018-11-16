#include "../include/SDL_menu.hpp"
//Screen dimension constants

bool Run = true;
SDL_Event Events;
SDL_Window *gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Texture* gTexture = NULL;

int main(int argc, char *args[])
{
    //Start up SDL and create window
    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        //Load media
        if (!loadMedia())
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
                //Clear screen
                SDL_RenderClear( gRenderer );
                //Render texture to screen
                SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
                //Update screen
                SDL_RenderPresent( gRenderer );
            }

            //Free resources and close SDL
            close();
        }
    }


    return 0;
}
