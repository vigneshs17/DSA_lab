#include <stdio.h>
#include<stdlib.h>

#define QUEUE_SIZE 20
#define MAX 20

int queue[QUEUE_SIZE];
int queue_front, queue_end;
void enqueue(int v);
int dequeue();

void bfs(int source);
int source,V,E,time,visited[20],G[20][20];

int main(void) {
    int i,j,v1,v2, V, E;
    printf("Graphs\n");
    printf("Enter the no of vertices:");
    scanf("%d",&V);
    printf("Enter the no of edges:");
    scanf("%d",&E);
    
    for(i=0;i<V;i++) {
        for(j=0;j<V;j++)
            G[i][j]=0;
    }
    
    for(i=0;i<E;i++) {
        printf("Enter the edges: ");
        scanf("%d%d",&v1,&v2);
        G[v1-1][v2-1]=1;
    }

    for(i=0;i<V;i++) {
        for(j=0;j<V;j++)
            printf(" %d ",G[i][j]);
        printf("\n");
    }

    printf("Enter the source: ");
    scanf("%d",&source);
  
    bfs(source-1);
  
  return 0;
}

void bfs(int source) {
  //variables
  int i, j;
  
  //visited array to flag the vertex that
  //were visited
  int visited[MAX];

  //queue
  queue_front = 0;
  queue_end = 0;
  
  //set visited for all vertex to 0 (means unvisited)
  for(i = 0; i < MAX; i++) {
    visited[i] = 0;
  }
  
  //mark the visited source
  visited[source] = 1;
  
  //enqueue visited vertex
  enqueue(source);
  
  //print the vertex as result
  printf("%d ", source);
  
  //continue till queue is not empty
  while(queue_front <= queue_end) {
    //dequeue first element from the queue
    i = dequeue();
    
    for(j = 0; j < V; j++) {
      if(visited[j] == 0 && G[i][j] == 1) {
        //mark vertex as visited
        visited[j] = 1;
        
        //push vertex into stack
        enqueue(j);
        
        //print the vertex as result
        printf("%d ", j);
      }
    }
  }
  printf("\n");
}

void enqueue(int v) {
  queue[queue_end] = v;
  queue_end++;
}

int dequeue() {
  int index = queue_front;
  queue_front++;
  return queue[index];
}