#include <iostream>

using namespace std;

int sum_pos(int ind, int* array, int n){
    int sum = 0;
    for (int i = ind; i < n; ++i) {
        sum+=array[i];
    }
    return sum;
}

int main() {
    int n, ind;
    int array[100];
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>array[i];
    }
    cin>>ind;
    cout<<sum_pos(ind, array, n);
  
    return 0;
}
