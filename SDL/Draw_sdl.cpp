#include "../include/SDL_menu.hpp"
//Screen dimension constants

int main(int argc, char *args[])
{
    MenuGraphics * graph = new MenuGraphics();
    graph->start_menu();
    graph->close();

    return 0;
}
