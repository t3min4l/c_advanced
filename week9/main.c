#include <libfdr/jrb.h>
#include <libfdr/jval.h>
#include <libfdr/dllist.h>
#include <libgraph/graph.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printNode(int a)
{
  printf("%d\n", a);
}


int main(){

  Graph graph = createGraph();
  addVertex(graph, 0, "Tran Hung Dao");
  addVertex(graph, 1, "Tran Duy Hung");
  addVertex(graph, 2, "Tran Dai Nghia");
  addVertex(graph, 3, "Tran Quang Khai");
  addVertex(graph, 4, "Tran Dai Quang");
  addVertex(graph, 5, "Dinh Bo Linh");
  addVertex(graph, 6, "Dinh Anh Dung");
  addVertex(graph, 7, "Dinh Canh Nam");


  addEdge(graph, 1, 2, 1.0);
  addEdge(graph, 0, 1, 2.0);
  addEdge(graph, 0, 3, 2.5);
  addEdge(graph, 0, 4, 2.8);
  addEdge(graph, 0, 6, 1.6);
  addEdge(graph, 1, 7, 1.9);
  addEdge(graph, 1, 3, 3.2);
  addEdge(graph, 1, 5, 4.0);
  addEdge(graph, 2, 1, 4.8);
  addEdge(graph, 2, 6, 5.2);
  addEdge(graph, 2, 7, 5.9);
  addEdge(graph, 3, 0, 7.0);
  addEdge(graph, 3, 4, 4.7);
  addEdge(graph, 3, 2, 2.9);
  addEdge(graph, 3, 6, 3.5);
  addEdge(graph, 4, 2, 1.9);
  addEdge(graph, 4, 1, 3.3);
  addEdge(graph, 4, 7, 8.9);
  addEdge(graph, 4, 0, 9.0);
  addEdge(graph, 5, 1, 3.3);
  addEdge(graph, 5, 2, 1.7);
  addEdge(graph, 5, 3, 8.9);
  addEdge(graph, 5, 4, 9.1);
  addEdge(graph, 6, 7, 10.0);
  addEdge(graph, 6, 0, 8.9);
  addEdge(graph, 6, 2, 7.2);
  addEdge(graph, 7, 3, 7.5);
  addEdge(graph, 7, 6, 1.0);
  addEdge(graph, 7, 4, 4.0);

  DFS(graph, 0, &printNode);
  Dllist path = new_dllist();
  double *length = (double *)malloc(sizeof(double));
  double d = shortestPath(graph, 0, 7, path);
  Dllist ptr;
  printf("shortest path\n");
  dll_traverse(ptr, path){
    printf("%d\n", jval_i(ptr->val));
  };
  printf("best value from 0 - 7 %f\n", d);

  path = topologicalOrder(graph);
  if(path == NULL){
    printf("DAG graph can not perform\n");
  };
  if(path != NULL)
  {
    dll_traverse(ptr, path)
    {
    printf("%d\n", jval_i(ptr->val));
    }
  };
  printf("test 2\n");

  Graph test_topo = createGraph();

  addVertex(test_topo, 0, "Dinh Anh Dung");
  addVertex(test_topo, 1, "Dinh Bo Linh");
  addVertex(test_topo, 2, "Tran Quang Khai");
  addVertex(test_topo, 3, "Tran Hung Dao");
  addVertex(test_topo, 4, "Nguyen Hue");
  addVertex(test_topo, 5, "Gia Long");
  addVertex(test_topo, 6, "Tran Dai Nghia");

  addEdge(test_topo, 1, 2, 0.5);
  addEdge(test_topo, 0, 2, 0.5);
  addEdge(test_topo, 1, 3, 0.5);
  addEdge(test_topo, 2, 4, 0.5);
  addEdge(test_topo, 2, 5, 0.5);
  addEdge(test_topo, 2, 6, 0.5);


  DFS(test_topo, 0, &printNode);
  path = topologicalOrder(test_topo);
  if(path == NULL)
  {
    printf("also can not perform");
  }
  if(path != NULL)
  {
    dll_traverse(ptr, path)
    {
      printf("%d\n", jval_i(ptr->val));
    }
  }

  return 0;
}