#include <iostream>
#include <cmath>
using namespace std;

int input() {
	cout << "введите число: ";
	int num;
	while (!(cin >> num)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "incorrect input!!! try again: ";
	}
	cout << endl;

	return num;
}

void divide(int num, int div)
{
	int pl = div;
	bool is = false;
	while (div <= num) {
		if (num == div) {
			is = true;
			break;
		}
		else {
			div += pl;
		}
	}
	cout << "число " << num;
	if (!is) cout << " не";
	cout << " делится на " << pl << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");

	int num = input();
	num = abs(num);
	int divs[] = { 11, 43, 179 };

	int i = 0;
	while (i < 3) {
		divide(num, divs[i]);
		i++;
	}

	return 0;
}