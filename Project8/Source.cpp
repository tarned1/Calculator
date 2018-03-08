#include<iostream>
#include<cmath>
#include "Header.h"

using namespace std;

float operator_to_numbers(int, int, char);
int from_base_n_to_10(int, int);
int from_base_10_to_base_n(int, int);
bool check(int, int);

int main()
{
	calculator f;
	char choise;
	int base1, number, base;
	char x[25], y[25];
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
			<< "0 to exit \n";
		cout << "ans = ";
		f.printX();
		cout << "memory = ";
		f.print_memory();
		cout << "enter your choise:";
		cin >> choise;
		switch (choise)
		{
		case '0':
			f.~calculator();
			break;
		case '1':
			cin >> x;
			cin >> Toperator;
			cin >> y;
			cout << f.xy(x, y, Toperator) << endl;
			break;
		case '2':
			cout << "enter the base of the number:" << endl;
			cin >> base;
			cout << "enter the number:" << endl;
			cin >> number;
			if (check(base, number))
			{
				cout << from_base_n_to_10(number, base) << endl;
				f.inputX(from_base_n_to_10(number, base));
			}
			else
				cout << "ERROR" << endl;
			break;
		case '3':
			cout << "enter the base of the number you want:" << endl;
			cin >> base;
			cout << "enter the number:" << endl;
			cin >> number;
			cout << from_base_10_to_base_n(base, number) << endl;
			f.inputX(from_base_10_to_base_n(base, number));
			break;
		case '4':
			cout << "enter the base of the number:" << endl;
			cin >> base;
			cout << "enter the base of the number you want:" << endl;
			cin >> base1;
			cout << "enter the number:" << endl;
			cin >> number;
			if (check(base, number))
			{
				number = from_base_n_to_10(number, base);
				cout << from_base_10_to_base_n(base1, number) << endl;
				f.inputX(from_base_10_to_base_n(base1, number));
			}
			else
				cout << "ERROR" << endl;
			break;
		case '5':
			f.memory();
			cout << "ans had saved!" << endl;
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
int from_base_n_to_10(int n, int base)
{
	int ans = 0, i = 0;
	int help = n;
	while (help > 0)
	{
		if (i)
			ans += (help % 10) * pow(base, i);
		else
			ans += help % 10;
		help /= 10;
		++i;
	}
	return ans;
}
int from_base_10_to_base_n(int base, int number)
{
	if (number < base)
		return number;
	return from_base_10_to_base_n(base, number / base) * 10 + (number % base);
}
bool check(int base, int number)
{
	bool good = true;
	int n = number;
	while (n)
	{
		if (n % 10 > base)
			good = false;
		n /= 10;
	}
	return good;
}