//#ifndef SDL_STRUCTURE
//#define SDL_STRUCTURE
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include  <iostream>

//Screen dimension constants
static const int SCREEN_WIDTH = 800;
static const int SCREEN_HEIGHT = 600;
static bool Run = true;

static SDL_Event Events;
//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
static SDL_Window *gWindow = NULL;

//The surface contained by the window
static SDL_Surface *gScreenSurface = NULL;

//The image we will load and show on the screen
static SDL_Surface *gHelloWorld = NULL;
//#endif