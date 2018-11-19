#ifndef GRAPHICS_STRUCTURE
#define GRAPHICS_STRUCTURE

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

#include "Texture.hpp"
#include "common.hpp"

class Graphics{
    public:
        bool init();
        bool loadMedia();
        void close();
};

#endif
