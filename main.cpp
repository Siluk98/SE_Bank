#include "lib/Engine/hpp/game.hpp"
#include <iostream>
#include "hpp/firstState.hpp"

int main()
{
    Game game;
    game.pushState(new AuthenticationState);
    game.run();
    return 0;
}
