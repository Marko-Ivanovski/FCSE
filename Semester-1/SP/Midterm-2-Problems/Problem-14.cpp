#include <iostream>

using namespace std;

int poramnet(int a) {
    if (a == 0) {
        return 0;
    }
    int digit = a % 10;
    if (digit == 9) {
        return 7 + poramnet(a / 10) * 10;
    } else {
        return digit + poramnet(a / 10) * 10;
    }
}

int main() {
    int input, alignments[5];
    int count = 0;

    while (cin >> input) {
        alignments[count] = poramnet(input);
        count++;
        if (count == 5) {
            break;
        }
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (alignments[j] > alignments[j + 1]) {
                int temp = alignments[j];
                alignments[j] = alignments[j + 1];
                alignments[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < count; i++) {
        cout << alignments[i] << " ";
    }

    return 0;
}
