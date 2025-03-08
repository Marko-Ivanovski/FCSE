#include <iostream>

using namespace std;

int maxNum(int n) {
    int digit;
    int maxDigit = 0;
    while (n != 0) {
        digit = n%10;
        maxDigit = max(digit, maxDigit);
        n/=10;
    }
    return maxDigit;
}

int main() {
    int n;
    while (cin >> n) {
        cout << maxNum(n) << endl;
    }
    return 0;
}
