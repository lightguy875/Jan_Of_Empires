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
                gWindow = SDL_CreateWindow("Jan of empires", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
                if (gWindow == NULL)
                {
                        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
                        success = false;
                }
                else
                {
                        //Get window surface
                        gScreenSurface = SDL_GetWindowSurface(gWindow);
                        //SDL_SetWindowResizable(gWindow, SDL_TRUE);
                }
        }

        return success;
}
bool loadMedia()
{
        if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG ))
        {
                std::cout << "Failed to initialize SDL_image for png files: " << IMG_GetError() << std::endl;
                return false;
        }
        //Loading success flag
        bool success = true;

        //Load splash image
        gMainmenu = IMG_Load("../assets/button_rpg.png");
        if (gMainmenu == NULL)
        {
                printf("Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
                success = false;
        }

        return success;
}
void close()
{
        //Deallocate surface
        SDL_FreeSurface(gMainmenu);
        SDL_FreeSurface(gScreenSurface);
        gMainmenu = NULL;

        //Destroy window
        SDL_DestroyWindow(gWindow);
        gWindow = NULL;

        //Quit SDL subsystems
        SDL_Quit();
}

