#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int V, E, graph[100][100], src;

void dijkstra(int graph[V][V], int src) {
	
	int dist[V]; //distance to each vertex
	int sptSet[V]; //set to keep track of visited vertices
	int min_dist;	
	//initialising all distances to infinity and marking all vertices as not visited
	for(int v=0;v<V;v++) {
		dist[v]=INT_MAX;
		sptSet[v]=0;
	}

	dist[src]=0;
//	sptSet[src]=1;
	
	for(int count=1;count<V-1;count++) {
		min_dist=INT_MAX;
		int u;
		for(int i=0;i<V;i++) {
			if(dist[i]<min_dist && sptSet[i]==0) {
				min_dist=dist[i];
				u=i;
			}
		}

		sptSet[u]=1;
		for(int v=0;v<V;v++) {
			if(graph[u][v] && sptSet[v]==0 && dist[u]+graph[u][v]<dist[v])
				dist[v]=dist[u]+graph[u][v];
		}

	}

	printf("Distances of each node from source %d\n", src);
	for(int i=0;i<V;i++) 
		printf("%d\t%d\n", i, dist[i]);
	
}

int main() {
	int i,j,v1,v2, wt;
   	printf("Graphs\n");
	printf("Enter the no of vertices:");
	scanf("%d",&V);
   	printf("Enter the no of edges:");
    	scanf("%d",&E);

    	for(i=0;i<V;i++) {
        	for(j=0;j<V;j++)
            		graph[i][j]=0;
    	}

    	for(i=0;i<E;i++) {
        	printf("Enter the edges and their weights: ");
	        scanf("%d%d%d",&v1,&v2,&wt);
	        graph[v1][v2]=wt;
		graph[v2][v1]=wt;
	}

    	for(i=0;i<V;i++) {
        	for(j=0;j<V;j++)
	            printf(" %d ",graph[i][j]);
        	printf("\n");
    	}	

	printf("Enter the source: ");
	scanf("%d",&src);
	
	dijkstra(graph, src);

	return 0;
}
