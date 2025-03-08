#include<iostream>

using namespace std;

int maxcifra(int n){
    int cifra, maxcifra=0;
    while(n>0)
    {
        cifra=n%10;
        if(maxcifra<cifra)
        {
            maxcifra=cifra;
        }
        n=n/10;
    }
    return maxcifra;
}

int zbir(int n){
    int cifra, zbir=0;
    while(n>0)
    {
        cifra=n%10;
        zbir=zbir+cifra;
        n=n/10;
    }
    return zbir;
}

int main() {
    int n, temp1, temp2=0;
    while(cin>>n)
    {
        temp1=maxcifra(n);
        cout<<n<<": "<<maxcifra(temp2)+zbir(n)<<endl;
        temp2=temp1;

    }
  
return 0;
}
