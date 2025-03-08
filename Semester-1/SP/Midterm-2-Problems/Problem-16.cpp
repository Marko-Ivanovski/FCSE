#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    int matrix[100][100];
    int sum1, sum2;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        sum1 = 0;
        sum2 = 0;
        for (int j = 0; j < m / 2 + n % 2; ++j) {
            sum1 += matrix[i][j];
        }
        for (int j = m / 2; j < m; ++j) {
            sum2 += matrix[i][j];
        }
        if (m % 2) {
            matrix[i][n / 2] = abs(sum1 - sum2);
        } else {
            matrix[i][m / 2 - 1] = abs(sum1 - sum2);
            matrix[i][m / 2] = abs(sum1 - sum2);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
