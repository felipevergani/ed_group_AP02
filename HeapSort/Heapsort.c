// Heapsort
// Grupo 8
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define true 1
//gcc -std=c99 Heapsort.c HeapsortMAIN.c -o heap.x

void heapsort(int array[], int n) {
   int i = n / 2, pai, filho, t;
   while(true) {
      if (i > 0) {
          i--;
          t = array[i];
      } else {
          n--;
          if (n <= 0) return;
          t = array[n];
          array[n] = array[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (array[filho + 1] > array[filho]))
              filho++;
          if (array[filho] > t) {
             array[pai] = array[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      array[pai] = t;
   }
}