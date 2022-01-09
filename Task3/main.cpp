#include <iostream>
using namespace std;

int length(char* num)
{
	int len = 0;
	do {
		len++;
	} while (num[len]);
	return len;
}

char* input()
{
	char* num = new char[10];
	bool next;
	do
	{
		next = false;
		cin >> num;
		int len = length(num);
		for (int i = 0; num[i]; i++)
		{
			if (num[i] < '0' || num[i] > '1' || len != 8 )
			{
				next = true;
				printf("incorrect input!!! try again: ");
				break;
			}
		}
	} while (next);

	return num;
}

void to_compl(char*& num)
{
	if (num[0] == '1')
	{
		int length = 1;
		for (int i = 1; num[i]; i++)
		{
			length++;
			if (num[i] == '1') {
				num[i] = '0';
			}
			else {
				num[i] = '1';
			}
		}

		for (int i = length - 1; i; i--) {
			if (num[i] == '0')
			{
				num[i] = '1';
				for (int k = i + 1; k < length; k++) {
					num[k] = '0';
				}
				break;
			}
		}
	}
}

char* sum(char* num1, char* num2)
{
	int m = 9;
	char* res = new char[m];
	bool have = false;

	int i = 7;
	while (i >= 0)
	{
		if (num1[i] == '1' && num2[i] == '1') {
			if (have) {
				res[m-- - 2] = '1';
			}
			else {
				res[m-- - 2] = '0';
			}
			have = true;
		}
		else if (num1[i] == '0' && num2[i] == '0') {
			if (have) {
				res[m-- - 2] = '1';
				have = false;
			}
			else {
				res[m-- - 2] = '0';
			}
		}
		else {
			if (have) {
				res[m-- - 2] = '0';
			}
			else {
				res[m-- - 2] = '1';
			}
		}
		i--;
	}


	res[8] = '\0';

	return res;

}


int main()
{
	setlocale(LC_ALL, "rus");
	cout << "\tВвод двоичных чисел в естественной форме(8бит):\n";
	cout << "введите 1-е число:\n";
	char* num1 = input();
	cout << "введите 2-е число:\n";
	char* num2 = input();

	to_compl(num1);
	to_compl(num2);

	cout <<  endl << "Преобразованные в доп. код: " << num1 << ", " << num2 << endl;

	char* result = sum(num1, num2);

	

	if (result[0] == '1')
	{
		for (int i = 7; i; i--) {
			if (result[i] == '1')
			{
				result[i] = '0';
				for (int k = i + 1; k < 8; k++) {
					result[k] = '1';
				}
				break;
			}
		}

		for (int i = 1; result[i]; i++)
		{
			if (result[i] == '1') {
				result[i] = '0';
			}
			else {
				result[i] = '1';
			}
		}
	}

	int resultN = 0;
	for (int i = 1; result[i]; i++) {
		resultN += (int(result[i]) - 48) * pow(2, 7 - i);
	}

	cout << "\nСумма чисел в естественной форме:\n2: " << result << "\n10: ";
	if (result[0] == '1')
		cout << "-";
	cout << resultN;

	delete[] num1;
	delete[] num2;
	delete[] result;

	return 0;
}