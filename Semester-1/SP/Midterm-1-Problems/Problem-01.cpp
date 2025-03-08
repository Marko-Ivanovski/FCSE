#include <iostream>

using namespace std;

int main() {
    int pocetok, kraj;
    cin>>pocetok>>kraj;
    int minBlagBroj=0;

    for(int i=pocetok;i<=kraj;i++){
        int number = i;
        bool isBlag = true;
        while(number>0){
            int digits = number%10;
            if(digits%2!=0){
                isBlag=false;
                break;
            }
            number/=10;
        }
        if(isBlag){
            minBlagBroj=i;
            break;
        }
    }
    if (minBlagBroj != 0) {
        cout <<minBlagBroj<< endl;
    } else {
        cout << "NE" << endl;
    }
    return 0;
}
