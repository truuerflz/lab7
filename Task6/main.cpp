#include <iostream>
#include <string>
using namespace std;

int input() {
    int num;
    while (!(cin >> num) || num < 1) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "incorrect input!!! try again: ";
    }
    return num;
}

int main()
{
    setlocale(LC_ALL, "rus");

    cout << "введите количество наборов:\n";
    int t = input();

    int* arr = new int[t];
    cout << "\tввод наборов:\n";
    for (int i = 0; i < t; i++) {
        arr[i] = input();
    }

    cout << "\nвывод:\n";
    for (int i = 0; i < t; i++) {
        if (arr[i] % 10 == 9) cout << arr[i] / 10 + 1 << endl;
        else cout << arr[i] / 10 << endl;
    }
    delete[] arr;

    return 0;
}