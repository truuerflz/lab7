#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "введите число в дополнительном коде:\n";
	char num[16];
	int length;
	bool next;
	do
	{
		next = false;
		length = 0;
		cin >> num;
		for (int i = 0; num[i]; i++)
		{
			length++;
			if (num[i] < '0' || num[i] > '1' || length == 17)
			{
				next = true;
				printf("incorrect input!!! try again: ");
				break;
			}
		}
	} while (next);
	cout << endl;

	long result = 0;
	bool k = true;
	if(num[0] == '1')
	{
		for (int i = length - 1; i ; i--) {
			if (num[i] == '1') 
			{
				k = false;
				num[i] = '0';
				if (i != length - 1) {
					num[i + 1] = '1';
				}
				break;
			}
		}

		if (k) {
			cout << "число в естественной форме:\n" << -128;
			return 0;
		}

		for (int i = 1; num[i]; i++)
		{
			if (num[i] == '1') {
				num[i] = '0';
			}
			else {
				num[i] = '1';
			}
		}
	}

	for (int i = 1; num[i]; i++) {
		result += (int(num[i]) - 48) * pow(2, length - i - 1);
	}

	cout << "число в естественной форме:\n";
	if (num[0] == '1')
		cout << "-";
	cout << result;

	return 0;
}
