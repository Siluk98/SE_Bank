#ifndef TRANSFER_H
#define TRANSFER_H
#include "Date.hpp"
class Transfer {

private:
	float value;
	int from;
	int to;
	bool isPeriodic;
	int ID;
	Date date;
	Date period;

public:
	float getValue();
	void setValue(int value);
	int getFrom();
	void setFrom(int from);
	int getTo();
	void setTo(int to);
	bool getIsPeriodic();
	void setIsPeriodic(bool isPeriodic);
	int getID();
	Date getDate();
	void setDate(Date date);
	Date getPeriod();
	void setPeriod(Date period);
};

#endif
