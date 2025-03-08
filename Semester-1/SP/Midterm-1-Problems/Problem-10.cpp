#include <iostream>

using namespace std;

int main(){
    int x, temp;
    bool flag;
    while(cin>>x){
        if(x<10)
            continue;
        if(x>=10&&x<=99){
            if(x%10!=x/10%10)
                cout<<x<<endl;
        }
        temp = x;
        flag = false;
        while(x>99){
            flag = false;
            if(!((x%10 > x/10%10 && x/100%10 > x/10%10)||(x%10 < x/10%10 && x/100%10 < x/10%10))) {
                break;
            }
            else {
                x /= 10;
                flag=true;
            }
        }
        if(flag)
            cout<<temp<<endl;
    }
  
    return 0;
}
