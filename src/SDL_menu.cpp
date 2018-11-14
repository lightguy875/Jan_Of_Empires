#include "SDL2/SDL.h"
#include <iostream>


int main(int argc, char const *argv[])
{
        const int HEIGHT = 600;
        const int WIDTH = 800;
        bool running = true;
        //Init SDL
        
        if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
        {
                running = false;
        }
        SDL_Surface *screen;

        SDL_Window *window = SDL_CreateWindow("Jan_of_empires",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WIDTH,HEIGHT,SDL_WINDOW_SHOWN);
        
        SDL_Surface *gScreenSurface = NULL;
        //Set up screen
        
        //screen = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);
        
        if(window == NULL)
        {
                std::cout << "A janela não pode ser criada" << SDL_GetError() << std::endl;
                return EXIT_FAILURE;
        }
        gScreenSurface = SDL_GetWindowSurface(window);
            SDL_Event windowEvent;

        while (running == true)
        {
                SDL_PollEvent(&windowEvent);

                if(windowEvent.type == SDL_QUIT)
                {
                        running = false;
                }
                SDL_FillRect(gScreenSurface,NULL,0);


                
        }
        
        //
        SDL_Quit();

        return 0;
}
