#ifndef BANKINGACCOUNT_H
#define BANKINGACCOUNT_H
#include <iostream>
#include "Date.hpp"
#include "TransferHandler.hpp"
//class TransferHandler;
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
	bool makeTransfer(unsigned int idt, float cash, Date d, Date dp);
	bool exchangeCurrency(std::string s);
	bool makeInvestment();
	bool takeLoan(float);
	bool vindicate();
    void addMoney(float);
private:
    static unsigned int calculateInitialIDCounter();
	std::string currency;
	float balance;
	bool isFrozen;
	bool isInvestment;
	float loan;
	unsigned int ID;
	static unsigned int IDCounter;

};

#endif
