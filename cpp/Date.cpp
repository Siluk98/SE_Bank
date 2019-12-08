#include "../hpp/Date.hpp"

int Date::getDay() {
	return this->day;
}

void Date::setDay(int day) {
	this->day = day;
}

int Date::getMonth() {
	return this->month;
}

void Date::setMonth(int month) {
	this->month = month;
}

int Date::getYear() {
	return this->year;
}

void Date::setYear(int year) {
	this->year = year;
}

Date& Date::operator+(const Date&) {
	// TODO - implement Date::operator+
	throw "Not yet implemented";
}

Date& Date::operator-(const Date&) {
	// TODO - implement Date::operator-
	throw "Not yet implemented";
}

bool Date::operator>(const Date&) const{
	// TODO - implement Date::operator>
	throw "Not yet implemented";
}

bool Date::operator<(const Date&) const{
	// TODO - implement Date::operator<
	throw "Not yet implemented";
}

bool Date::operator==(const Date&) const{
	// TODO - implement Date::operator==
	throw "Not yet implemented";
}

bool Date::operator>=(const Date&) const{
	// TODO - implement Date::operator>=
	throw "Not yet implemented";
}

bool Date::operator<=(const Date&) const{
	// TODO - implement Date::operator<=
	throw "Not yet implemented";
}

bool Date::operator!=(const Date&) const{
	// TODO - implement Date::operator!=
	throw "Not yet implemented";
}
