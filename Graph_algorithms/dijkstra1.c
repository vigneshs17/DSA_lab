#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int findMinvertex(int weight[], int visited[],int V){
    int minvertex=-1;
    for(int i=0;i<V;i++){
        if(visited[i]==0 && (minvertex==-1 || weight[i]< weight[minvertex])){
            minvertex=i;
        }
    }
    return minvertex;
}
    
void dijkstra(int V,int AdjMat[][V],int src,int visited[], int weight[]){
   
    weight[src]=0;
    for(int i=0;i<V;i++){
        int minvertex=findMinvertex(weight,visited,V);
        visited[minvertex]=1;
        for(int j =0;j<V;j++){
            
            if(visited[j]==0 && (AdjMat[minvertex][j]!=INT_MAX)){
                
                int dist=AdjMat[minvertex][j] + weight[minvertex];
                
                if(dist < weight[j]){
                    weight[j]=dist;  
                }
            }
        
        }
        
    }
}


// Function to display minimum spanning Tree
void display(int visited[],int weight[],int V, int src){
    printf("Distance of each vertex from the source %d\n", src);
    for(int i= 0;i<V;i++)
        printf("%d\t%d\n",i,weight[i]);
}

// Function to create Adjacency Matrix
void AdjacencyMatrix(int V, int e){
        int x,y,src,wt;      

        int AdjMat[V][V];    
        int visited[V]; 
        int weight[V];
       
        for(int i=0;i<V;i++){
            //initially mark all te vertices unvisited 
            visited[i]=0;
            
            //initially weight of each vertex is Infinity
            weight[i]=INT_MAX;
            
            // initially edge weight is infinityn for all the edges
            for(int j=0;j<V;j++){
                AdjMat[i][j]= INT_MAX;
            }
        } 


        printf("Enter the edges and its weight\n");
        for(int i=1;i<=e;i++){
            scanf("%d%d%d",&x,&y,&wt);

            AdjMat[x][y]=wt;
            AdjMat[y][x]=wt;
        }

        printf("Enter the source vertex\n");
        scanf("%d",&src);
        dijkstra(V,AdjMat,src,visited,weight);
        
        display(visited,weight,V, src);
}




int main(){
    int V , e;
    printf("Enter the  number of vertices in the graph G.\n");
    scanf("%d",&V);

    printf("Enter the number of edges in the graph G.\n");
    scanf("%d",&e);

    AdjacencyMatrix(V,e);

    return 0;

}
