#include <stdio.h>
#include <string.h>

#define NEDELI 4
#define DENOVI 5

typedef struct RabotnaNedela{
    int casovi[DENOVI];
    int nedela;
}RabotnaNedela;

typedef struct Rabotnik{
    char ime[50];
    RabotnaNedela nedeli[NEDELI];
}Rabotnik;

int maxNedela(Rabotnik *r){
    int indexNajrabotnaNedela=0;
    int maxSaati=0;
    for(int i=0;i<NEDELI;i++){
        int vkupnoNedelniSaati=0;
        for(int j=0;j<DENOVI;j++){
           vkupnoNedelniSaati=vkupnoNedelniSaati+r->nedeli[i].casovi[j];
        }
        if(maxSaati<vkupnoNedelniSaati){
            maxSaati=vkupnoNedelniSaati;
            indexNajrabotnaNedela=i;
        }
    }
    return indexNajrabotnaNedela+1;
}

void table(Rabotnik *r, int n){
    printf("Rab\t1\t2\t3\t4\tVkupno\n");
    for(int i=0;i<n;i++){
        printf("%s\t", r[i].ime);
        int vkupno = 0;
        for(int j=0; j<NEDELI;j++){
            int vkupnoNedela= 0;
            for(int t=0;t<DENOVI;t++){
                vkupnoNedela = vkupnoNedela + r[i].nedeli[j].casovi[t];
            }
        printf("%d\t",vkupnoNedela );
        vkupno=vkupno+vkupnoNedela;
        }
    printf("%d\n",vkupno);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    Rabotnik rabotnici[n];
    int i;
    for (i = 0; i < n; ++i) {
        scanf("%s", rabotnici[i].ime);
        int j;
        for (j = 0; j < NEDELI; ++j) {
            int k;
            for (k = 0; k < DENOVI; ++k) {
                scanf("%d", &rabotnici[i].nedeli[j].casovi[k]);
            }

        }
    }
    printf("TABLE\n");
    table(rabotnici, n);
    printf("MAX NEDELA NA RABOTNIK: %s\n", rabotnici[n / 2].ime);
    printf("%d\n", maxNedela(&rabotnici[n / 2]));
    return 0;
}
