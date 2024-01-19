#include <iostream>

using namespace std;

double findArithmetic(const int *row, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += row[i];
    }
    double mean = (double) sum / n;
    return mean;
}

int findElement(const int *row, int n, double mean) {
    int farthest = row[0];
    double distance = row[0] - mean;
    if (distance < 0) {
        distance = -distance;
    }
    for (int i = 0; i < n; ++i) {
        double currentDistance = row[i] - mean;
        if (currentDistance < 0) {
            currentDistance = -currentDistance;
        }
        if (currentDistance > distance) {
            farthest = row[i];
            distance = currentDistance;
        }
    }
    return farthest;
}

int main() {
    int n, m;
    int matrix[100][100];
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
    int result[n];
    for (int i = 0; i < n; ++i) {
        double mean = findArithmetic(matrix[i], m);
        result[i] = findElement(matrix[i], m, mean);
    }
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }

    return 0;
}
