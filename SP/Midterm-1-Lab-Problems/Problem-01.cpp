#include <iostream>

using namespace std;

int main() {
    
    int grade1, grade2, grade3, grade4, grade5;
    int sum;
    float average;
    cin>>grade1>>grade2>>grade3>>grade4>>grade5;
    
    sum = grade1 + grade2 + grade3 + grade4 + grade5;
    average = (float)sum / 5.0; 
    
    cout<<"Average grade: "<<average;
    
    return 0;
}
