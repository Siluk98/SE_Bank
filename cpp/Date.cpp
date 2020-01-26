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
static std::string add_zero_year(int arg)
{
    if(arg>=0&&arg<10) return std::string("000")+std::to_string(arg);
    else if (arg>=10&&arg<100) return std::string("00")+std::to_string(arg);
    else if (arg>=100&&arg<1000) return std::string("0")+std::to_string(arg);
    else if (arg<=0&&arg>-10) return std::string("-000")+std::to_string(arg*(-1));
    else if (arg<=-10&&arg>-100) return std::string("-00")+std::to_string(arg*(-1));
    else if (arg<=-100&&arg>-1000) return std::string("-0")+std::to_string(arg*(-1));
    else return std::to_string(arg);
}

std::string Date::getString()
{
    std::string s("");
    s+=add_zero(day);
    s+=".";
    s+=add_zero(month);
    s+=".";
    s+=add_zero_year(year);
    return s;
}

std::string Date::getSpaceString()
{
    std::string s("");
    s+=add_zero(day);
    s+=" ";
    s+=add_zero(month);
    s+=" ";
    s+=add_zero_year(year);
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
    //if(m==1||m==3||m==5||m==7||m==9||m==11||m==12) return 31;
    if(m&1||m==12) return 31;
    else if (m==2) return 28;
    else return 30;
}

Date& Date::add(int d, int m, int y)
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

Date Date::getCurrentDate()
{
    std::chrono::time_point t = std::chrono::system_clock::now();
    return Date(1970,1,1+std::chrono::system_clock::to_time_t(t)/86400);
}
