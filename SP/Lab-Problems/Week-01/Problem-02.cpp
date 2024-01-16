#include <iostream>

using namespace std;

int main() {
    int num;
    cin>>num;
    int years = num/365;
    int temp1 = num%365;
    int months = temp1/30;
    int temp2 = temp1%30;
    int days = temp2%30;
    cout<<"Years: "<<years<<", months: "<<months<<", days: "<<days<<endl;

    return 0;
}
