#ifndef HTML_INTERPRETER_HPP
#define HTML_INTERPRETER_HPP

#include "object.hpp"

class htmlInterpreter
{
public:
    htmlInterpreter();
    ~htmlInterpreter();
    void loadFromFile(std::string filename);
    void loadFromString(std::string text);
private:
    Object* structure;
    Object* construct(std::string taglist, Object* parent);
    Object* parse(std::string tag, std::string& tl);
};

#endif
