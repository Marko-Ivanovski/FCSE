#include <iostream>

using namespace std;

int main() {
    int n, max;
    cin>>n;
    int deliteli=1, zbir=0, najgolem=0;
    for(int i=0;i<n;i++){
        while(deliteli<i){
            if(i%deliteli==0 && i!=deliteli){
                zbir+=deliteli;
            }
            deliteli++;
        }
        if(zbir>najgolem){
            najgolem=zbir;
            max=i;
        }
        deliteli=1;
        zbir=0;
    }
    cout<<max;

    return 0;
}
