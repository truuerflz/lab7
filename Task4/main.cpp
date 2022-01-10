#include <iostream>
#include <string>
using namespace std;

int length(string num)
{
	int len = 0;
	do {
		len++;
	} while (num[len]);
	return len;
}

string input()
{
	string num;
	bool next;
	do
	{
		next = false;
		cin >> num;
		for (int i = 0; num[i]; i++)
		{
			if (!(num[i] >= '0' && num[i] <= '9') && !(num[i] >= 'A' && num[i] <= 'E'))
			{
				next = true;
				printf("incorrect input!!! try again: ");
				break;
			}
		}
	} while (next);

	return num;
}

int symb(char num)
{
	if (num >= '0' && num <= '9') {
		return (int(num) - 48);
	}
	else {
		return (int(num) - 55);
	}
}

char put(int num)
{
	if (num < 10) {
		return (char(num + 48));
	}
	else {
		return (char(num + 55));
	}
}

char* menu(string num1, string num2)
{
	int len1 = length(num1), len2 = length(num2);
	string max, min;
	int dist, pLen, x;

	if (len1 >= len2) {
		max = num1;
		min = num2;
		dist = len1 - len2;
		pLen = len1;
		x = len2;

	}
	else {
		max = num2;
		min = num1;
		dist = len2 - len1;
		pLen = len2;
		x = len1;
	}

	cout << "введите + или -(сложение\\вычитание):\n";
	char sign;
	cin >> sign;

	if (sign == '+')
	{
		char* result = new char[pLen + 2];
		result[pLen + 1] = '\0';
		int stock = 0;
		int i = pLen - 1;

		while (i >= 0)
		{
			stock += symb(max[i]);
			if (x) {
				stock += symb(min[i - dist]);
				--x;
			}

			if (stock < 15) {
				result[i + 1] = put(stock);
				stock = 0;
			}
			else {
				result[i + 1] = put(stock - 15);
				stock = 1;
			}
			i--;
		}
		if (stock) {
			result[0] = put(stock);
		}
		else {
			result[0] = ' ';
		}

		return result;

	}
	else
	{
		char* result = new char[pLen + 1];
		result[pLen] = '\0';
		int stock = 0;
		int i = pLen - 1;

		while (i >= 0)
		{
			stock += symb(max[i]);
			if (x) {
				stock -= symb(min[i - dist]);
				--x;
			}

			if (stock < 0) {
				stock += 15;
				for (int k = 1; ; k++) {
					if (max[i - k] != '0') {
						max[i - k] = put(symb(max[i - k]) - 1);
						break;
					}
					else {
						max[i - k] = 'E';
					}
				}
			}

			result[i] = put(stock);
			stock = 0;
			i--;
		}

		return result;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "\tВвод пятнадцатеричных чисел:\n";
	cout << "введите 1-е число:\n";
	string num1 = input();
	cout << "введите 2-е число:\n";
	string num2 = input();
	
	cout << "\nвывод: " << menu(num1, num2);

	return 0;
}
