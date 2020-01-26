#ifndef BANKING_SYSTEM_HPP
#define BANKING_SYSTEM_HPP
#include <memory>
#include <map>
#include "BankingAccount.hpp"
#include "Transfer.hpp"
class BankingAccount;
class BankingSystem
{
public:
    static BankingSystem* getInstance();
    ~BankingSystem();
    std::shared_ptr<BankingAccount> getAccount(unsigned int id);
    float calculateCurrencyFactor(std::string f, std::string t);
    bool makeTransfer(std::shared_ptr<Transfer> t);
    void currInit();
private:
    BankingSystem();
    std::map<unsigned int,std::shared_ptr<BankingAccount>> accounts;
    std::map<std::string, float> curr;
};


#endif // BANKING_SYSTEM_HPP
