#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void bellmanFord(int V,int AdjMat[][V],int src,int weight[]){
   
    weight[src]=0;
    for(int i=0;i<V;i++){
        for(int j =0;j<V;j++){
            if((AdjMat[i][j]!=INT_MAX)){
                
                int dist=AdjMat[i][j] + weight[i];
                
                if(dist < weight[j]){
                    weight[j]=dist;  
                }
            }
        
        }
        
    }
}



void print(int weight[],int V, int src){
    printf("Distance of each node from the source vertex\n");
    for(int i= 0;i<V;i++)
        printf("%d\t%d\n",i,weight[i]);
}


void AdjacencyMatrix(int V, int e){
        int x,y,src,wt;
        int AdjMat[V][V];
        int weight[V];
        for(int i=0;i<V;i++) {
            weight[i]=INT_MAX;
            
            for(int j=0;j<V;j++){
                AdjMat[i][j]= INT_MAX;
            }
        } 


        printf("Enter the edge and its weight\n");
        for(int i=1;i<=e;i++){
            scanf("%d%d%d",&x,&y,&wt);
            AdjMat[x][y]=wt;
            AdjMat[y][x]=wt;

            printf("\n");

        }

        printf("Enter the source vertex\n");
        scanf("%d",&src);
        bellmanFord(V,AdjMat,src,weight);
        
        print(weight,V, src);
}




int main(){
    int V, e;
    printf("Enter the  number of vertices in the graph G.\n");
    scanf("%d",&V);
   
    printf("Enter the number of edges in the graph G.\n");
    scanf("%d",&e);

    AdjacencyMatrix(V,e);

    return 0;

}
