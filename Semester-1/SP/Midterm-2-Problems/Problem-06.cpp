#include <iostream>

using namespace std;

int main() {
    int n, m;
    int counter = 0;
    int matrix[100][100];
    cin>>n>>m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>matrix[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(matrix[i][j] == 1 && matrix[i][j+1] == 1 && matrix[i][j+2] == 1){ //Check rows
                counter++;
                break;
            }
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if(matrix[i][j] == 1 && matrix[i+1][j] == 1 && matrix[i+2][j] == 1){ //Check columns
                counter++;
                break;
            }
        }
    }

    cout<<counter;
    
    return 0;
}
