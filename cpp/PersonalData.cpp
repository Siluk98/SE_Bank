#include "../hpp/PersonalData.hpp"

std::string PersonalData::getName() {
	return this->name;
}

void PersonalData::setName(std::string name) {
	this->name = name;
}

std::string PersonalData::getSecondName() {
	return this->secondName;
}

void PersonalData::setSecondName(std::string secondName) {
	this->secondName = secondName;
}

std::string PersonalData::getLastName() {
	return this->lastName;
}

void PersonalData::setLastName(std::string lastName) {
	this->lastName = lastName;
}

Date PersonalData::getDateOfBirth() {
	return this->dateOfBirth;
}

void PersonalData::setDateOfBirth(Date dateOfBirth) {
	this->dateOfBirth = dateOfBirth;
}

std::string PersonalData::getCitizenship() {
	return this->citizenship;
}

void PersonalData::setCitizenship(std::string citizenship) {
	this->citizenship = citizenship;
}

int PersonalData::getID() {
	return this->ID;
}

std::string PersonalData::getPESEL() {
	return this->PESEL;
}

void PersonalData::setPESEL(std::string PESEL) {
	this->PESEL = PESEL;
}

std::string PersonalData::getPhoneNr() {
	return this->phoneNr;
}

void PersonalData::setPhoneNr(std::string phoneNr) {
	this->phoneNr = phoneNr;
}

std::string PersonalData::getEmail() {
	return this->email;
}

void PersonalData::setEmail(std::string email) {
	this->email = email;
}

std::string PersonalData::getAddress() {
	return this->address;
}

void PersonalData::setAddress(std::string address) {
	this->address = address;
}
