#include <iostream>
#include <string>

using namespace std;

string roman_numerals(int number) {
	string roman[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
	int nums[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
	string res;
	for (int i = 12; i >= 0; i--) {
		while (number - nums[i] >= 0) {
			res += roman[i];
			number -= nums[i];
		}
	}
	return res;
}

int main() {
	setlocale(LC_ALL, "rus");

	int number = 0;
	cout << "������� �����:\n";
	cin >> number;
	cout << "������ ����� �������� �������: " << roman_numerals(number);

	return 0;
}