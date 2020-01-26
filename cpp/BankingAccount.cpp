#include "../hpp/BankingAccount.hpp"

unsigned int BankingAccount::IDCounter = BankingAccount::calculateInitialIDCounter();

std::string BankingAccount::getCurrency() {
	return this->currency;
}

void BankingAccount::setCurrency(std::string currency) {
	this->currency = currency;
}

float BankingAccount::getBalance() {
	return this->balance;
}

void BankingAccount::setBalance(float balance) {
	this->balance = balance;
}

bool BankingAccount::getIsFrozen() {
	return this->isFrozen;
}

void BankingAccount::setIsFrozen(bool isFrozen) {
	this->isFrozen = isFrozen;
}

bool BankingAccount::getIsInvestment() {
	return this->isInvestment;
}

void BankingAccount::setIsInvestment(bool isInvestment) {
	this->isInvestment = isInvestment;
}

int BankingAccount::getID() {
	return this->ID;
}

bool BankingAccount::makeTransfer() {
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
	return TransferHandler::getInstance().addTransfer(ID,idt,cash,Date(day,month,year),Date(dayp,monthp,yearp));
}

bool BankingAccount::exchangeCurrency() {
	// TODO - implement BankingAccount::exchangeCurrency
	throw "Not yet implemented";
}

bool BankingAccount::makeInvestment() {
	// TODO - implement BankingAccount::makeInvestment
	throw "Not yet implemented";
}

bool BankingAccount::takeCredit(float f) {
    loan+=f;
    balance+=f;
}

void BankingAccount::vindicate() {
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
	return TransferHandler::getInstance().addTransfer(idt,ID,cash,Date(day,month,year),Date(dayp,monthp,yearp));
}

unsigned int BankingAccount::calculateInitialIDCounter()
{
    return 0;
    /*
    std::ifstream file;
    file.open("ids.conf");
    */
    //implement
}

void BankingAccount::addMoney(float f)
{
    balance+=f;
}
