#include "../hpp/Transfer.hpp"

int Transfer::_ID = 0;

Transfer::Transfer()
{
    ID = _ID;
    _ID++;
    isExpired = false;
}

Transfer::Transfer(unsigned int f, unsigned int t, float v, Date d, Date p)
:Transfer()
{
    setPeriod(p);
    setFrom(f);
    setTo(t);
    setValue(v);
    setDate(d);
}

float Transfer::getValue() {
	return this->value;
}

void Transfer::setValue(int value) {
	this->value = value;
}

int Transfer::getFrom() {
	return this->from;
}

void Transfer::setFrom(int from) {
	this->from = from;
}

int Transfer::getTo() {
	return this->to;
}

void Transfer::setTo(int to) {
	this->to = to;
}

bool Transfer::getIsPeriodic() {
	return this->isPeriodic;
}

/*
void Transfer::setIsPeriodic(bool isPeriodic) {
	// TODO - implement Transfer::setIsPeriodic
	throw "Not yet implemented";
}
*/

int Transfer::getID() {
	return this->ID;
}

Date Transfer::getDate() {
	return this->date;
}

void Transfer::setDate(Date date) {
	this->date = date;
}

Date Transfer::getPeriod() {
	return this->period;
}

void Transfer::setPeriod(Date period) {
	this->period = period;
	if(period == Date(0,0,0)) isPeriodic = false;
	else isPeriodic = true;
}

void Transfer::setIsExpired(bool isExpired)
{
    this->isExpired = isExpired;
}

bool Transfer::getIsExpired()
{
    return isExpired;
}

bool Transfer::execute()
{
    BankingSystem& bank = BankingSystem::getInstance();
    std::shared_ptr<BankingAccount> f = bank.getAccount(from);
    std::shared_ptr<BankingAccount> t = bank.getAccount(to);
    if(f==nullptr || t == nullptr) return false;
    float factor = 1;
    if(f->getCurrency() != t->getCurrency()) factor = bank.calculateCurrencyFactor(f->getCurrency(),t->getCurrency());
    f->addMoney(-1*value);
    t->addMoney(value*factor);
    if(!getIsPeriodic()) setIsExpired(true);
    else setDate(getDate()+getPeriod());
    return true;
}
