#include <iostream>

using namespace std;

int main() {
    int m, temp1, temp2, temp3;
    cin>>m;
    for(int i=1;i<=m;i++){
        if(i==1){
            cout<<"%";
            temp1=m-2;
            while(temp1>0){
                cout<<"@";
                temp1--;
            }
            cout<<"%"<<endl;
        }
        if(i!=1 && i!=m){
            cout<<"%";
            temp2=m-2;
            while(temp2>0){
                cout<<".";
                temp2--;
            }
            cout<<"%"<<endl;
        }
        if(i==m){
            cout<<"%";
            temp3=m-2;
            while(temp3>0){
                cout<<"@";
                temp3--;
            }
            cout<<"%"<<endl;
        }
    }
    return 0;
}
