#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int gcd_easy(int a, int b) {
    while (a) a ^= b ^= a ^= b %= a;
    return b;
}

int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int gcd_if(int a, int b) {
    while (a && b) {
        if (a > b) a %= b;
        else b %= a;
    }
    return a + b;
}

int main() {
    srand(time(0));
    vector<int> as, bs;
    const int n = 100000000;
    for (int i = 0; i < n; ++i) {
        as.push_back(rand());
        bs.push_back(rand());
    }

    clock_t cl;
    int sum;

    cl = clock();
    sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += gcd(as[i], bs[i]);
    }
    cout << "GCD: " << (clock() - cl) / (double) CLOCKS_PER_SEC << ", sum = " << sum << endl;

    cl = clock();
    sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += gcd_if(as[i], bs[i]);
    }
    cout << "GCD with if: " << (clock() - cl) / (double) CLOCKS_PER_SEC << ", sum = " << sum << endl;

    cl = clock();
    sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += gcd_easy(as[i], bs[i]);
    }
    cout << "GCD easy: " << (clock() - cl) / (double) CLOCKS_PER_SEC << ", sum = " << sum << endl;

    return 0;
}