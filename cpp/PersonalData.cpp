#include "../hpp/PersonalData.hpp"

std::string PersonalData::getName() {
	return this->name;
}

void PersonalData::setName(std::string Imie) {
	//throw "Not yet implemented";

	name=Imie; //Suhar
}

std::string PersonalData::getSecondName() {
	return this->secondName;
}

void PersonalData::setSecondName(std::string DrugieImie) {
	
	//throw "Not yet implemented";
	secondName=DrugieImie;//Suhar
}

std::string PersonalData::getLastName() {
	return this->lastName;
}

void PersonalData::setLastName(std::string Nazwisko) {
	
	//throw "Not yet implemented";
	lastName=Nazwisko;
}

Date PersonalData::getDateOfBirth() {
	return this->dateOfBirth;
}

void PersonalData::setDateOfBirth(Date DataUrodzenia) {
	
	//throw "Not yet implemented";
	dateOfBirth=DataUrodzenia;
}

std::string PersonalData::getCitizenship() {
	return this->citizenship;
}

void PersonalData::setCitizenship(std::string Obywatelstwo) {
	
	//throw "Not yet implemented";
	citizenship=Obywatelstwo;
}

int PersonalData::getID() {
	// TODO - implement PersonalData::getID
	throw "Not yet implemented";
}

std::string PersonalData::getPESEL() {
	
	//throw "Not yet implemented";
	return this->PESEL;
}

void PersonalData::setPESEL(std::string pesel) {
	
	//throw "Not yet implemented";
	PESEL=pesel;
}

std::string PersonalData::getPhoneNr() {
	return this->phoneNr;
}

void PersonalData::setPhoneNr(std::string NrTel) {
	
	//throw "Not yet implemented";
	phoneNr=NrTel;
}

std::string PersonalData::getEmail() {
	return this->email;
}

void PersonalData::setEmail(std::string Email) {
	
	//throw "Not yet implemented";
	email=Email;
}

std::string PersonalData::getAddress() {
	return this->address;
}

void PersonalData::setAddress(std::string Address) {
	
	//throw "Not yet implemented";
	address=Address;
}
