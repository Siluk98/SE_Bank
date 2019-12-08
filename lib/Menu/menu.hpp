#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <initializer_list>
#include <map>
#include <conio.h>

#ifndef NO_WINAPI
#include <windows.h>
#endif // NO_WINAPI

class Menu
{
public:
    Menu(std::string);
    Menu(std::string,std::initializer_list<std::string>);
    ~Menu();
    int getValue();
    std::string getId();
    int waitForInput();
    void addOption(std::string, int);
    void addTitle(std::string);
protected:
    const std::string id;
    int value;
    std::string title;
    std::map<int, std::string> options;
};


#endif // MENU_HPP
