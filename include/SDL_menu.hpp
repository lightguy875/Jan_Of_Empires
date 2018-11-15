#ifndef SDL_STRUCTURE
#define SDL_STRUCTURE
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <stdio.h>
#include <string>


//Starts up SDL and creates window
bool init(SDL_Window **gWindow, SDL_Surface **gScreenSurface, const int SCREEN_WIDTH, const int SCREEN_HEIGHT);

//Loads media
bool loadMedia(SDL_Surface **gPNGSurface, SDL_Surface **gScreenSurface);

//Frees media and shuts down SDL
void close(SDL_Surface **gPNGSurface, SDL_Window **gWindow);

//Loads individual image
SDL_Surface *loadSurface(std::string path, SDL_Surface **gScreenSurface);

#endif