#ifndef FSTATE_HPP
#define FSTATE_HPP

#include "../lib/Engine/hpp/state.hpp"
#include "../lib/UI/hpp/CSSMGR.HPP"

class AuthenticationState : public State
{
public:
    AuthenticationState(gfxMgr*, eventMgr*, audioMgr*);
    AuthenticationState();
    ~AuthenticationState();
    void init();
    void cleanup();
    void handleEvents(sf::RenderWindow*);
    void update();
    void render(sf::RenderWindow*);
    void pause();
    void resume();
private:
    UI::cssMgr* cssmgr;
};

#endif // STATE_HPP

