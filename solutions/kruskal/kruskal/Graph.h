#ifndef SOLUTIONS_KRUSKAL_KRUSKAL_GRAPH_H_
#define SOLUTIONS_KRUSKAL_KRUSKAL_GRAPH_H_

#include <iostream>
#include <stack>
#include "Set.h"

struct edge {
  int a;
  int b;
  int size;
};

struct Graph {
  int node;
  int edgee;
  edge* edges;
};

void edg(int, int, int, edge*);
void gr(int, int, edge*, Graph*);
void Print(Graph *g);
void Kruskal(Graph*, Graph*);

#endif  // SOLUTIONS_KRUSKAL_KRUSKAL_GRAPH_H_
