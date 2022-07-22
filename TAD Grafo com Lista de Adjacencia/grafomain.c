
// TAD Grafo usando Lista de Adjacência.
// Grupo 8.
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
	
	GRAFO * gr = criaGrafo(5);
	criaAresta(gr, 0, 1, 2);
	criaAresta(gr, 1, 2, 4);
	criaAresta(gr, 2, 0, 12);
	criaAresta(gr, 2, 4, 40);
	criaAresta(gr, 3, 1, 3);
	criaAresta(gr, 4, 3, 8);
	profundida(gr);
	
    
    imprime(gr);
}