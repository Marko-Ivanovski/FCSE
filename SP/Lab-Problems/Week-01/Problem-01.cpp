#include <iostream>

using namespace std;

int main() {
    int radius;
    cin>>radius;
    double perimetar=1, plostina=1;
    perimetar=2*radius*3.14;
    plostina=radius*radius*3.14;
    cout<<"Perimetar: "<<perimetar<<endl;
    cout<<"Plostina: "<<plostina<<endl;
    
    return 0;
}