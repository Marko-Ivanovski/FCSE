#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    float niza[n], avg = 0, diff = 0, el = 0;

    for (int i = 0; i < n; i++) {
        cin >> niza[i];
        avg += niza[i];
    }

    avg /= n;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            diff = avg - niza[i];
            el = niza[i];
            if (diff < 0)
                diff *= -1;
        }

        float r = avg - niza[i];

        if (r < 0)
            r *= -1;

        if (diff > r) {
            diff = r;
            el = niza[i];
        }
    }

    cout << fixed << setprecision(2) << el << endl;

    return 0;
}
