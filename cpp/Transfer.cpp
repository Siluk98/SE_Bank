#include "../hpp/Transfer.hpp"

float Transfer::getValue() {
	return this->value;
}

void Transfer::setValue(int value) {
	// TODO - implement Transfer::setValue
	throw "Not yet implemented";
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

void Transfer::setIsPeriodic(bool isPeriodic) {
	// TODO - implement Transfer::setIsPeriodic
	throw "Not yet implemented";
}

int Transfer::getID() {
	// TODO - implement Transfer::getID
	throw "Not yet implemented";
}

Date Transfer::getDate() {
	return this->date;
}

void Transfer::setDate(Date date) {
	// TODO - implement Transfer::setDate
	throw "Not yet implemented";
}

Date Transfer::getPeriod() {
	return this->period;
}

void Transfer::setPeriod(Date period) {
	// TODO - implement Transfer::setPeriod
	throw "Not yet implemented";
}
