#ifndef GRAPHICS_STRUCTURE
#define GRAPHICS_STRUCTURE

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

#include "Texture.hpp"
#include "common.hpp"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

class Graphics{
    public:
        bool init();
        bool loadMedia();
        void close();
};

#endif
