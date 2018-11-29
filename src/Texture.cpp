#include "../include/Texture.hpp"

Texture::Texture()
{
    //Inicializa
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}

Texture::~Texture()
{
    //Desaloca
    free();
}


bool Texture::loadFromFile( std::string path )
{
    //apaga o que tinha antes
    free();

    //a textura que sera retornada
    SDL_Texture* newTexture = NULL;

    //carrega imagem numa surface
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //transparencia
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

        //textura a partir da surface
        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        else
        {
            //dimensoes
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }

        //libera a memoria da superficie
        SDL_FreeSurface( loadedSurface );
    }

    mTexture = newTexture;
    return mTexture != NULL;
}

void Texture::free()
{
    //libera textura se existir
    if( mTexture != NULL )
    {
        SDL_DestroyTexture( mTexture );
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void Texture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
    //O quanto da textura vai renderizar
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };

    //corte na textura (pra pegar partes da textura)
    if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    //renderiza na tela
    SDL_RenderCopyEx( renderer, mTexture, clip, &renderQuad, angle, center, flip );
}

int Texture::getWidth()
{
    return mWidth;
}

int Texture::getHeight()
{
    return mHeight;
}

bool Texture::loadFromRenderedText( std::string textureText)
{
    //Get rid of preexisting texture
    free();

    SDL_Color textColor = {255,255,255};

    SDL_Texture* newTexture = NULL;

    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid( font, textureText.c_str(), textColor );
    if( textSurface == NULL )
    {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( renderer, textSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }

        //Get rid of old surface
        SDL_FreeSurface( textSurface );
    }

    mTexture = newTexture;
    return mTexture != NULL;
}
