#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <cstdio>

using namespace std;

int simple_read() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        sum += a;
    }
    return sum;
}

int scanf_read() {
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        sum += a;
    }
    return sum;
}

int faster_read() {
    int n;
    cin >> n;
    string str;
    getline(cin, str);
    getline(cin, str);
    stringstream ss(str);
    int a, sum = 0;
    while (ss >> a) sum += a;
    return sum;
}

int main() {
    clock_t cl;
    int sum;

    freopen("big_input.txt", "r", stdin);
    cl = clock();
    sum = simple_read();
    cout << "Simple read: " << (clock() - cl) / (double) CLOCKS_PER_SEC << ", sum = " << sum << endl;

    freopen("big_input.txt", "r", stdin);
    cl = clock();
    sum = scanf_read();
    cout << "Scanf read: " << (clock() - cl) / (double) CLOCKS_PER_SEC << ", sum = " << sum << endl;

    freopen("big_input.txt", "r", stdin);
    cl = clock();
    sum = faster_read();
    cout << "Faster read: " << (clock() - cl) / (double) CLOCKS_PER_SEC << ", sum = " << sum << endl;
    return 0;
}
