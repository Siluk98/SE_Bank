#ifndef TRANSFER_H
#define TRANSFER_H
#include "Date.hpp"
#include "BankingAccount.hpp"
#include "BankingSystem.hpp"
class BankingAccount;
class BankingSystem;
class Transfer {
public:
    Transfer();
    Transfer(unsigned int f, unsigned int t, float v, Date d, Date p = Date());
	float getValue();
	void setValue(int value);
	int getFrom();
	void setFrom(int from);
	int getTo();
	void setTo(int to);
	bool getIsPeriodic();
	//void setIsPeriodic(bool isPeriodic);
	int getID();
	Date getDate();
	void setDate(Date date);
	Date getPeriod();
	void setPeriod(Date period);
	void setIsExpired(bool isExpired);
	bool getIsExpired();
	bool checkData();
	bool execute();
private:
	float value;
	unsigned int from;
	unsigned int to;
	bool isPeriodic;
	int ID;
	static int _ID;
	Date date;
	Date period;
    bool isExpired;

};

#endif
