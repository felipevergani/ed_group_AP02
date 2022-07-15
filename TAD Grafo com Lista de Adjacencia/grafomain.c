// TAD Grafo usando Lista de Adjacência.
// Grupo 8.
// compilar e linkar -> gcc -std=c99 grafomain.c grafofunc.c -o teste.exe

#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

int main(){
	
	//Criar o grafo
	
	Grafo *cria_Grafo(int n_vertices, int grau_max, int ponderado);
	void libera_Grafo(Grafo* gr);
	int insereAresta(Grafo* gr, int origem, int destin, int digrafo, float peso);
	int removeAresta(Grafo* gr, int origem, int destin, int digrafo);
	
	
	Grafo *gr;
	gr = cria_Grafo(10, 7, 0);
	insereAresta(gr, 0, 1, 0, 0);
	insereAresta(gr, 1, 3, 0, 0);
	removeAresta(gr, 0, 1, 0);
	
	libera_Grafo(gr);
	
	
	return 0;
};