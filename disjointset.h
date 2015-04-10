#ifndef _DISJOINT_SET_
#define _DISJOINT_SET_

typedef struct n{
  int id;
  int rank;
  struct n *parent;
} Node;


Node * create_set(int id);
Node * find_set(Node * x);
void merge_set(Node * x, Node * y);




#endif
