#include <iostream>
using namespace std;

int rank3(int sum)
{
	int i = 0;
	for (; sum >= pow(3, i); i++)
	{

	}
	return i;
}

int system3(int n, int j, int h)
{
	int k = 0;

	for (; j < h; j++)
	{
		k = n % 3;
		n /= 3;
	}

	return k;
}

void Sashaclever(int h, int* arr)
{
	for (int i = 1; i < h; i++)
	{
		if (arr[i] == 0)
		{
			arr[i - 1]--;
			arr[i] += 3;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int n;
	cout << "Введите число в десятичной системе счисления для перевода в особенную систему счисления\n";
	cin >> n;

	int h = rank3(n);
	int* sashasystem = new int[h];

	for (int i = 0; i < h; i++)
	{
		sashasystem[i] = system3(n, i, h);
	}

	cout << "\nЧисло в нормальной троичной системе счисления\t";

	for (int i = 0; i < h; i++)
	{
		cout << sashasystem[i];
	}

	cout << "\nЧисло в особенной системе счисления\t\t";

	bool a = true;
	for (int i = 0; i < h; i++)
	{
		if (sashasystem[i] == 0)
		{
			a = false;
		}
	}

	if (a == true)
	{
		for (int i = 0; i < h; i++)
		{
			cout << sashasystem[i];
		}
	}
	else
	{
		Sashaclever(h, sashasystem);
		for (int i = 0; i < h; i++)
		{
			if (sashasystem[i] != 0)
			{
				cout << sashasystem[i];
			}
		}
	}

	cout << "\n";

	return 0;
}
