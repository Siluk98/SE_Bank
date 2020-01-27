#include <iostream>
#include "lib/Engine/Core/hpp/engine.hpp"
#include "hpp/firstState.hpp"
#include "hpp/AuthenticationSystem.hpp"
//#include "hpp/CEOMainState.hpp"

bool makeTransfer(BankingAccount* ba)
{
    std::cout << "Insert target's ID number: ";
	unsigned int idt;
	std::cin >> idt;
	float cash;
	do{
        std::cin >> cash;
        std::cout << "insert cash: ";
	}while(cash<0);
	int day,month, year;
	std::cout << "Insert date(day): ";
	std::cin >> day;
	std::cout << "Insert date(month): ";
	std::cin >> month;
	std::cout << "Insert date(year): ";
	std::cin >> year;
	int dayp,monthp, yearp;
	std::cout << "Insert period(day): ";
	std::cin >> dayp;
	std::cout << "Insert period(month): ";
	std::cin >> monthp;
	std::cout << "Insert period(year): ";
	std::cin >> yearp;
	return ba->makeTransfer(idt,cash, Date(day,month,year), Date(dayp,monthp,yearp));
}


bool vindicate(BankingAccount* ba)
{
    std::cout << "Insert target's ID number: ";
	unsigned int idt;
	std::cin >> idt;
	float cash;
	do{
        std::cin >> cash;
        std::cout << "insert cash: ";
	}while(cash<0);
	return ba->makeTransfer(idt,cash, Date(0,0,0), Date(0,0,0));
}

BankingAccount* chooseAccount(SystemAccount* sa)
{
    BankingAccount* ret =nullptr;
    std::vector<BankingAccount*> al = sa->getAccountList();
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
    std::cout << std::endl;
    std::cin >> acn;
    ret = sa->getAccount(acn);
    return ret;

}

int main()
{
    Engine engine;
    engine.pushState(new AuthenticationState);
    //engine.pushState(new CEOMainState);
    engine.run();


    /*
    BankingSystem* bank = BankingSystem::getInstance();
    BankSettings bs;
    AuthenticationSystem auths;
    SystemAccount* sa;
    bool isRunning = true;
    std::string login,password;
    std::cout << "Insert login: ";
    std::cin >> login;
    std::cout << "Insert password: ";
    std::cin >> password;
    while(!auths.authenticate(login, password))
    {
        std::cout << "Credentials Error" << std::endl;
        std::cout << "Insert login: ";
        std::cin >> login;
        std::cout << "Insert password: ";
        std::cin >> password;
    }
    sa = bank->getAccount(auths.getAuth().login);
    if(sa==nullptr)
    {
        sa = new SystemAccount(login, password);
        sa->setIsAdmin(true);
        sa->setIsVindicator(true);
    }

    while(isRunning)
    {

        std::cout << "1.Trasfer money" << std::endl
                << "2.Exchange currency" << std::endl
                << "3.Make Investment" << std::endl
                << "4.Take loan" << std::endl
                << "5.Add account" << std::endl;
        if(sa->getIsVindicator())
            std::cout << "6.Vindicate" << std::endl;
        if(sa->getIsAdmin())
        {
            std::cout << "7.Set intrest rates" << std::endl;
        }
        std::cout << "0.Exit" << std::endl;

        int ch = 1;
        std::cin >> ch;

        switch(ch)
        {
            case 1:
            {
                BankingAccount* ba = nullptr;
                while(ba == nullptr)
                {
                    chooseAccount(sa);
                }
                makeTransfer(ba);
                break;
            }
            case 2:
            {
                BankingAccount* ba = nullptr;
                while(ba == nullptr)
                {
                    chooseAccount(sa);
                }
                std::cout << "Set currency: ";
                std::string cur;
                std::cin >> cur;
                if(ba->exchangeCurrency(cur))
                {
                    std::cout << "OK" << std::endl;
                }
                else
                {
                    std::cout << "Wrong currency" << std::endl;
                }
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                BankingAccount* ba = nullptr;
                while(ba == nullptr)
                {
                    chooseAccount(sa);
                }
                float cash;
                do{
                    std::cin >> cash;
                    std::cout << "insert cash: ";
                }while(cash<0);
                ba->takeLoan(cash);
                break;
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
                sa->addAccount(b);
                break;
            }
            case 6:
            {
                if(sa->getIsVindicator())
                {
                    BankingAccount* ba = nullptr;
                    while(ba == nullptr)
                    {
                        chooseAccount(sa);
                    }
                    vindicate(ba);
                }
                break;
            }
            case 7:
            {
                if(sa->getIsAdmin())
                {
                    std::cout << "Insert intrest rate: ";
                    float ir;
                    std::cin >> ir;
                    bs.setIntrestRate(ir);
                }
                break;
            }
            case 0:
            {
                isRunning = false;
                break;
            }
            default:{}
        }
    }

*/
    return 0;
}
