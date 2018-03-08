#pragma once
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