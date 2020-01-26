#ifndef SYSTEMACCOUNT_H
#define SYSTEMACCOUNT_H
#include <string>
#include <vector>
#include "BankingAccount.hpp"
class SystemAccount {
public:
	std::string getLogin();
	//void setLogin(std::string Login);
	std::string getPassword();
	void setPassword(std::string Password);
	std::vector<BankingAccount*>& getAccountList();
	void setAccountList(std::vector<BankingAccount*>& AccountList);
	unsigned int getID();
	void addAccount(BankingAccount* );
	BankingAccount* getAccount(int i);
	//void removeAccount();
	bool getIsAdmin();
	void setIsAdmin(bool isAdmin);
	bool getIsVindicator();
	void setIsVindicator(bool isVindicator);

private:
	std::string login;
	std::string password;
    std::vector<BankingAccount*> accountList;
	unsigned int ID;
	static unsigned int ID_counter;
	bool isAdmin;
	bool isVindicator;
};

#endif
