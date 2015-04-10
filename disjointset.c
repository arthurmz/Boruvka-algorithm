#include "disjointset.h"
#include <stdlib.h>


Node * create_set(int id){
  Node * set = malloc(sizeof(Node));
  set->id = id;
  set->rank = 0;//número de arestas do caminho mais longo desse nó pra baixo
  set->parent = set;
  return set;
  
}


/**
 * União por rank:
 * Fazer a raiz da arvore com menos nós apontar pra
 * arvore com mais nós.
 * 
 * Complexidade O((m+n)a())
 */
void merge_set(Node * x, Node * y){
  Node *Px = find_set(x);
  Node *Py = find_set(y);
  if(Px->rank > Py->rank){
    Py->parent = Px;
    Px->rank++;
  }
  else{
    Px->parent = Py;
    Py->rank++;
  }
}

/**
 * Compressão de caminho:
 * Após achar a raiz v de um nó u
 * repete mais uma vez o caminho, dessa vez
 * apontando o pai de cada nó diretamente pra v
 * Complexidade O((m+n)a())
 */
Node * find_set(Node * x){
  Node * temp = x;
  while(x->parent != x)
    x = x->parent;
  
  //comprimindo o caminho
  Node *next;
  while(temp->parent != temp){
    next = temp->parent;
    temp->parent = x;
    temp = next;
  }
  return x;
}