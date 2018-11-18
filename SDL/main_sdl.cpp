#include "../include/Game.hpp"
#include "../include/Graphics.hpp"

int main(int argc, char *args[])
{
    Graphics *graphics = new Graphics();
    Game *game = new Game();

	if( !graphics->init() ){
		printf( "Falha ao inicializar!\n" );
	}
	else{
		//Carrega mídia
		if( !graphics->loadMedia() ){
			printf( "Nao foi possivel carregar a midia!\n" );
		}
		else{
            game->playGame(GAME_MENU);
    	}
        graphics->close();;
    }

    return 0;
}
