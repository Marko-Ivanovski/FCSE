#include <iostream>

using namespace std;

int main() {
    int sum=0, temp=0;
    char znak;
    while(cin>>noskipws>>znak){
        if(znak=='!') {
            break;
        } else {
            if(znak>='0' && znak<='9'){
                temp=(temp*10)+znak-'0';
            } else {
                sum+=temp;
                temp=0;
            }
        }
    }
    cout<<sum+temp;
  
    return 0;
}
