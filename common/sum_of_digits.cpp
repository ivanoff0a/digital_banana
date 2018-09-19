#include <iostream>

using namespace std;

int get_sum(int a) {
    int result = 0;
    while (a) {
        result += a % 10;
        a /= 10;
    }
    return result;
}

int get_sum(int a, int base_of_system) {
    int result = 0;
    while (a) {
        result += a % base_of_system;
        a /= base_of_system;
    }
    return result;
}

int main() {
    int a;
    cout << "Enter a number: ";
    cin >> a;
    cout << "Sum of digits = " << get_sum(a) << endl;
    cout << "Count of 1 in binary code = " << get_sum(a, 2) << endl;
    return 0;
}
