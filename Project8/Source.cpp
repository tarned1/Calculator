#include<iostream>
#include<cmath>
#include "calculator.h"

using namespace std;

int main()
{
	calculator f;
	char choise;
	int base1, number, base;
	char dx[50], xn[50], n[50];
	char x[50], y[50];
	char Toperator;
	f.inputX(0);
	f.memory();
	do
	{
		cout << "enter a number: \n"
			<< "1 for calculator \n"
			<< "2 to set number to base 10 \n"
			<< "3 to set number from base 10 to anthuor base \n"
			<< "4 to set number from one base to anouther \n"
			<< "5 for M \n"
			<< "6 for ???\n"
			<< "0 to exit \n";
		cout << "ans = " << f.getX() << endl;
		cout << "memory = " << f.getM() << endl;
		cout << "enter your choise:";
		cin >> choise;
		switch (choise)
		{
		//to get out from the calculator
		case '0':
			f.~calculator();
			break;
		//the calculator
		case '1':
			cout << "enter the first number of the quistion:" << endl;
			cin >> x;
			cout << "enter the operator of the quistion:" << endl;
			cin >> Toperator;
			cout << "enter the second number of the quistion:" << endl;
			cin >> y;
			if (Toperator == '@')
				cout << x << Toperator << '=' << f.xy(x, y, Toperator) << endl;
			else if (f.xy(x, y, Toperator) != 3.142344555464566547567)
			{
				cout << f.getHelp() << Toperator << f.getHelp1() << '=';
				cout << f.xy(x, y, Toperator) << endl;
			}
			else
				cout << "ERROR" << endl;
			break;
		//conversion from any base to base 10
		case '2':
			cout << "enter the base of the number:" << endl;
			cin >> base;
			cout << "enter the number:" << endl;
			cin >> x;
			if (!strcmp(x, "ans"))
				number = f.getX();
			else if (!strcmp(x, "M"))
				number = f.getM();
			else
				number = atoi(x);
			if (f.check(base, number))
			{
				cout << f.from_base_n_to_10(number, base) << endl;
				f.inputX(f.from_base_n_to_10(number, base));
			}
			else
				cout << "ERROR" << endl;
			break;
		//conversion from base 10 to any base
		case '3':
			cout << "enter the base of the number you want:" << endl;
			cin >> base;
			cout << "enter the number:" << endl;
			cin >> x;
			if (!strcmp(x, "ans"))
				number = f.getX();
			else if (!strcmp(x, "M"))
				number = f.getM();
			else
				number = atoi(x);
			cout << f.from_base_10_to_base_n(base, number) << endl;
			f.inputX(f.from_base_10_to_base_n(base, number));
			break;
		//conversion from any base to any base
		case '4':
			cout << "enter the base of the number:" << endl;
			cin >> base;
			cout << "enter the base of the number you want:" << endl;
			cin >> base1;
			cout << "enter the number:" << endl;
			cin >> x;
			if (!strcmp(x, "ans"))
				number = f.getX();
			else if (!strcmp(x, "M"))
				number = f.getM();
			else
				number = atoi(x);
			if (f.check(base, number))
			{
				number = f.from_base_n_to_10(number, base);
				cout << f.from_base_10_to_base_n(base1, number) << endl;
				f.inputX(f.from_base_10_to_base_n(base1, number));
			}
			else
				cout << "ERROR" << endl;
			break;
		case '5':
			f.memory();
			cout << "ans had saved!" << endl;
			break;
		case '6':
			cout << "       x ^ 2 * ";
			cin >> dx;
			cout << "        + x * ";
			cin >> xn;
			cout << "          + ";
			cin >> n;
			f.we_will_see(dx, xn, n);
			break;
		default:
			cout << "ERROR" << endl;
			break;
		}
		system("pause");
		system("cls");
	} while (choise != '0');
	return 0;
}