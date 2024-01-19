#include <iostream>

using namespace std;

int main() {
    int n;
    int matrix[50][100];
    int newMatrix[100][50];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n * 2; ++j) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n * 2; ++j) {
            if(j<n){
                newMatrix[i][j] = matrix[i][j];
            } else {
                newMatrix[i+n][j-n] = matrix[i][j];
            }
        }
    }
    for (int i = 0; i < n*2; ++i) {
        for (int j = 0; j < n; ++j) {
            cout<<newMatrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
