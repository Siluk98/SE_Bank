#include "../hpp/range.hpp"
#include "../hpp/cssHandler.hpp"
#include <iostream>
#include "../../Engine/hpp/state.hpp"
#include "../../Engine/hpp/game.hpp"
#include "../../Engine/hpp/event.hpp"

UI::Range::Range(std::string id, cssHandler& css)
{

}

UI::Range::Range(std::string id, cssHandler* css)
{

}

UI::Range::~Range()
{

}

void UI::Range::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(*field);
    target.draw(*slider);
}

void UI::Range::update()
{

}

std::string UI::Range::create(std::string obj, std::string params)
{
    return "What's that?";
}

void UI::Range::changeStyle(std::string atr, std::string val)
{

}
