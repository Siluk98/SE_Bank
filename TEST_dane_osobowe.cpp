//#include "./hpp/PersonalData.hpp"
#include "./cpp/PersonalData.cpp"
#include "./hpp/Date.hpp"
#include "./cpp/Date.cpp"
#include <string>
#include<iostream>
using namespace std;
/*rivate:
	string name;
	string secondName;
	string lastName;
	Date dateOfBirth;
	string citizenship;
	int ID;
	string PESEL;
	string phoneNr;
	string email;
	string address;
*/

int main()
{
	PersonalData osoba_01;
	osoba_01.setName("Adam");	
	osoba_01.setSecondName("Piotr");	
	osoba_01.setLastName("Kowal");
	osoba_01.setDateOfBirth(Date(1,2,1998));
	osoba_01.setCitizenship("Polska");	
	osoba_01.setPESEL("980201123");
	osoba_01.setPhoneNr(string("123456789"));
	osoba_01.setEmail("adam.kowal@poczta.pl");
	osoba_01.setAddress("ul.Dzika 27");

	cout<<osoba_01.getName()<<endl;	
	cout<<osoba_01.getSecondName()<<endl;	
	cout<<osoba_01.getLastName()<<endl;
	cout<<osoba_01.getDateOfBirth().getString()<<endl;
	cout<<osoba_01.getCitizenship()<<endl;	
	cout<<osoba_01.getPESEL()<<endl;
	cout<<osoba_01.getPhoneNr()<<endl;
	cout<<osoba_01.getEmail()<<endl;
	cout<<osoba_01.getAddress()<<endl;

	
	return 0;
}