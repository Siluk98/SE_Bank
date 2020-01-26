#ifndef FSTATE_HPP
#define FSTATE_HPP

#include "../lib/Engine/ResourceMgrs/stateMgr/hpp/state.hpp"
#include "../lib/Engine/ResourceMgrs/cssMgr/hpp/cssMgr.hpp"
#include <iostream>
#include "../lib/Engine/Core/hpp/engine.hpp"
#include "../lib/Engine/UI/hpp/button.hpp"
#include "../lib/Engine/UI/hpp/canvas.hpp"
#include "../lib/Engine/UI/hpp/input.hpp"
#include "AuthenticationSystem.hpp"
#include "CEOMainState.hpp"

class AuthenticationState : public State
{
public:
    AuthenticationState();
    ~AuthenticationState();
    void init();
    void cleanup();
    void handleEvents(sf::RenderWindow&);
    void update();
    void render(sf::RenderWindow&);
    void pause();
    void resume();
private:
    AuthenticationSystem auth;
    UI::Button* bt;
    UI::Input* inp1;
    UI::Input* inp2;
};

#endif // STATE_HPP

