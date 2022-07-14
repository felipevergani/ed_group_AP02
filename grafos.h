// TAD Grafo usando Lista de Adjacência.
// Grupo 8.

#include <stdio.h>
#include <stdlib.h>

typedef struct Grafo{
	int ponderado;
	int n_vertices;
	int grau_max;
	int** arestas;
	float** pesos;
	int* grau;
}Grafo;


Grafo *cria_Grafo(int n_vertices, int grau_max, int ponderado);
void libera_Grafo(Grafo* gr);
int insereAresta(Grafo* gr, int origem, int destin, int digrafo, float peso);
int removeAresta(Grafo* gr, int origem, int destin, int digrafo);
	

