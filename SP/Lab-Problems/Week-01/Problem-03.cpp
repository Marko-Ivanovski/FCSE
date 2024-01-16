#include <iostream>

using namespace std;

int main() {
    int num;
    int temp1;
    int num1, num2;
    int sum=0;
    cin>>num;
    temp1=num%10000;
    temp1=temp1/10;
    cout<<temp1<<endl;
    num1=num/10000;
    num2=num%10;
    sum=num1+num2;
    cout<<sum;
    
    return 0;
}
