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
        /**
         * @brief Inicializa a textura com os atributos zerados
         */
        Texture();

        /**
         * @brief Desaloca a textura, liberando a memoria alocada.
         *
         */
        ~Texture();

        /**
         * @brief Carrega na textura um imagem png
         *
         * @param path - diretório do arquivo a ser carregado
         * @return true imagem carregada com sucesso por todas as estruturas
         * @return false caso ocorra algum erro no upload da imagem
         */
        bool loadFromFile( std::string path);

        /**
         * @brief Carrega na texturaum texto qualquer
         *
         * @param text - texto a ser rendeizado na textura
         * @return true texto carregado com sucesso por todas as estruturas
         * @return false caso ocorra algum erro na criação da textura com o texto renderizado
         */
        bool loadFromRenderedText( std::string text);

        /**
         * @brief Libera o objeto da textura
         *
         */
        void free();

        /**
         * @brief
         *
         * @param x - coordenada x onde será renderizado a textura
         * @param y - coordenada y onde será renderizado a textura
         * @param clip - coordenadas para corte de parte da textura em tempo de renderização
         * @param angle - ângulo do objeto a ser renderizado
         * @param center - ponto do centro do objeto
         * @param flip - direção do objeto
         */
        void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

        /**
         * @brief Função de acesso a variável de comprimento da textu
         * @return comprimento textura
         */
        int getWidth();

        /**
         * @brief Função de acesso a variável de altura da textu
         * @return altura textura
         */
        int getHeight();

    private:
        SDL_Texture* mTexture;
        int mWidth;
        int mHeight;

};

#endif
