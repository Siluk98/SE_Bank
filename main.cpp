#include <iostream>
#include "lib/Engine/Core/hpp/engine.hpp"
#include "hpp/firstState.hpp"
#include "hpp/AuthenticationSystem.hpp"
//#include "hpp/CEOMainState.hpp"

BankingAccount* chooseAccount(SystemAccount* sa)
{
    BankingAccount* ret =nullptr;
    std::vector<BankingAccount*> al = sa.getAccountList();
    if(al.size()==0)
    {
        std::cout << "You dont have an account" << std::endl;
        return nullptr;
    }
    std::cout << "Choose an account: ";
    int acn=0;
    for(auto i:al)
    {
       std::cout << " " << i->getID();
    }
    std::cin >> acn;
    ret = sa.getAccount(acn);
    return ret;

}

int main()
{
    //Engine engine;
    //engine.pushState(new AuthenticationState);
    //engine.pushState(new CEOMainState);
    //engine.run();

    BankingSystem* bank BankingSystem::getInstance();
    AuthenticationSystem auths;
    SystemAccount* sa;
    bool isRunning;
    if(auths.authenticate("login3", "haslo3"));
    {
        while(isRunning)
        {
            sa = auths.getAccount();
            std::cout << "1.Trasfer money" << std::endl
                    << "2.Exchange currency" << std::endl
                    << "3.Make Investment" << std::endl
                    << "4.Take loan" << std::endl
                    << "5.Add account" << std::endl;
            if(sa.getIsVindicator())
                std::cout << "6.Vindicate" << std::endl;
            if(sa.isAdmin())
            {
                std::cout << "7.Set intrest rates" << std::endl;
            }
            std::cout << "0.Exit" << std::endl;

            int ch = 1;
            std::cin >> ch

            switch(ch)
            {
                case 1:
                {

                }
                case 2:
                {

                }
                case 3:
                {

                }
                case 4:
                {

                }
                case 5:
                {
                    BankingAccount* b= new BankingAccount;
                    std::cout << "Your new account has ID: " << b->getID() << std::endl;
                    std::cout << "Set currency: ";
                    std::string cur;
                    std::cin >> cur;
                    b->setCurrency(cur);
                    b->setIsFrozen(false);
                    b->setIsInvestment(false);
                    sa.addAccount(b);
                }
                case 6:
                {

                }
                case 7:
                {

                }
                case 8:
                {

                }
                case 0:
                {
                    isRunning = false;
                    break;
                }
                default:{}
            }
        }
    }


    return 0;
}
