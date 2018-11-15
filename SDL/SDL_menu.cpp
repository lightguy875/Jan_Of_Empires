#include "../include/SDL_menu.hpp"

bool init()
{
        //Initialization flag
        bool success = true;

        //Initialize SDL
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        {
                printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
                success = false;
        }
        else
        {
                //Create window
                gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
                if (gWindow == NULL)
                {
                        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
                        success = false;
                }
                else
                {
                        //Get window surface
                        gScreenSurface = SDL_GetWindowSurface(gWindow);
                        SDL_SetWindowResizable(gWindow, SDL_TRUE);
                }
        }

        return success;
}
bool loadMedia()
{
        //Loading success flag
        bool success = true;

        //Load splash image
        gHelloWorld = SDL_LoadBMP("hello_world.bmp");
        if (gHelloWorld == NULL)
        {
                printf("Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
                success = false;
        }

        return success;
}
void close()
{
        //Deallocate surface
        SDL_FreeSurface(gHelloWorld);
        gHelloWorld = NULL;

        //Destroy window
        SDL_DestroyWindow(gWindow);
        gWindow = NULL;

        //Quit SDL subsystems
        SDL_Quit();
}

