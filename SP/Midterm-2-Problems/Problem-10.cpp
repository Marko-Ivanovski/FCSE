#include <iostream>
#include <cstring>

using namespace std;

void bubbleSort(char* chArray, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (chArray[j] > chArray[j + 1]) {
                swap(chArray[j], chArray[j + 1]);
            }
        }
    }
}

int main() {
    char chArray[100];

    while (cin.getline(chArray, 100, '#')) {
        int length = strlen(chArray);
        int counter = 0;

        for (int i = 0; i < length; i++) {
            if (isdigit(chArray[i])) {
                counter++;
            }
        }

        bubbleSort(chArray, length);
        cout << counter << ": ";


        for (int i = 0; i < length; i++) {
            cout << chArray[i];
        }
        cout << endl;
    }

    cin.clear();

    return 0;
}
