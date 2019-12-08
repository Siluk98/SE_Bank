#ifndef DATE_H
#define DATE_H

class Date {

private:
	int day;
	int month;
	int year;

public:
	int getDay();
	void setDay(int day);
	int getMonth();
	void setMonth(int month);
	int getYear();
	void setYear(int year);
	Date& operator+(const Date&);
	Date& operator-(const Date&);
	bool operator>(const Date&) const;
	bool operator<(const Date&) const;
	bool operator==(const Date&) const;
	bool operator>=(const Date&) const;
	bool operator<=(const Date&) const;
	bool operator!=(const Date&) const;
};

#endif
