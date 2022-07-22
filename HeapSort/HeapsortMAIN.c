// Heapsort
// Grupo 8
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//gcc -std=c99 Heapsort.c HeapsortMAIN.c -o heap.x

void heapsort(int a[], int n);

int main(){
	
	int sizex;
	int aux;
	
	printf("Quantos valores serão gerados : ");
	scanf("%d", &sizex);
	
	int array[sizex];
	int *ptr = malloc(sizeof(int) * sizex);
	srand((unsigned)time(0));
	
	
	printf("Valores aleatórios não ordenados: ");
	for(int i = 0; i <= sizex; i++){
		
		ptr[i] = (rand() % 1000);
		printf(" %d ", ptr[i]);
	}	
	printf("\n");
	
	
	

	heapsort(ptr, sizex);
	
	printf("Valores aleatórios ordenados por heapsort: ");
	for(int i = 0; i <= sizex; i++){	
		printf(" %d ", ptr[i]);
	}
	
	
	
	return 0;
}
