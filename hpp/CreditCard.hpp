#ifndef CREDITCARD_H
#define CREDITCARD_H
#include <string>
#include <fstream>
#include <iostream>
class CreditCard {

private:
	int ID;
	bool isRestricted;
	std::string securityCode;
	std::string pin;

public:
	void getID();
	bool getIsRestricted();
	void setIsRestricted(bool isRestricted);
	std::string getSecurityCode();
	void setSecurityCode(std::string securityCode);
	std::string getPin();
	void setPin(std::string pin);
	void restict();
};

#endif
