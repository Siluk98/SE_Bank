#include "../hpp/firstState.hpp"

AuthenticationState::AuthenticationState()
{
    std::cout << "AuthenticationState: const" << std::endl;
    /*
    gfxmgr = nullptr;
    eventmgr = eventMgr::getInstance();
    if(cssmgr == nullptr)
        cssmgr = new UI::cssMgr();
    audiomgr = new audioMgr();
    */
}

AuthenticationState::~AuthenticationState()
{
    std::cout << "AuthenticationState: delete" << std::endl;
    for(auto i:objects)
    {
        delete i;
    }
}

void AuthenticationState::init()
{
    std::cout << "AuthenticationState: init" << std::endl;
    //initDefaultPredicates(eventmgr);
    //eventmgr->printPredicates();
    //int a;
    //std::cin >> a;
/*
    std::cout << "Music to be loaded" << std::endl;
    audiomgr->loadMusicFromFile("sfx/elu.ogg");
    std::cout << "Music to be played" << std::endl;
    audiomgr->playMusic();
    std::cout << "Music played" << std::endl;

    addObject(new UI::Button("btNew",2,2,"","gfx/btNew.png","gfx/btNewC.png",sf::Color::White,Action{
                                     [](Object* a, Object* b, std::string arg1, std::string arg2){
                                        Game* game = Game::getGame();
                                        State* s = game->getState();
                                        //std::cout << "create new canvas" << std::endl;
                                        UI::Canvas* canvas = dynamic_cast<UI::Canvas*>(s->findObject("canvas"));
                                        canvas->clear();
                                     }}));
    addObject(new UI::Button("btLoad",36,2,"","gfx/btLoad.png","gfx/btLoadC.png",sf::Color::White,Action{
                                     [](Object* a, Object* b, std::string arg1, std::string arg2){
                                        Game* game = Game::getGame();
                                        State* s = game->getState();
                                        //std::cout << "load from ppm" << std::endl;
                                        UI::Canvas* canvas = dynamic_cast<UI::Canvas*>(s->findObject("canvas"));
                                        canvas->load("pic.png");
                                     }}));
    addObject(new UI::Button("btSave",70,2,"","gfx/btSave.png","gfx/btSaveC.png",sf::Color::White,Action{
                                     [](Object* a, Object* b, std::string arg1, std::string arg2){
                                        Game* game = Game::getGame();
                                        State* s = game->getState();
                                        //std::cout << "save as ppm" << std::endl;
                                        UI::Canvas* canvas = dynamic_cast<UI::Canvas*>(s->findObject("canvas"));
                                        canvas->save("pic.png");
                                     }}));

    addObject(new UI::Canvas("canvas", 0,100, 600,600));
    for(int i=0;i<3;i++)
    {
        std::string color="colorbt";
        std::string c="";

        addObject(new UI::Button(color+std::to_string((i*3)+1),104+(i*3+1)*34,2,c+std::to_string(i),"","",sf::Color(0,0,85*(i+1)), Action{
                                    [](Object* a, Object* b, std::string arg1, std::string arg2){
                                        UI::Button* bt = dynamic_cast<UI::Button*>(a);
                                        Game* game = Game::getGame();
                                        State* s = game->getState();
                                        UI::Canvas* canvas = dynamic_cast<UI::Canvas*>(s->findObject("canvas"));
                                        std::cout << bt->getText();
                                        canvas->setColor(0,0,85*(std::stoi(bt->getText())+1));
                                        }}));
        addObject(new UI::Button(color+std::to_string((i*3)+2),104+(i*3+2)*34,2,c+std::to_string(i),"","",sf::Color(0,85*(i+1),0), Action{
                                    [](Object* a, Object* b, std::string arg1, std::string arg2){
                                        UI::Button* bt = dynamic_cast<UI::Button*>(a);
                                        Game* game = Game::getGame();
                                        State* s = game->getState();
                                        UI::Canvas* canvas = dynamic_cast<UI::Canvas*>(s->findObject("canvas"));
                                        std::cout << bt->getText();
                                        canvas->setColor(0,85*(std::stoi(bt->getText())+1),0);
                                        }}));
        addObject(new UI::Button(color+std::to_string(i*3),104+(i*3)*34,2,c+std::to_string(i),"","",sf::Color(85*(i+1),0,0), Action{
                                    [](Object* a, Object* b, std::string arg1, std::string arg2){
                                        UI::Button* bt = dynamic_cast<UI::Button*>(a);
                                        Game* game = Game::getGame();
                                        State* s = game->getState();
                                        UI::Canvas* canvas = dynamic_cast<UI::Canvas*>(s->findObject("canvas"));
                                        std::cout << bt->getText();
                                        canvas->setColor(85*(std::stoi(bt->getText())+1),0,0);
                                        }}));
    }

    addObject(new UI::Button("brushUp",550,2,"","gfx/btBrushUp.png","gfx/btBrushUp.png",sf::Color::White,Action{
                                [](Object* a, Object* b, std::string arg1, std::string arg2){
                                    Game* game = Game::getGame();
                                    State* s = game->getState();
                                    UI::Canvas* canvas = dynamic_cast<UI::Canvas*>(s->findObject("canvas"));
                                    canvas->brushUp();
                                }
                             }));

    addObject(new UI::Button("brushDown",550,36,"","gfx/btBrushDown.png","gfx/btBrushDown.png",sf::Color::White,Action{
                                [](Object* a, Object* b, std::string arg1, std::string arg2){
                                    Game* game = Game::getGame();
                                    State* s = game->getState();
                                    UI::Canvas* canvas = dynamic_cast<UI::Canvas*>(s->findObject("canvas"));
                                    canvas->brushDown();
                                }
                             }));
*/
    UI::CssMgr* cssmgr = UI::CssMgr::getInstance();
    cssmgr->loadFromFile("text.css");
    UI::cssHandler* cssBt = cssmgr->getCss("#submit");
    UI::cssHandler* cssInp = cssmgr->getCss(".input");
    UI::cssHandler* cssInp2 = cssmgr->getCss("#input2");
    std::cout << "BT --------------" << std::endl;
    cssBt->print();
    std::cout << "INP --------------" << std::endl;
    cssInp->print();
    std::cout << "INP2 --------------" << std::endl;
    cssInp2->print();
    std::cout << "FIN --------------" << std::endl;

    inp1 = new UI::Input("input1", *cssInp,"fonts/arial.ttf");
    inp2 = new UI::Input("input2", *cssInp,"fonts/arial.ttf");
    inp2->applyStyle(*cssInp2);
    bt = new UI::Button("submit", *cssBt,"Submit","gfx/empty.png","gfx/empty.png",
                                Action{[](Object* a, Object* b, std::string arg1, std::string arg2){
                                    UI::Input* inp1 = dynamic_cast<UI::Input*>(thisState->findObject("input1"));
                                    UI::Input* inp2 = dynamic_cast<UI::Input*>(thisState->findObject("input2"));
                                    if(!inp1 || !inp2) std::cout << "INP NULL" << std::endl;
                                    AuthenticationState* ts = dynamic_cast<AuthenticationState*>(thisState);
                                    if(ts->auth.authenticate(inp1->getText(),inp2->getText()))
                                    {
                                        //if(ts->auth)
                                        Engine::pushState(new CEOMainState,&(ts->auth));
                                        //Engine::pushState(new AuthenticationState,&(ts->auth));

                                    }
                                    else
                                    {
                                        std::cout << "Credentials error" << std::endl;
                                    }
                                }
                            });
    addObject(inp2);
    addObject(bt);
    addObject(inp1);

}

void AuthenticationState::cleanup()
{
    std::cout << "AuthenticationState: cleanup" << std::endl;
}

void AuthenticationState::handleEvents(sf::RenderWindow& window)
{
    //std::cout << "AuthenticationState: events" << std::endl;
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
        /*
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
           {
               std::cout << "POP" << std::endl;
               Engine::popState();
           }
        */
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

void AuthenticationState::pause()
{
    std::cout << "AuthenticationState: pause" << std::endl;
    paused = true;
}

void AuthenticationState::resume()
{
    std::cout << "AuthenticationState: resume" << std::endl;
    paused = false;
}

void AuthenticationState::update()
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

void AuthenticationState::render(sf::RenderWindow& window)
{
    //std::cout << "AuthenticationState: render" << std::endl;
    for(auto el : objects)
    {
        //std::cout << el << std::endl;
        if(el!=nullptr) window.draw(*el);
    }
}
