#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Voz{
    char relacija[50];
    float pominatiKm;
    int noPatnici;
}Voz;

typedef struct ZeleznickaStanica{
    char city[20];
    Voz vozovi[30];
    int numVozovi;
}ZeleznickaStanica;

void najkratkaRelacija(ZeleznickaStanica* zs, int n, char* grad){
    int index=0;
    for(int i=0;i<n;i++){
        if(strcmp(zs[i].city,  grad)==0){
            index=i;
        }
    }
    Voz min=zs[index].vozovi[0];
    for(int i=0;i<zs[index].numVozovi;i++){
        if(zs[index].vozovi[i].pominatiKm < min.pominatiKm){
            min=zs[index].vozovi[i];
        }
    }
    printf("Najkratka relacija: %s-%s (%.2f km)\n", grad, min.relacija, min.pominatiKm);
}

int main()
{
    int n;
    scanf("%d", &n);
    ZeleznickaStanica stanica[100];
    for(int i=0;i<n;i++){
        scanf("%d", &stanica->numVozovi);
    }
    char grad[25];
    scanf("%s", grad);

    najkratkaRelacija(stanica,n,grad);
    return 0;
}
