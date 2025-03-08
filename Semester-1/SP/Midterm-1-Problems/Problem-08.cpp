#include <iostream>

using namespace std;

int main() {
    int n, x, temp1, temp2, digits1, digits2;
    bool najden;
    cin>>n>>x;
    for(int i=n-1;i>=0;i--){
        najden= true;
        for(temp1=i;temp1>0;temp1/=10){
            digits1=temp1%10;
            for(temp2=x;temp2>0;temp2/=10){
                digits2=temp2%10;
                if(digits1==digits2){
                    najden=false;
                }
            }
        }
        if(najden!=false){
            cout<<i;
            break;
        }
    }
  
    return 0;
}
