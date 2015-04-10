#include "graph.h"
#include <time.h>
#include <stdlib.h>

/**
 * Inicia um grafo conectado aleatório
 */
int** newGraph(int qtdNodes){
  int** linhas = malloc(qtdNodes * sizeof(int*));
  int* valores = calloc(qtdNodes*qtdNodes, sizeof(int));
  
  for(int i = 0; i< qtdNodes; i++){
    linhas[i] = valores + i*qtdNodes;
  }
  return linhas;
}


void initGraph(int** graph, int qtdNodes){
  srand(time(NULL));
  for (int i = 0; i< qtdNodes; i++){
    for(int j = i+1; j< qtdNodes; j++){
      graph[i][j] = (rand() % 100) + 1;
    }
  }
}
