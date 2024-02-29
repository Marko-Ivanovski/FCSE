#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

typedef enum { Touch, noTouch } Ekran;

typedef struct Laptop {
  char brand[100];
  float monitorSize;
  bool touch;
  int price;
} Laptop;

typedef struct ITStore {
  char name[100];
  char location[100];
  Laptop array[100];
  int n;
} ITStore;

void print(ITStore *array, int n) {
  for (int i = 0; i < n; i++) {
    printf("%s %s\n", array[i].name, array[i].location);
    for (int j = 0; j < array[i].n; j++) {
      printf("%s %g %d\n", array[i].array[j].brand,
             array[i].array[j].monitorSize, array[i].array[j].price);
    }
  }
}

void najeftina_ponuda(ITStore *array, int n) {
  int minCena = 99999999;  // initialize with a large value
  int minIndex = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < array[i].n; j++) {
      if (array[i].array[j].touch && array[i].array[j].price < minCena) {
        minIndex = i;
        minCena = array[i].array[j].price;
      }
    }
  }
  if (minIndex != -1) {
    printf("Najeftina ponuda ima prodavnicata:\n");
    printf("%s %s\n", array[minIndex].name, array[minIndex].location);
    printf("Najniskata cena iznesuva: %d", minCena);
  } 
}

int main() {
  ITStore s[100];
  int n;
  scanf("%d", &n);  // broj na IT prodavnici
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i].name);
    scanf("%s", s[i].location);
    scanf("%d", &s[i].n);
    for (int j = 0; j < s[i].n; j++) {
      scanf("%s", s[i].array[j].brand);
      scanf("%f", &s[i].array[j].monitorSize);
      scanf("%d", &s[i].array[j].touch);
      scanf("%d", &s[i].array[j].price);
    }
  }
  print(s, n);
  najeftina_ponuda(s, n);

  return 0;
}
