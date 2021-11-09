#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define initial 1
#define visited 2
int n;
int adj[MAX][MAX];
int state[MAX];
void create_graph()
{
 int count,max_edge,origin,destin;
 printf("Enter number of vertices : "); 
 scanf("%d", &n);
 max_edge = n * (n-1);
 for(count=1; count<=max_edge; count++)
 {
  printf("Enter edge %d( -1 -1 to quit ) : ",count); 
  scanf("%d %d", &origin,&destin);
  if((origin == -1) && (destin == -1)) 
  break;
  else if(origin>=n || destin>=n || origin<0 || destin<0)
  {
    printf("Invalidedge!\n"); 
    count--;
  }
  else
  {
   adj[origin][destin] = 1;
  }
 }
}
void DFS(int v)
{
  printf("%d ",v);
  int i; 
  state[v] = visited; 
  for(i=0; i<n; i++)
  {
   if(adj[v][i] == 1 && state[i] == initial)
   {
    DFS(i);
   }
  }
}
void DF_Traversal()
{
  int vertex,v;
  for(v=0; v<n; v++) 
  state[v] = initial;
  printf("Enter Start Vertex for BFS: ");
  scanf("%d", &vertex);
  printf("\nDepth first search:");
  DFS(vertex);
}
int main()
{
  create_graph(); 
  DF_Traversal(); 
  return 0;
}



