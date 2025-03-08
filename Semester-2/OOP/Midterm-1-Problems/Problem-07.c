#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vozenje{
    char name[50];
    int time;
    float price;
    int discount;
}Vozenje;

typedef struct ZabavenPark{
    char name[100];
    char location[100];
    Vozenje array[100];
    int n;
}ZabavenPark;

void print(ZabavenPark *array, int n){
    for(int i=0;i<n;i++){
        printf("%s %s\n", array[i].name, array[i].location);
        for(int j=0;j<array[i].n;j++){
            printf("%s %d %.2f\n", array[i].array[j].name, array[i].array[j].time, array[i].array[j].price);
        }
    }
}
void najdobar(ZabavenPark *array, int n){
    int maxName=0;
    int maxLocation=0;
    int maxTime=0;
    for(int i=0;i<n;i++){
        int counter=0;
        int timeSpent=0;
        for(int j=0;j<array[i].n;j++){
            if(array[i].array[j].discount==1)
                counter++;
                timeSpent+=array[i].array[j].time;
        }
        if(counter>maxLocation){
            maxLocation=counter;
            maxName=i;
            maxTime=timeSpent;
        }
        else if(counter==maxLocation && timeSpent>maxTime){
            maxName=i;
            maxLocation=timeSpent;
        }
    }
    printf("Najdobar park: %s %s\n", array[maxName].name, array[maxName].location);
}
int main()
{
    int n, broj;
    ZabavenPark park[100];   //Niza od 100 zabavni parkovi
    scanf("%d", &n);
    for(int i=0;i<n;i++){    //Citanje na podatoci
        scanf("%s", park[i].name);
        scanf("%s", park[i].location);
        scanf("%d", &park[i].n);
        for(int j=0;j<park[i].n;j++){
            scanf("%s", park[i].array[j].name);
			scanf("%d", &park[i].array[j].time);
			scanf("%f", &park[i].array[j].price);
            scanf("%d", &park[i].array[j].discount);
        }
    }
    print(park,n);
    najdobar(park,n);

    return 0;
}
