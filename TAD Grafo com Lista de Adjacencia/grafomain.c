
// TAD Grafo usando Lista de Adjacência.
// Felipe Brun Vergani
// compilar e linkar -> gcc -std=c99 grafomain.c grafofunc.c -o teste.exe


#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#include "struct.h"
typedef int bool;
typedef int TIPOPESO;



int main()
{
	
	GRAFO * gr = criaGrafo(10);
	criaAresta(gr, 0, 1, 2);
	criaAresta(gr, 1, 2, 4);
	criaAresta(gr, 2, 0, 12);
	criaAresta(gr, 2, 4, 40);
	criaAresta(gr, 3, 1, 3);
	profundida(gr);
	
    
    imprime(gr);
}