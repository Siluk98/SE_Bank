#include "../hpp/input.hpp"
#include "../../ResourceMgrs/cssMgr/hpp/cssHandler.hpp"
#include "../../ResourceMgrs/fontMgr/hpp/fontMgr.hpp"
#include <iostream>
#include "../../ResourceMgrs/stateMgr/hpp/state.hpp"
#include "../../Core/hpp/engine.hpp"
#include "../../ResourceMgrs/eventMgr/hpp/event.hpp"

UI::Input::Input(std::string _id, cssHandler& css, std::string f="fonts/arial.ttf"){
    std::cout << _id << std::endl;
    id = _id;
    std::cout << id << std::endl;
    focus = false;
    caretVisible = true;
    addType("textInput");
    container = true;
    posx = 0;
    posy = 50;
    width = 100;
    height = 20;
    sprite = nullptr;
    caretCounter = 0;
    caretMax = 60;
    field = new sf::RectangleShape(sf::Vector2f{128,32});
    field->setFillColor(sf::Color::White);
    field->setPosition(sf::Vector2f{posx,posy});
    caret = new sf::RectangleShape(sf::Vector2f{1,28});
    caret->setPosition(posx+1,posy+1);
    caretColor = new sf::Color(0,0,0,255);
    caret->setFillColor(*caretColor);
    hitbox = new sf::IntRect(posx+1,posy+1,128,32);
    text = new sf::Text;

    font = FontMgr::getInstance()->loadFont(f);

    text->setFont(*font);
    text->setCharacterSize(28);
    text->setFillColor(sf::Color::Black);
    text->setPosition(posx+1,posy);
    applyStyle(css);
    addEvent("MouseDown", Action{[](Object* a, Object* b, std::string arg1, std::string arg2){
                    UI::Input *c = dynamic_cast<UI::Input*>(a);
                    c->focus = true;
                    State* s = Engine::getState();
                    s->setFocus(c);
                    std::cout << "Focus" << std::endl;
             }});

    addEvent("MouseOut", Action{[](Object* a, Object* b, std::string arg1, std::string arg2){
                    UI::Input* c = dynamic_cast<UI::Input*>(a);
                    c->focus = false;
                    if(c->caretVisible) c->caretBlink();
                    std::cout << "Out of focus" << std::endl;
             }});
}
UI::Input::~Input(){
    delete text;
    delete field;
    delete caret;
    //delete font; // dangling pointer
}

void UI::Input::update()
{
    for(unsigned int i=0;i<events.size();i++)
    {
        events[i]->handle(this,nullptr,"","");
    }
    //updateTexture(*sprite);
    if(focus)
    {
        caretCounter++;
        if(caretCounter>=caretMax)
        {
            caretCounter = 0;
            caretBlink();
        }
    }
}

void UI::Input::caretBlink()
{
    std::cout << "blink" << std::endl;
    if(caretVisible)
        caretColor->a = 0;
    else
        caretColor->a = 255;
    caret->setFillColor(*caretColor);
    caretVisible = !caretVisible;
}

void UI::Input::draw(sf::RenderTarget &target, sf::RenderStates s) const
{
    target.draw(*field);
    target.draw(*text);
    target.draw(*caret);
}


void UI::Input::changeStyle(std::string atr, std::string val)
{
    try
    {
        if(val == "") return;
        std::cout << id << ": |" << atr << "|: |" << val <<"|" <<std::endl;

        if(atr == "width")
        {
            width = std::stoi(val);
            hitbox->width = width;
            field->setSize(sf::Vector2f(width,height));
        }
        if(atr == "height")
        {
            height = std::stoi(val);
            hitbox->height = height;
            caret->setSize(sf::Vector2f(1,height));
            field->setSize(sf::Vector2f(width,height));
        }
        if(atr == "top")
        {
            posy = std::stoi(val);
            std::cout << posx << " " << posy << std::endl;
            field->setPosition(posx,posy);
            hitbox->top = posy;
            caret->setPosition(posx+1,posy+1);
            text->setPosition(posx+1,posy);
        }
        if(atr == "left")
        {
            posx = std::stoi(val);
            std::cout << posx << " " << posy << std::endl;
            field->setPosition(posx,posy);
            hitbox->left = posx;
            caret->setPosition(posx+1,posy+1);
            text->setPosition(posx+1,posy);
        }
        if(atr == "color")
        {

        }
    }
    catch(...)
    {
        std::cout << "Broken css" << std::endl;
    }
}

std::string UI::Input::create(std::string obj, std::string params){return id;};

void UI::Input::sendChar(char c)
{
    if(c<=31){
        if(c==8 && !value.empty())
            value.pop_back();
    }
    else
        value.push_back(c);
    std::cout << "value: " << value << std::endl;
    updateText();
}

void UI::Input::updateText()
{
    text->setString(value);
}

std::string UI::Input::getText()
{
    return value;
}

void UI::Input::setText(std::string arg)
{
    value = arg;
    updateText();
}
