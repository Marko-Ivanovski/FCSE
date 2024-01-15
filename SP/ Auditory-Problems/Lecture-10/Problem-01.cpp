#include <iostream>

using namespace std;

int main() {
    int counter = 0;
    char string[100];
    char ch;
    cin.getline(string, 100);
    cin>>ch;
    for (int i = 0; i < strlen(string); ++i) {
        if(string[i]==ch){
            counter++;
        }
    }
    cout<<counter;

    return 0;
}
