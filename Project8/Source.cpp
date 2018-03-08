#include<iostream>
#include<cmath>

using namespace std;
class calculator
{
public:
	calculator();
	void memory()
	{
		M = ans;
	}
	void print_memory()
	{
		cout << M << endl;
	}
	void printX()
	{
		cout << ans << endl;
	}
	void inputX(int y)
	{
		ans = (float)y;
	}
	float xy(char x[], char y[], char opera)
	{
		char ch;
		if (!strcmp("ans", x))
			help = ans;
		else if (!strcmp("M", x))
			help = M;
		else if (*x < '0' || *x > '9')
		{
			cout << "ERROR" << endl;
			return -1;
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
			cout << "ERROR" << endl;
			return -1;
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
	float ans, M;
	float help, help1;
	float temp;
};

calculator::calculator()
{
}

calculator::~calculator()
{
	cout << "good bay!" << endl;
}

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