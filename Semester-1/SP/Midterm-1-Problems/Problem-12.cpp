#include <iostream>

using namespace std;

int maxCifra(int num){
    int max=0, digits;
    while(num>0){
        digits=num%10;
        if(max<digits){
            max=digits;
        }
        num/=10;
    }
    return max;
}

int main(){
    int num, nulta=0, prva=0, vtora=0, treta=0, cetvrta=0;
    while (cin>>num){
        if(maxCifra(num)==num%10){
            nulta++;
        }
        else if(maxCifra(num)==num/10%10){
            prva++;
        }
        else if(maxCifra(num)==num/100%10){
            vtora++;
        }
        else if(maxCifra(num)==num/1000%10){
            treta++;
        }
        else if(maxCifra(num)==num/10000%10){
            cetvrta++;
        }
    }
    cout<<"0: "<<nulta<<endl;
    cout<<"1: "<<prva<<endl;
    cout<<"2: "<<vtora<<endl;
    cout<<"3: "<<treta<<endl;
    cout<<"4: "<<cetvrta<<endl;

    return 0;
}
