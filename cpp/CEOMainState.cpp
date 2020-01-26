#include "../hpp/CEOMainState.hpp"

CEOMainState::CEOMainState()
{
    std::cout << "CEOMainState: const" << std::endl;
}

CEOMainState::~CEOMainState()
{
    std::cout << "CEOMainState: delete" << std::endl;
    for(auto i:objects)
    {
        delete i;
    }
}

void CEOMainState::init()
{
    std::cout << "CEOMainState: init" << std::endl;
    UI::CssMgr* cssmgr = UI::CssMgr::getInstance();
    cssmgr->loadFromFile("text.css");
    UI::cssHandler* cssBt = cssmgr->getCss("#submit");
    UI::cssHandler* cssInp = cssmgr->getCss(".input");
    UI::cssHandler* cssBt2 = cssmgr->getCss("#back");

    inp1 = new UI::Input("input1", *cssInp,"fonts/arial.ttf");
    inp1->setText(std::to_string(bs.getIntrestRate()));
    bt = new UI::Button("submit", *cssBt,"Submit","gfx/empty.png","gfx/empty.png",
                                Action{[](Object* a, Object* b, std::string arg1, std::string arg2){
                                    UI::Input* inp1 = dynamic_cast<UI::Input*>(thisState->findObject("input1"));
                                    if(!inp1) std::cout << "INP NULL" << std::endl;
                                    if(inp1->getText() == "") inp1->setText("0");
                                    dynamic_cast<CEOMainState*>(thisState)->bs.setIntrestRate(std::stof(inp1->getText()));
                                }
                            });
    bt2 = new UI::Button("back", *cssBt2,"Back","gfx/empty.png","gfx/empty.png",
                                Action{[](Object* a, Object* b, std::string arg1, std::string arg2){
                                    Engine::popState();
                                }
                            });
    addObject(bt);
    addObject(bt2);
    addObject(inp1);

}

void CEOMainState::cleanup()
{
    std::cout << "CEOMainState: cleanup" << std::endl;
}

void CEOMainState::handleEvents(sf::RenderWindow& window)
{
    //std::cout << "CEOMainState: events" << std::endl;
    if(!paused)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
           {
               std::cout << "pyton" << std::endl;
               for(auto i:objects)
                {
                    std::cout <<"|"<< i->getId() <<"|"<< std::endl;
                }
           }
    }


    sf::Event event;
    while (window.pollEvent(event))
    {
        if(!paused)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                Engine::stop();
            }
            if (event.type == sf::Event::TextEntered)
            {
                std::cout << "aaaaaa" << event.text.unicode << std::endl;
                if(focus!=nullptr && focus->isOfType("textInput"))
                    if (event.text.unicode < 128)
                    {
                        dynamic_cast<UI::Input*>(focus)->sendChar(static_cast<char>(event.text.unicode));
                        std::cout << focus->getId() << std::endl;
                    }


            }
            if(event.type == sf::Event::LostFocus) pause();
        }

        if(event.type == sf::Event::GainedFocus) resume();
    }
}

void CEOMainState::pause()
{
    std::cout << "CEOMainState: pause" << std::endl;
    paused = true;
}

void CEOMainState::resume()
{
    std::cout << "CEOMainState: resume" << std::endl;
    paused = false;
}

void CEOMainState::update()
{
    if(!paused)
    {
        for(unsigned int i=0;i<objects.size();i++)
            {
                auto el = objects[i];
                if(el!=nullptr)
                {
                    el -> update();
                }
            }
    }
}

void CEOMainState::render(sf::RenderWindow& window)
{
    //std::cout << "CEOMainState: render" << std::endl;
    for(auto el : objects)
    {
        //std::cout << el << std::endl;
        if(el!=nullptr) window.draw(*el);
    }
}

