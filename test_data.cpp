#include <iostream>
#include <string>
#include"hpp\Date.hpp"

using namespace std;

int main()
{
	Date data_01(12, 11, 1923);
	Date data_02(15, 11, 1940);

	Date data_03(89, 8, 1944);
	Date data_04(75, 0, 1960);
	Date data_05(-4, 11, 1970);
	Date data_06(-4, -8, 1970);
	Date data_07(-4, -11, -1);



	//cout << data_01.getString() << endl;
	//data_01 = data_01 + data_02;
	cout << data_01.getString() << endl;
	data_01 = data_01 - data_02;
	cout << data_01.getString() << endl;
	data_01 = data_01 + data_02;
	cout << data_01.getString() << endl;

	if (data_02>data_01)cout << "Większe" << endl;
	if (data_01<data_02)cout << "Mniejsze" << endl;
	if (data_02 == data_02)cout << "Równe" << endl;
	if (data_02 >= data_01)cout << "WiekszoRowne" << endl;
	if (data_01<data_02)cout << "MniejszoRówne" << endl;
	if (data_02 != data_01)cout << "Nierowne" << endl;

	cout << data_02.getString() << endl;
	data_02.setDay(18);
	cout << data_02.getString() << endl;
	data_02.setMonth(9);
	cout << data_02.getString() << endl;
	data_02.setYear(1998);
	cout << data_02.getString() << endl;

	cout << data_03.getString() << endl;
	cout << data_04.getString() << endl;
	cout << data_05.getString() << endl;
	cout << data_06.getString() << endl;
	cout << data_07.getString() << endl;


	system("pause");
	return 0;

}
