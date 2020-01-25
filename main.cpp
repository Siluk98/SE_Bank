#include <iostream>
#include "lib/Engine/Core/hpp/engine.hpp"
#include "hpp/firstState.hpp"

int main()
{
    Engine engine;
    engine.pushState(new AuthenticationState);
    engine.run();
    return 0;
}
