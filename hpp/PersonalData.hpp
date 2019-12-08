#ifndef PERSONALDATA_H
#define PERSONALDATA_H
#include <string>
#include "Date.hpp"
class PersonalData {

private:
	std::string name;
	std::string secondName;
	std::string lastName;
	Date dateOfBirth;
	std::string citizenship;
	int ID;
	std::string PESEL;
	std::string phoneNr;
	std::string email;
	std::string address;

public:
	std::string getName();
	void setName(std::string name);
	std::string getSecondName();
	void setSecondName(std::string secondName);
	std::string getLastName();
	void setLastName(std::string lastName);
	Date getDateOfBirth();
	void setDateOfBirth(Date dateOfBirth);
	std::string getCitizenship();
	void setCitizenship(std::string citizenship);
	int getID();
	std::string getPESEL();
	void setPESEL(std::string PESEL);
	std::string getPhoneNr();
	void setPhoneNr(std::string phoneNr);
	std::string getEmail();
	void setEmail(std::string email);
	std::string getAddress();
	void setAddress(std::string address);
};

#endif
