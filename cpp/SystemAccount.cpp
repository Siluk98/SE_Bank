#include "../hpp/SystemAccount.hpp"

std::string SystemAccount::getLogin() {
	// TODO - implement SystemAccount::getLogin
	throw "Not yet implemented";
}

/*
void SystemAccount::setLogin(std::string Login) {
	// TODO - implement SystemAccount::setLogin
	throw "Not yet implemented";
}
*/

std::string SystemAccount::getPassword() {
	// TODO - implement SystemAccount::getPassword
	throw "Not yet implemented";
}

void SystemAccount::setPassword(std::string Password) {
	// TODO - implement SystemAccount::setPassword
	throw "Not yet implemented";
}

void SystemAccount::getAccountList() {
	// TODO - implement SystemAccount::getAccountList
	throw "Not yet implemented";
}

void SystemAccount::setAccountList(std::vector<BankingAccount*> AccountList) {
	// TODO - implement SystemAccount::setAccountList
	throw "Not yet implemented";
}

void SystemAccount::getID() {
	// TODO - implement SystemAccount::getID
	throw "Not yet implemented";
}


void SystemAccount::addAccount() {
	// TODO - implement SystemAccount::addAccount
	throw "Not yet implemented";
}

void SystemAccount::removeAccount() {
	// TODO - implement SystemAccount::removeAccount
	throw "Not yet implemented";
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
