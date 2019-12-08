#ifndef BANKINGACCOUNT_H
#define BANKINGACCOUNT_H
#include <string>

class BankingAccount {

private:
	std::string currency;
	float balance;
	bool isFrozen;
	bool isInvestment;
	int ID;

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
};

#endif
