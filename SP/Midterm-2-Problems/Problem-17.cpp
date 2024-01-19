#include <iostream>

using namespace std;

int main() {
    int n;
    double sumGlavna = 0, sumSporedna = 0;
    double matrixA[100][100];
    double matrixB[100][100];
    cin>>n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>matrixA[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i > j) {
                sumGlavna+=matrixA[i][j];
            } 
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i+j > n-1) {
                sumSporedna+=matrixA[i][j];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i==j && i+j==n-1){
                matrixB[i][j] = sumGlavna + sumSporedna;
            } else if (i==j) {
                matrixB[i][j] = sumGlavna;
            } else if (i+j==n-1) {
                matrixB[i][j] = sumSporedna;
            } else {
                matrixB[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout<<matrixB[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
