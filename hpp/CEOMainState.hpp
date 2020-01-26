#ifndef CEOSTATE_HPP
#define CEOSTATE_HPP

#include "../lib/Engine/ResourceMgrs/stateMgr/hpp/state.hpp"
#include "../lib/Engine/ResourceMgrs/cssMgr/hpp/cssMgr.hpp"
#include <iostream>
#include "../lib/Engine/Core/hpp/engine.hpp"
#include "../lib/Engine/UI/hpp/button.hpp"
#include "../lib/Engine/UI/hpp/input.hpp"
#include "BankSettings.hpp"

class CEOMainState : public State
{
public:
    CEOMainState();
    ~CEOMainState();
    void init();
    void cleanup();
    void handleEvents(sf::RenderWindow&);
    void update();
    void render(sf::RenderWindow&);
    void pause();
    void resume();
private:
    BankSettings bs;
    UI::Button* bt;
    UI::Button* bt2;
    UI::Input* inp1;
    //UI::Input* inp2;
};

#endif // STATE_HPP

