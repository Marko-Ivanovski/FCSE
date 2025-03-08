#include <iostream>

int main() {
    int x, br = 0, tmp, cifra1, cifra2, p, f;

    while (cin >> x) {
        f = 1;
        if (x >= 10) {
            tmp = x;
            cifra1 = tmp % 10;
            tmp /= 10;
            cifra2 = tmp % 10;
            tmp /= 10;
            if (cifra1 < 5 && cifra2 >= 5) {
                p = 1;
            } else if (cifra1 >= 5 && cifra2 < 5) {
                p = 0;
            } else
                f = 0;
            cifra1 = cifra2;
            if (f) {
                while (tmp) {
                    cifra2 = tmp % 10;
                    if (p) {
                        if (!(cifra1 >= 5 && cifra2 < 5)) {
                            f = 0;
                            break;
                        } else
                            p = 0;
                    } else {
                        if (!(cifra1 < 5 && cifra2 >= 5)) {
                            f = 0;
                            break;
                        } else
                            p = 1;
                    }
                    tmp /= 10;
                    cifra1 = cifra2;
                }
            }
            if (f)
                cout << x << endl;
        }
    }

    return 0;
}
