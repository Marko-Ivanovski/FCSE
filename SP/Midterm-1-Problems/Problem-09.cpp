#include <iostream>

using namespace std;

int main() {
    char hex;
    int sum=0;
    while(cin>>hex) {
        if(hex=='.') {
            break;
        } else {
            if(hex == 'A' || hex=='a'){
                sum+=10;
            }
            if(hex == 'B' || hex=='b'){
                sum+=11;
            }
            if(hex == 'C' || hex=='c'){
                sum+=12;
            }
            if(hex == 'D' || hex=='d'){
                sum+=13;
            }
            if(hex == 'E' || hex=='e'){
                sum+=14;
            }
            if(hex == 'F' || hex=='f'){
                sum+=15;
            }
            if(hex>='0' && hex<='9'){
                sum+=hex-'0';
            }
        }

    }
    if(sum%16==0){
        if(sum%10==6 && sum/10%10==1){
            cout<<"Poln pogodok";
        } else{
            cout<<"Pogodok";
        }
    } else{
        cout<<sum;
    }
  
    return 0;
}
