#include <iostream>

using namespace std;

int digitsOfNums(int nums) {
    while (nums>=10){
        nums/=10;
    }
    return nums;
}

int main() {
    int n, nums, digit;
    int maxDigit, maxNum;
    while(cin>>n){
        if(n==0){
            break;
        } else {
            maxDigit = 0;
            maxNum = 0;
            for (int i = 0; i < n; ++i) {
                cin>>nums;
                digit = digitsOfNums(nums);
                if(digit>maxDigit) {
                    maxDigit = digit;
                    maxNum = nums;
                }
            }
            cout<<maxNum<<endl;
        }
    }
  
    return 0;
}
