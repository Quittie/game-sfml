#include "moveable.h"
#include "game.h"

int main()
{

    Game game;

    bool keyPressed = true;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    while(game.running())
    {
        game.update(keyPressed);
        game.render();

    }
    return 0;
}


