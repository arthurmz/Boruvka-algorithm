#include "disjointset.h" 
#include "graph.h"
#include "avaliacaotempo.h"
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <math.h>

int TAMANHO = 70000;

void printGrafo(int** grafo, char* nomeArquivo){
  FILE *fp = fopen(nomeArquivo, "w");
  
  for (int i = 0; i< TAMANHO; i++){
    fprintf(fp, "[");
    for(int j = 0; j< TAMANHO; j++){
     fprintf(fp, "%d, ",grafo[i][j]);
    }
    fprintf(fp, "]\n");
  }
}


int** boruvka(int** grafo){
  int ** MST = newGraph(TAMANHO);
  
  int qtdConjuntos = TAMANHO;  
  Node* conjuntos[TAMANHO];//ao longo do tempo, cada nó desse array vai deixar de ser uma raiz
  
  for(int i = 0; i < TAMANHO; i++){
    conjuntos[i] = create_set(i);
  }
  

  //loop
   while (qtdConjuntos > 1){
     printf("Tamanho: %d\n",qtdConjuntos);
     for(int p = 0; p < TAMANHO; p++){ if(find_set(conjuntos[p]) == conjuntos[p]){//pra cada componente conexa de T
	//Definie o conjunto atual
      	Node * conjuntoAtual = conjuntos[p];
	
	//inicialia o peso da menor aresta
	int peso = INT_MAX;
	Node * noA;
	Node * noB;
	
 	for (int i = 0; i < TAMANHO; i++){ if (find_set(conjuntos[i]) == conjuntoAtual){//pra cada vértice dentro da componente 
 	    //encontrar aresta mais barata do vértice atual (todosOsNos[i]) para os vértices que não estão em C
 	    //iterar sobre os que não estão em c, verificar o peso da aresta e colocar o menor
 	    for (int k = 0; k < TAMANHO; k++){
 	      if (find_set(conjuntos[k]) != conjuntoAtual && grafo[i][k] > 0 && grafo[i][k] < peso){
 		peso = grafo[i][k];
 		noA = conjuntos[i];
 		noB = conjuntos[k];
 	      }
 	    }//no fim achou o menor peso desse nó
 	}}//e no fim desse achou o menor peso do componente como mundo externo, nem precisa de uma lista
 	if(peso < INT_MAX && peso > 0){
 	  merge_set(noA, noB);
 	  MST[noA->id][noB->id] = peso;
 	  qtdConjuntos--;
 	} 
     }}
   }
     
   return MST;
  
}


int main(){
  printf("Informe a quantidade de vértices: ");
  scanf("%d",&TAMANHO);
  struct timeval tvBegin, tvEnd, tvDiff;
  
  // begin
  gettimeofday(&tvBegin, NULL);
  //timeval_print(&tvBegin);

  int** grafo = newGraph(TAMANHO);
  initGraph(grafo, TAMANHO);
  printf("Matriz do grafo inicial:\n");
  //printGrafo(grafo);
  int** arvore = boruvka(grafo);
  
  //printGrafo(arvore);
  
  //end
  gettimeofday(&tvEnd, NULL);
  //timeval_print(&tvEnd);
  
  // diff
  timeval_subtract(&tvDiff, &tvEnd, &tvBegin);
  printf("Computação concluída, tempo gasto:%ld.%06ld\n", tvDiff.tv_sec, tvDiff.tv_usec);
  
  printGrafo(grafo, "grafo_original.txt");
  printGrafo(arvore, "arvore_resultante.txt");
   
  return 0;
}