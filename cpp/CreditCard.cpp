#include "../hpp/CreditCard.hpp"

int CreditCard::getID() {
	return ID;
}

bool CreditCard::getIsRestricted() {
	return isRestricted;
}

void CreditCard::setIsRestricted(bool isRestricted) {
	this->isRestricted = isRestricted;
}

std::string CreditCard::getSecurityCode() {
	return securityCode;
}

void CreditCard::setSecurityCode(std::string securityCode) {

}

std::string CreditCard::getPin() {
	return pin;
}

void CreditCard::setPin(std::string pin) {
	this->pin = pin;
}

void CreditCard::restict() {
	setIsRestricted(false);
}
