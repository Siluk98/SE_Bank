#include "../hpp/htmlInterpreter.hpp"
#include <fstream>
#include <iostream>
#include "../../UI/hpp/ui.hpp"

htmlInterpreter::htmlInterpreter(){};
htmlInterpreter::~htmlInterpreter(){};

void htmlInterpreter::loadFromFile(std::string fname)
{
    std::ifstream f;
    f.open(fname);
    if(f.good())
    {
        std::string ret{};
        std::string temp;
        while(!f.eof())
        {
            std::getline(f, temp);
            ret += temp;
        }
        structure = construct(ret, nullptr);
    }
    else
    {
        //throw
    }
}

void htmlInterpreter::loadFromString(std::string text)
{
    structure = construct(text, nullptr);
}

Object* htmlInterpreter::construct(std::string taglist, Object* parent)
{
    if(parent==nullptr)
    {
        //parent = createContainer();
    }
    auto sp = taglist.find('<');
    auto ep = taglist.find('>');
    while(sp!=std::string::npos && ep!=std::string::npos)
    {
        std::string tag = taglist.substr(sp,ep+1);
        std::cout << "tag: " << tag << std::endl;
        taglist = taglist.substr(ep+1);
        std::cout << "taglist: " << taglist << std::endl;
        Object* obj = parse(tag, taglist);
        if(obj->isContainer())
        {
            std::string closingTag="";//generateClosingTag(tag);
            auto closePos = taglist.find(closingTag);
            std::string subtaglist = taglist.substr(0,closePos);
            construct(subtaglist,obj);
        }

        parent->addChild(obj);

        sp = taglist.find('<');
        ep = taglist.find('>');
    }
    return parent;
}

Object* htmlInterpreter::parse(std::string tag, std::string& tl)
{
    Object* parsed;
    if(tag.find("button"))
    {
        parsed = new UI::Button();
    }
    else if(tag.find("canvas"))
    {
        parsed = new UI::Canvas();
    }
    else
    {
        //parsed = new Object;
    }


    //ui objects returned as object*
    //object type defined for future cast
    //as well as containerity
    return parsed;
}
