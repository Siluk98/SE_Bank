#include "../hpp/SystemAccount.hpp"

std::string SystemAccount::getLogin() {
	return login;
}

/*
void SystemAccount::setLogin(std::string Login) {
	// TODO - implement SystemAccount::setLogin
	throw "Not yet implemented";
}
*/

std::string SystemAccount::getPassword() {
	return password;
}

void SystemAccount::setPassword(std::string Password) {
	password = Password;
}

std::vector<BankingAccount*>& SystemAccount::getAccountList() {
	return accountList;
}

void SystemAccount::setAccountList(std::vector<BankingAccount*>& AccountList) {
	accountList = AccountList;
}

unsigned int SystemAccount::getID() {
	return ID;
}


void SystemAccount::addAccount(BankingAccount* b) {
	accountList.push_back(b);
}


BankingAccount* SystemAccount::getAccount(int k) {
    for(int i=0;i<accountList.size();i++)
    {
        if(accountList[i]->getID()==k) return accountList[i];
    }
    return nullptr;
}


bool SystemAccount::getIsAdmin() {
	return this->isAdmin;
}

void SystemAccount::setIsAdmin(bool isAdmin) {
	this->isAdmin = isAdmin;
}

bool SystemAccount::getIsVindicator() {
	return this->isVindicator;
}

void SystemAccount::setIsVindicator(bool isVindicator) {
	this->isVindicator = isVindicator;
}
