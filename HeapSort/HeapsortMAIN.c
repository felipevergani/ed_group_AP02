// Heapsort
// Grupo 8
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//Felipe Brun Vergani
//gcc -std=c99 Heapsort.c HeapsortMAIN.c -o heap.x

void heapsort(int a[], int n);

int main(){
	
	FILE *opn;
	opn = fopen("resultados.txt", "a+");
	int sizex;
	int aux;
	
	printf("Quantos valores serão gerados : ");
	scanf("%d", &sizex);
	
	int array[sizex];
	int *ptr = malloc(sizeof(int) * sizex);
	srand((unsigned)time(0));
	
	
	fprintf(opn,"Valores aleatórios não ordenados: \n");
	for(int i = 0; i < sizex; i++){
		
		ptr[i] = (rand() % 1000);
		fprintf(opn," %d", ptr[i]);
	}	
	fprintf(opn,"\n");
	
	
	

	heapsort(ptr, sizex);
	
	fprintf(opn,"Valores aleatórios ordenados por heapsort: \n");
	for(int i = 0; i < sizex; i++){	
		fprintf(opn," %d", ptr[i]);
	}
	fprintf(opn,"\n");
	
	fclose(opn);
	
	return 0;
}
