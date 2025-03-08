#include <iostream>

using namespace std;

int main() {
    int n, max=0, interesenNum=0, obraten=0, digits=0, copyOfInteresen, brojac=0;
    cin>>n;
    for (int i=1; i<n; i++) {
        interesenNum=i;
        obraten=0;
        brojac=0;
        while (interesenNum!=0) {
            digits=interesenNum%10;
            brojac++;
            obraten+=digits;
            interesenNum/=10;
            if (interesenNum==0) {
                break;
            }
            obraten*=10;
        }
        if (obraten%brojac==0) {
            copyOfInteresen=i;
            if (max<i) {
                max=i;
            }
        }
    }
    if (n<=9) {
        cout<<"Brojot ne e validen"<<endl;
    }
    else{
        cout<<max;
    }
  
    return 0;
}
