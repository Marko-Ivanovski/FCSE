#include <iostream>

using namespace std;

int main() {
    int z, num1, num2, parovi=0, brojParovi=0;
    float procent=1;
    cin>>z;
    while(cin>>num1>>num2){
        if(num1==0 && num2==0){
            break;
        }
        else{
            if(num1+num2==z){
                parovi++;
            }
            brojParovi++;
            procent=(parovi*100.0)/brojParovi;
        }
    }
    cout<<"Vnesovte "<<parovi<<" parovi od broevi chij zbir e "<<z<<endl;
    cout<<"Procentot na parovi so zbir "<<z<<" e "<<procent<<"%";
  
    return 0;
}
