#include <iostream>

using namespace std;

int BrojPozitivni(int array[], int n){
    int pozitivni = 0;
    for (int i = 0; i < n; ++i) {
        if(array[i]>0){
            pozitivni++;
        }
    }
    return pozitivni;
}

int main() {
    int n;
    int array[100];
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>array[i];
    }
    cout<<BrojPozitivni(array,n);
    
    return 0;
}
