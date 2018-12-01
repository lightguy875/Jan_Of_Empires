//// "Copyright 2018 Jan_of_Empires"
/**
 * @file Graphics.hpp
 * @author Alex Siqueira (siqueiralex@github.com)
 * @author Alexander André (Alexander-1995@github.com)
 * @author Arthur Veiga (arthurveiga@github.com)
 * @author Matheus Veleci (matheusvsantos@github.com)
 * @author Luis Luz (lightguy875@github.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-01
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef GRAPHICS_STRUCTURE
#define GRAPHICS_STRUCTURE

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "Texture.hpp"
#include "common.hpp"

class Graphics{
    public:
        bool init();
        bool loadMedia();
        void close();
};

#endif
