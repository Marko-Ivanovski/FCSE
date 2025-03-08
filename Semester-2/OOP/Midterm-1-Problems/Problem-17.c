#include <stdio.h>
#include <string.h>

// Define the Pacient structure
typedef struct {
    char ime[100];
    int zdrastveno;
    int pregledi;
} Pacient;

// Define the MaticenDoktor structure
typedef struct {
    char ime[100];
    int br_pac;
    Pacient niza[200];
    float cena;
} MaticenDoktor;

// Function to find the most successful doctor
void najuspesen_doktor(MaticenDoktor* doktori, int n) {
    int maxEarned = -1;
    int maxEarnedIndex = -1;

    for (int i = 0; i < n; ++i) {
        int totalEarned = 0;
        int totalExams = 0;

        for (int j = 0; j < doktori[i].br_pac; ++j) {
            if (!doktori[i].niza[j].zdrastveno) {  // If not health insured
                totalEarned += doktori[i].niza[j].pregledi * doktori[i].cena;
            }
            totalExams += doktori[i].niza[j].pregledi;
        }

        if (totalEarned > maxEarned || (totalEarned == maxEarned && totalExams > doktori[maxEarnedIndex].br_pac)) {
            maxEarned = totalEarned;
            maxEarnedIndex = i;
        }
    }

    // Print the most successful doctor
    printf("Najuspesen doktor:\n");
    printf("Ime: %s\n", doktori[maxEarnedIndex].ime);
    printf("Zarabotena suma: %d\n", maxEarned);
    printf("Broj na pregledi: %d\n", doktori[maxEarnedIndex].br_pac);
}

int main() {
    int i, j, n;
    MaticenDoktor md[200];
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        //ime na doktor
        scanf("%s", md[i].ime);
        //broj na pacienti
        scanf("%d", &md[i].br_pac);
        //cena na pregled
        scanf("%f", &md[i].cena);

        for (j = 0; j < md[i].br_pac; j++) {
            scanf("%s", md[i].niza[j].ime);
            scanf("%d", &md[i].niza[j].zdrastveno);
            scanf("%d", &md[i].niza[j].pregledi);
        }
    }

    najuspesen_doktor(md, n);

    return 0;
}
