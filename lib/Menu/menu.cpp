#include "menu.hpp"

Menu::Menu(std::string _id)
:id(_id)
,value(0)
,title("")
{}

Menu::Menu(std::string _id, std::initializer_list<std::string> args)
:id(_id)
,title("")
{
    int c=0;
    for(auto i=args.begin();i!=args.end();i++)
    {
        options[c]=*i;
        c++;
    }
    value = options.begin()->first;
}

Menu::~Menu(){}

void Menu::addOption(std::string s, int i)
{
    options[i]=s;
}

static char checked(int a, int b)
{
    return (a==b)?'x':' ';
}

int Menu::waitForInput()
{
    char c = 0;
    do
    {

        #ifndef NO_WINAPI
        system("cls");
        #endif // NO_WINAPI

        if(c==13) break;

        if(c==']')
        {
            auto ptr = options.find(value);
            if(++ptr == options.end()) ptr = options.begin();
            value = ptr->first;
        }

        if(c=='[')
        {
            auto ptr = options.find(value);
            if(ptr == options.begin()) ptr = options.end();
            ptr--;
            value = ptr->first;
        }

        std::cout << title << std::endl;
        for(std::pair<int, std::string> el : options)
        {
            std::cout << '['<<checked(el.first,value)<<']'<<el.second << std::endl;
        }
        c=getch();
        //std::cout << "c" << (int)c << std::endl;
    }
    while(true);
    return value;
}

void Menu::addTitle(std::string _title)
{
    title = _title;
}

int Menu::getValue()
{
    return value;
}

std::string Menu::getId()
{
    return id;
}


