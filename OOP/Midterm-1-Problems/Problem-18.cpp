#include <iostream>
#include <cstring>

using namespace std;

struct Tanc {
    char ime[15];
    char zemja[15];
};
struct Tancer {
    char ime[20];
    char prezime[20];
    Tanc niza[5];
};

void tancuvanje(Tancer *t, int n, char *zemja) {
    cout << "Tanceri koi znaat da tancuvaat tanc od " << zemja << " se:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (strcmp(t[i].niza[j].zemja, zemja) == 0) {
                cout << t[i].ime << " " << t[i].prezime << ", " << t[i].niza[j].ime << endl;
                break; // Нема потреба да продолжиме проверка за останатите танци
            }
        }
    }
}

int main() {
    int i, j, n;
    char zemja[15];
    Tancer tanceri[5];

    cout << "Vnesi broj na tanceri: ";
    cin >> n;

    for (i = 0; i < n; ++i) {
        cout << "Vnesi ime i prezime na tancer " << i + 1 << ": ";
        cin >> tanceri[i].ime >> tanceri[i].prezime;

        cout << "Vnesi informacii za tanci:\n";
        for (j = 0; j < 3; ++j) {
            cout << "Tanc " << j + 1 << ": ";
            cin >> tanceri[i].niza[j].ime >> tanceri[i].niza[j].zemja;
        }
    }

    cout << "Vnesi zemja za proverka: ";
    cin >> zemja;

    tancuvanje(tanceri, n, zemja);

    return 0;
}
