#include "../hpp/BankingSystem.hpp"

BankingSystem::BankingSystem()
{
    currInit();
}

void BankingSystem::currInit()
{
    curr["pln"] = 1;
    curr["eur"] = 0.23;
    curr["fr"] = 0.25;
    curr["usd"] = 0.26;
    curr["jpn"] = 28.57;
    curr["rup"] = 16.66;
}

SystemAccount* BankingSystem::getAccount(std::string s)
{
 return nullptr;
}

float BankingSystem::getCurrency(std::string s)
{
    return curr[s];
}

float BankingSystem::calculateCurrencyFactor(std::string f, std::string t)
{
    if(curr[f]==0 && curr[t] == 0) return 0;
    return curr[t]/curr[f];
}

std::shared_ptr<BankingAccount> BankingSystem::getAccount(unsigned int id)
{
    //if(accounts.find(id) != )
    return accounts[id];
}

bool BankingSystem::makeTransfer(std::shared_ptr<Transfer> arg)
{
    std::shared_ptr<BankingAccount> f = getAccount(arg->getFrom());
    std::shared_ptr<BankingAccount> t = getAccount(arg->getTo());
    if(f==nullptr || t == nullptr) return false;
    float factor = 1;
    if(f->getCurrency() != t->getCurrency()) factor = calculateCurrencyFactor(f->getCurrency(),t->getCurrency());
    f->addMoney(-1*arg->getValue());
    t->addMoney(arg->getValue()*factor);
    if(!(arg->getIsPeriodic())) arg->setIsExpired(true);
    else arg->setDate(arg->getDate()+arg->getPeriod());
    return true;
}

BankingSystem* BankingSystem::getInstance()
{
    static BankingSystem* b = new BankingSystem;
    return b;
}
