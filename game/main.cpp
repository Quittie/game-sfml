#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include <vector>
#include <iostream>
#include <string>

#include "moveable.h"
#include "game.h"


int main()
{
    std::vector<float> vec = {23, 234, 23};
    std::vector<float> vec2 = {23, 234, 23};
    Moveable test(vec, vec2);

    Moveable test2(vec, vec2);
    Game game;
    game.add(test);


    return 0;
}
