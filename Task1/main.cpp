#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int numSize(string num)
{
	int size = 0;
	for (int i = 0; num[i]; i++)
	{
		size++;
	}
	return size;
}

void reverse(string& num)
{
	int size = numSize(num);
	char temp = ' ';
	for (int i = 0; i < size / 2; i++)
	{
		temp = num[i];
		num[i] = num[size - i - 1];
		num[size - i - 1] = temp;
	}
}

int transform_5_10(string num)
{
	int number = 0;
	for (int i = 0; num[i]; i++)
	{
		number += (int(num[i]) - 48) * pow(5, i);
	}

	return number;
}

string transform_10_15(int num)
{
	string str;
	while (num != 0)
	{
		char t = ' ';
		switch (num % 15)
		{
		case 10:
			t = 'A';
			break;
		case 11:
			t = 'B';
			break;
		case 12:
			t = 'C';
			break;
		case 13:
			t = 'D';
			break;
		case 14:
			t = 'E';
			break;
		}

		if (t != ' ') {
			str.push_back(t);
		}
		else {
			str.push_back(num % 15 + 48);
		}

		num /= 15;
	}

	reverse(str);
	return str;
}

int main()
{
	cout << "enter number(5):\n";
	string num;

	bool next;
	do
	{
		next = false;
		cin >> num;
		for (int i = 0; num[i]; i++)
		{
			if (num[i] < '0' || num[i] > '4')
			{
				next = true;
				printf("incorrect input!!! try again: ");
				break;
			}
		}	
	} while (next);
	cout << endl;

	reverse(num);
	cout << "number in 10: " << transform_5_10(num) << endl;
	cout << "number in 15: " << transform_10_15(transform_5_10(num)) << endl;

	return 0;
}