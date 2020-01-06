#ifndef BANKINGACCOUNT_H
#define BANKINGACCOUNT_H
#include <iostream>
//#include "TransferHandler.hpp"
class TransferHandler;
class BankingAccount {
public:
	std::string getCurrency();
	void setCurrency(std::string currency);
	float getBalance();
	void setBalance(float balance);
	bool getIsFrozen();
	void setIsFrozen(bool isFrozen);
	bool getIsInvestment();
	void setIsInvestment(bool isInvestment);
	int getID();
	bool makeTransfer();
	bool exchangeCurrency();
	bool makeInvestment();
	bool takeCredit();
	void vindicate();
    void addMoney(float);
private:
    static unsigned int calculateInitialIDCounter();
	std::string currency;
	float balance;
	bool isFrozen;
	bool isInvestment;
	unsigned int ID;
	static unsigned int IDCounter;

};

#endif
