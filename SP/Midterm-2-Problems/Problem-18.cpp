#include <iostream>
#include <cstring>

using namespace std;

void shiftString(char* array, int shifts) {
    char first;
    if (*array == 0) {
        return;
    } else {
        if (isalpha(*array)) {
            first = 'a';
            if (isupper(*array)) {
                first = 'A';
            }
            *array = first + (*array + shifts - first) % 26;
        }
    }
    shiftString(++array, shifts);
}

int main() {
    int n, shifts;
    cin >> n >> shifts;

    cin.ignore(); 

    char array[1000];

    for (int i = 0; i < n; ++i) {
        cin.getline(array, 1000, i);
        shiftString(array, shifts);
        cout << array <<endl;
    }

    return 0;
}
