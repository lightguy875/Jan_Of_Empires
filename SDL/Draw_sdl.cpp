#include "../include/SDL_menu.hpp"
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
            //Apply the image
            SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

            //Update the surface
            SDL_UpdateWindowSurface(gWindow);
        }
    }
    while (Run)
    {
        while (SDL_PollEvent(&Events))
        {
            if (Events.type == SDL_QUIT)
                Run = false;
        }
        // draw pretty pictures to the window :3
        SDL_Delay(100);
    }

    //Free resources and close SDL
    close();

    return 0;
}