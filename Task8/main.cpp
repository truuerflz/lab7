#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int input() {
	int num;
	while (!(cin >> num)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "incorrect input!!! try again: ";
	}
	cout << endl;

	return num;
}

int size(string str) {
	int s = 0;
	for (int i = 0; str[i]; i++) {
		s++;
	}
	return s;
}

long long my_stoi(string str) {
	long long result = 0;
	int sign = 1;
	if (str[0] == '-') {
		sign = -1;
	}
	for (int i = 0; i < size(str); i++) {
		if (str[i] != '-') {
			result += (int(str[i]) - 48) * pow(10, size(str) - 1 - i);
		}
	}
	return sign * result;
}

string conv_to_bin(const string& number) {
	long long tmp = my_stoi(number);
	string result;
	while (tmp != 0) {
		result = char((tmp % 2) + 48) + result;
		tmp /= 2;
	}
	return result;
}

string bin_counter(const int& end) {
	string result = "0";
	int counter = 0;
	int i = 0;
	string tmp;
	while (i < end) {
		if (result[size(result) - 1] == '0') {
			result[size(result) - 1] = '1';
		}
		else {
			counter = 0;
			while (counter < size(result)) {
				if (result[size(result) - 1 - counter] == '0') {
					result[size(result) - 1 - counter] = '1';
					for (int k = size(result) - counter; k < size(result); k++) {
						result[k] = '0';
					}
					break;
				}
				counter++;
			}
			if (counter == size(result)) {
				for (int j = 0; j < size(result); j++) {
					result[j] = '0';
				}
				result = '1' + result;
			}
		}
		tmp = conv_to_bin(result);
		tmp = tmp.substr(size(tmp) - size(result), size(tmp));
		if (result == tmp) {
			i++;
		}
	}
	return result;
}

int main() {
	cout << " Enter serial number " << endl;
	int num;
	num = input();
	cout << bin_counter(num);
	return 0;
}