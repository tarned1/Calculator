#pragma once
#include<iostream>
using namespace std;
class calculator
{
public:
	calculator();

	void we_will_see(double dx, double x, double in)
	{
		double discreminanta = sqrt(x * x - 4 * in * dx);
		double ans1 = ((-x) + discreminanta) / (2 * dx);
		double ans2 = ((-x) - discreminanta) / (2 * dx);
		cout << "answer1 : " << ans1 << endl;
		cout << "answer2 : " << ans2 << endl;
	}
	//returns the value of help
	int getHelp()
	{
		return help;
	}
	
	//returns the value of help1
	int getHelp1()
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

	//the fuction set's number from base 10 to any base (from base 2 to base 9)
	int from_base_10_to_base_n(int base, int number)
	{
		if (number < base)
			return number;
		return from_base_10_to_base_n(base, number / base) * 10 + (number % base);
	}

	//check if you entered a valid input in the base change fuctions
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

	//save a number the user wants
	void memory()
	{
		M = ans;
	}

	//set new value in ans
	void inputX(int y)
	{
		ans = (float)y;
	}

	//all operators for to numbers (*,/,%,^,+,-) but only for two numbers
	float xy(char x[], char y[], char opera)
	{
		char ch;
		if (!strcmp("ans", x))
			help = ans;
		else if (!strcmp("M", x))
			help = M;
		else if (*x < '0' || *x > '9')
		{
			return 3.142344555464566547567;
		}
		else
		{
			help = (float)atoi(x);
		}
		if (!strcmp("ans", y))
			help1 = ans;
		else if (!strcmp("M", y))
			help1 = M;
		else if (*y < '0' || *y > '9')
		{
			return 3.142344555464566547567;
		}
		else
			help1 = (float)atoi(y);

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
		default:
			break;
		}
		return ans;
	}

	~calculator();

private:
	float ans, M, help, help1, temp;
};

calculator::calculator()
{
}

calculator::~calculator()
{
}