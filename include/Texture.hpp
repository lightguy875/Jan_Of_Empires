//// "Copyright 2018 Jan_of_Empires"
/**
 * @file Texture.hpp
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
#ifndef SDL_INCLUDES
#define SDL_INCLUDES
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#endif

#include "common.hpp"

#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <string>

class Texture {
    public:
        //inicia as variaveis
        Texture();

        //desaloca memoria
        ~Texture();

        //carrega imagens de um arquivo
        bool loadFromFile( std::string path);

        bool loadFromRenderedText( std::string text);

        //Desaloca textura
        void free();

        //Renderiza textura em algum ponto
        void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

        //dimensoes da imagem
        int getWidth();
        int getHeight();

    private:
        //a textura
        SDL_Texture* mTexture;

        //dimensoes da imagem
        int mWidth;
        int mHeight;

};

#endif
