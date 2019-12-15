#include "../hpp/Date.hpp"

Date::Date()
:day(0)
,month(0)
,year(0)
{}

Date::Date(int d, int m, int y)
:day(d)
,month(m)
,year(y)
{
    add(0,0,0);
}

static std::string add_zero(int arg)
{
    return (arg>=10|| arg<=-10)?std::to_string(arg):std::string("0")+std::to_string(arg);
}

std::string Date::getString()
{
    std::string s("");
    s+=add_zero(day);
    s+=".";
    s+=add_zero(month);
    s+=".";
    s+=add_zero(year);
    return s;
}

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

int getNumberOfDays(int m)
{
    return 30; //TODO: zaimplementowac
}

Date& Date::add(int d, int m int y)
{
    day+=d;
    month+=m;
    year+=y;
    for(int i=0;i<2;i++){
    while(day>getNumberOfDays(month))
    {
        day-=getNumberOfDays(month);
        month++;
    }
    while(month>12)
    {
        year++;
        month-=12;
    }
    while(month<=0)
    {
        year--;
        month+=12;
    }
    while(day<=0)
    {
        month--;
        day+=getNumberOfDays(month);
    }
    }
    return *this;
}

Date Date::operator+(const Date& o) const {
	return Date(day+o.day, month+o.month, year+o.year);
}

Date Date::operator-(const Date& o) const {
	return Date(day-o.day, month-o.month, year-o.year);
}

bool Date::operator>(const Date& o) const{
    if(year>o.year) return true;
    if(year==o.year && month>o.month) return true;
    if(year==o.year && month==o.month && day>o.day) return true;
    return false;
}

bool Date::operator<(const Date& o) const{
	return (*this>o || *this==o)?false:true;
}

bool Date::operator==(const Date& o) const{
	if(year==o.year && month==o.month && day==o.day) return true;
    else return false;
}

bool Date::operator>=(const Date& o) const{
	return !(*this<o);
}

bool Date::operator<=(const Date& o) const{
	return !(*this>o);
}

bool Date::operator!=(const Date& o) const{
	return !(*this==o);
}
