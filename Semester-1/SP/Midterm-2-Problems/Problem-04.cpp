#include <iostream>

using namespace std;

int main() {
   int n, m;
   int matrix[100][100];
   cin>>n>>m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>matrix[i][j];
        }
    }
    int x, y;
    int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    cin>>x>>y;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i<x && j>=y){
                sum1 += matrix[i][j];
            } else if (i<x && j<y){
                sum2 += matrix[i][j];
            } else if (i>=x && j<y){
                sum3 += matrix[i][j];
            } else if (i>=x && j>=y){
                sum4 += matrix[i][j];
            }
        }
    }
    cout<<sum1<<" "<<sum2<<" "<<sum3<<" "<<sum4;
    
    return 0;
}
