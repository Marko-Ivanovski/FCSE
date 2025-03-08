#include <iostream>

using namespace std;

int main() {
    int tmp, pomal, pogolem, c1, c2;
    int e_par_equ;

    if (scin >> pogolem >> pomal) {
        if (pogolem <= 0 || pomal <= 0) {
            cout << "Invalid input" << endl;
            return 0;
        }

        if (pomal > pogolem) {
            tmp = pomal;
            pomal = pogolem;
            pogolem = tmp;
        }

        e_par_equ = 1;
        while (pomal > 0) {
            c1 = pomal % 10;
            c2 = (pogolem % 100) / 10;

            if (c1 != c2) {
                e_par_equ = 0;
                break;
            }

            pomal /= 10;
            pogolem /= 100;
        }

        if (e_par_equ) {
            cout << "PAREN" << std::endl;
        } else {
            cout << "NE" << std::endl;
        }
    } else {
        cout << "Invalid input" << endl;
    }

    return 0;
}
