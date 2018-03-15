#pragma once
#include<iostream>
using namespace std;
class calculator
{
public:
	calculator();

	void we_will_see(char* dc, char* xc, char* inc)
	{
		if (check_input(dc) && check_input(xc) && check_input(inc))
		{
			double dx = atof(dc), x = atof(xc), in = atof(inc);
			double ans1 = 0;
			double ans2 = 0;
			double discreminanta = sqrt(x * x - 4 * in * dx);
			if (discreminanta > 0 && dx)
			{
				ans1 = ((-x) + discreminanta) / (2 * dx);
				ans2 = ((-x) - discreminanta) / (2 * dx);
				cout << "answer1 : " << ans1 << endl;
				cout << "answer2 : " << ans2 << endl;
			}
			else if (discreminanta == 0 && dx)
			{
				ans1 = ((-x) + discreminanta) / (2 * dx);
				cout << "answer : " << ans1 << endl;
			}
			else if (dx == 0)
			{
				if (x > 0)
				{
					ans1 = (-in) / (x);
					cout << "answer : " << ans1 << endl;
				}
				else if (x < 0)
				{
					ans1 = (in) / (-x);
					cout << "answer : " << ans1 << endl;
				}
				else
					cout << "all numbers is the answer!" << endl;
			}
			else
				cout << "no answer!!" << endl;
		}
		else
			cout << "ERROR!" << endl;
	}
	//returns the value of help
	double getHelp()
	{
		return help;
	}
	
	//returns the value of help1
	double getHelp1()
	{
		return help1;
	}

	//gets the value of ans and put it in num
	int getX()
	{
		return (int)ans;
	}
	//gets the value of M and put it in num
	int getM()
	{
		return (int)M;
	}
	//the function set's a number from in any base (from base 2 to base 9) to base 10
	double from_base_n_to_10(int n, int base)
	{
		int i = 0;
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
	//the fuction set's number from base 10 to any base (from base 2 to base 9)
	int from_base_10_to_base_n(int base, int number)
	{
		if (number < base)
			return number;
		return from_base_10_to_base_n(base, number / base) * 10 + (number % base);
	}

	//save a number the user wants
	void memory()
	{
		M = ans;
	}

	//set new value in ans
	void inputX(double y)
	{
		ans = y;
	}

	//all operators for to numbers (*,/,%,^,+,-) but only for two numbers
	double xy(char x[], char y[], char opera)
	{
		if (!strcmp("ans", x))
			help = ans;
		else if (!strcmp("M", x))
			help = M;
		else if (!check_input(x))
		{
			return 3.142344555464566547567;
		}
		else
		{
			help = atof(x);
		}
		if (!strcmp("ans", y))
			help1 = ans;
		else if (!strcmp("M", y))
			help1 = M;
		else if (!check_input(y))
		{
			return 3.142344555464566547567;
		}
		else
			help1 = atof(y);

		switch (opera)
		{
		case '+':
			ans = help + help1;
			break;
		case '-':
			ans = help - help1;
			break;
		case '*':
			ans = help * help1;
			break;
		case '%':
			ans = (int)help % (int)help1;
			break;
		case '/':
			ans = help / help1;
			break;
		case '^':
			temp = help;
			for (int i = 1; i < help1; ++i)
				help *= temp;
			ans = help;
			break;
		case '@':
			ans = sqrt(help);
			break;
		default:
			break;
		}
		return ans;
	}

	~calculator();

private:
	double ans, M, help, help1, temp;
	bool check_input(char *input)
	{
		bool good = true;
		for (int i = 0; input[i]; ++i)
			if (input[i] < '0' || input[i] > '9')
				good = false;
		return good;
	}
};

calculator::calculator()
{
}

calculator::~calculator()
{
}