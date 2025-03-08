#include <iostream>

using namespace std;

int main() {
    int n, m, x;
    int sumRow;
    int matrix[100][100];
    cin>>x;
    cin>>n>>m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>matrix[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        sumRow = 0;
        for (int j = 0; j < m; ++j) {
            sumRow += matrix[i][j];
        }
        if (sumRow > x) {
            for (int j = 0; j < m; ++j) {
                matrix[i][j] = 1;
            }
        } else if (sumRow < x) {
            for (int j = 0; j < m; ++j) {
                matrix[i][j] = -1;
            }
        } else {
            for (int j = 0; j < m; ++j) {
                matrix[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
