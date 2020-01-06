#include "../hpp/fontMgr.hpp"
#include <iostream>

fontMgr* fontMgr::instance = nullptr;

fontMgr::fontMgr(){
    instance = this;
};

fontMgr::~fontMgr(){};

sf::Font* fontMgr::loadFont(std::string name)
{
    sf::Font* font = new sf::Font;

    if(!font->loadFromFile(name))
    {
        std::cout << "Font " << name << " failed to load" << std::endl;
        font = this->loadFont("fonts/arial.ttf");
    }

    fonts.push_back(font);
    return font;
}

//Obsolete
fontMgr* fontMgr::create()
{
    if(instance == nullptr)
        return new fontMgr;
    return instance;
}

fontMgr* fontMgr::getInstance()
{
    static fontMgr* instance = new fontMgr;
    return instance;
}
