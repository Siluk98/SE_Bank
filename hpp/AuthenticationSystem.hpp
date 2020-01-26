#ifndef AUTHENTICATIONSYSTEM_H
#define AUTHENTICATIONSYSTEM_H
#include <sstream>
#include <vector>
#include <iostream>
#include <SFML/Network.hpp>
#include "PersonalData.hpp"
#include "BankingSystem.hpp"

enum PrivilageLevel {User=0,Admin,CEO};

struct AuthToken
{
    PersonalData pd;
    PrivilageLevel priv;
    std::string login;
};

class AuthenticationSystem {
public:
    AuthenticationSystem();
    bool authenticate(std::string login, std::string password);
    SystemAccount* getAccount();
private:
    static std::string domain;
    static std::string page;
    AuthToken authToken;
};

#endif
