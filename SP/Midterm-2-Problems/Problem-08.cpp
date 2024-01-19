#include <iostream>

using namespace std;

double equation(int *array, int n) { 
    if (n == 1) {
        return array[0];
    } else {
        return array[0] + 1 / equation(array + 1, n - 1);
    }
}

int main() {
    int n;
    int array[100];
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>array[i];
    }
    cout<<equation(array, n);
    return 0;
}
