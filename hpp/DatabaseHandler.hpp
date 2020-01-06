#ifndef DATABASE_HANDLER_HPP
#define DATABASE_HANDLER_HPP

class DatabaseHandler
{
public:
    DatabaseHandler(std::vector<std::string>);
    ~DatabaseHandler();
    load()
    get();
protected:
    std::map<std::string, std::string> data;
};


#endif // DATABASE_HANDLER_HPP

