#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
public:
    Date();
    Date(int d, int m, int y);
    std::string getString();
	int getDay();
	void setDay(int day);
	int getMonth();
	void setMonth(int month);
	int getYear();
	void setYear(int year);
	Date& add(int d, int m, int y);
	Date operator+(const Date&) const;
	Date operator-(const Date&) const;
	bool operator>(const Date&) const;
	bool operator<(const Date&) const;
	bool operator==(const Date&) const;
	bool operator>=(const Date&) const;
	bool operator<=(const Date&) const;
	bool operator!=(const Date&) const;
private:
	int day;
	int month;
	int year;

};

#endif
