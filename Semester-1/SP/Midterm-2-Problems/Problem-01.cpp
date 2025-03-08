#include <iostream>

using namespace std;

int main() {
    char currentVowel, previousVowel = 0;
    int found = 0;
    char string;

    while(cin>>string){
        if(string == '#'){
            break;
        } else if (currentVowel == ' ' || currentVowel == '\n' || currentVowel == '\t') {
            previousVowel = 0;
        } else {
            string = tolower(string);
            if(string == 'a' || string == 'e' || string == 'i' || string == 'o' || string == 'u'){
                currentVowel = string;
                if(previousVowel != 0){
                    cout<<previousVowel<<currentVowel<<endl;
                    found++;
                }
                previousVowel=currentVowel;
            } else {
                previousVowel = 0;
            }
        }
    }
    cout<<found;

    return 0;
}
