#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int uplata;
    cin >> uplata;

    string maxType;
    int maxBetType;
    double maxCoefficient = 0.0;

    while (true) {
        string type;
        int betType;
        double coefficient;

        cin >> type;

        if (type == "#") {
            break;
        }

        cin >> betType >> coefficient;

        if (coefficient > maxCoefficient) {
            maxType = type;
            maxBetType = betType;
            maxCoefficient = coefficient;
        }
    }

    double dobitok = uplata * maxCoefficient;

    cout << "Najgolem koeficient: " << maxType << " " << maxBetType << " " << maxCoefficient << endl;
    cout << "Mozhna dobitka: " << dobitok << endl;

    return 0;
}
