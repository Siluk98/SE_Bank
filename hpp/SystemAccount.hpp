#ifndef SYSTEMACCOUNT_H
#define SYSTEMACCOUNT_H
#include <string>
#include <vector>
#include "BankingAccount.hpp"
class SystemAccount {

private:
	std::string login;
	std::string password;

	int ID;
	bool isAdmin;
	bool isVindicator;

public:
	std::string getLogin();
	void setLogin(std::string Login);
	std::string getPassword();
	void setPassword(std::string Password);
	void getAccountList();
	void setAccountList(std::vector<BankingAccount*> AccountList);
	void getID();
	void addAccount();
	void removeAccount();
	bool getIsAdmin();
	void setIsAdmin(bool isAdmin);
	bool getIsVindicator();
	void setIsVindicator(bool isVindicator);
};

#endif
