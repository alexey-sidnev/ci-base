#include "Graph.h"

void main() {
  edge a;
  edg(0, 1, 1, &a);
  edge b;
  edg(1, 2, 4, &b);
  edge c;
  edg(2, 3, 5, &c);
  edge d;
  edg(3, 4, 3, &d);
  edge e;
  edg(1, 3, 1, &e);
  edge f;
  edg(1, 4, 1, &f);
  edge g;
  edg(0, 4, 2, &g);
  edge r[7] = { a, b, c, d, e, f, g };
  Graph g1;
  gr(5, 7, r, &g1);
  Graph h;
  Kruskal(&g1, &h);
  Print(&h);
}
