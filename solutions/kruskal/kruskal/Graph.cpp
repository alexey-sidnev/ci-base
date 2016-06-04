#include "Graph.h"

void edg(int a, int b, int _size, edge* r) {
  r->a = a;
  r->b = b;
  r->size = _size;
}

void gr(int nodes, int edgees, edge* ed, Graph *g) {
  g->edgee = edgees;
  g->node = nodes;
  g->edges = new edge[edgees];
  for (int i = 0; i < edgees; i++)
    g->edges[i] = ed[i];
  for (int i = 0; i < edgees; i++)
    for (int j = edgees - 1; j > i; j--)
      if (g->edges[j - 1].size < g->edges[j].size) {
        edge tmp = g->edges[j - 1];
        g->edges[j - 1] = g->edges[j];
        g->edges[j] = tmp;
      }
}

void Print(Graph *g) {
  for (int i = 0; i < g->edgee; i++)
    std::cout << g->edges[i].a << " - " << g->edges[i].b << "; \n";
}

void Kruskal(Graph *g, Graph *ostov) {
  std::stack <edge> st;
  Sets s(g->node);
  int n = g->node;
  ostov->node = n;
  ostov->edgee = n - 1;
  ostov->edges = new edge[n - 1];
  for (int i = 0; i < n; i++)
    s.creat(i);
  for (int i = 0; i < g->edgee; i++)
    st.push(g->edges[i]);
  int t = 0;
  while ((st.empty() != 1) && t < n - 1) {
    edge tmp = st.top();
    st.pop();
    if (s.search(tmp.a) != s.search(tmp.b)) {
      ostov->edges[t] = tmp;
      t++;
      s.merge(tmp.a, tmp.b);
    }
  }
}
