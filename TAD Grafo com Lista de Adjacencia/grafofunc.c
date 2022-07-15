// TAD Grafo usando Lista de Adjacência.
// Grupo 8.

#include <stdio.h>
#include "grafos.h"


	//Criar o grafo
	Grafo *cria_Grafo(int n_vertices, int grau_max, int ponderado){
		Grafo *gr=(Grafo*) malloc(sizeof(struct Grafo));
		if(gr != NULL){
			int i;
			gr->n_vertices = n_vertices;
			gr->grau_max = grau_max;
			gr->ponderado = (ponderado != 0)?1:0;
			gr->grau=(int*)calloc(n_vertices, sizeof(int));
			gr->arestas=(int**)malloc(n_vertices*sizeof(int*));
			
			for(i=0; i < n_vertices; i++){
				gr->arestas[i]=(int*)malloc(grau_max*sizeof(int));
			}
			if(gr->ponderado){
				gr->pesos=(float**)malloc(n_vertices*sizeof(float*));
				
				for(i=0; i < n_vertices; i++)
					gr->pesos[i] = (float*)malloc(grau_max*sizeof(float));
			}
		}
		return gr;
	}
	
	//Liberar grafo
	
	void libera_Grafo(Grafo* gr){
		if(gr != NULL){
			int i;
			for(i = 0; i < gr->n_vertices; i++){
				free(gr->arestas[i]);
			}
			free(gr->arestas);
			
			if(gr->ponderado){
				for(i=0; i<gr->n_vertices; i++){
					free(gr->pesos[i]);
				}
				free(gr->pesos);
			}
			free(gr->grau);
			free(gr);
		}
	}
	
	int insereAresta(Grafo* gr, int origem, int destin, int digrafo, float peso){
	//Verificação se existe
		if(gr == NULL) return 0;
		
		if(origem < 0 || origem >= gr->n_vertices) return 0;
		
		if(destin < 0 || destin >= gr->n_vertices) return 0;
		
		gr->arestas[origem][gr->grau[origem]] = destin;
		if(gr->ponderado){
			gr->pesos[origem][gr->grau[origem]] = peso;
			gr->grau[origem]++;
		}
		
		if(digrafo == 0){
			insereAresta(gr, destin, origem, 1, peso);
		}
		
		return 1;
	}
	
	int removeAresta(Grafo* gr, int origem, int destin, int digrafo){
	//Verificação se existe
		if(gr == NULL) return 0;
		
		if(origem < 0 || origem >= gr->n_vertices) return 0;
		
		if(destin < 0 || destin >= gr->n_vertices) return 0;
		
		int i=0;
		while(i<gr->grau[origem] && gr->arestas[origem][i]!=destin){
			i++;
			if(i == gr->grau[origem]) return 0;	//Elemento não encontrado
		}
		gr->grau[origem]--;
		gr->arestas[origem][i]=gr->arestas[origem][gr->grau[origem]];
			
		if(gr->ponderado){
			gr->pesos[origem][i]=gr->pesos[origem][gr->grau[origem]];
		}
			
		if(digrafo == 1){
			removeAresta(gr, destin, origem, 1);
		}
		
		return 1;
	}