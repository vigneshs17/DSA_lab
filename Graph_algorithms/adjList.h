//create a graph using adjacency list
#include<stdio.h>
#include<stdlib.h>

//a structure to represent an adjacency list node
struct AdjListNode {
    int dest;
    struct AdjListNode *next;
};

//a structure to represent an adjacency list
struct AdjList {
    struct AdjListNode *head;
};

//a structure to represent a graph with vertices and edges. 
//a graph is an array of adjacency lists
struct Graph {
    int V; //number of vertices
    struct AdjList *array;
};

//function to add a new node
struct AdjListNode* addNewNode(int dest) {
    struct AdjListNode *newNode=(struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest=dest;
    newNode->next=NULL;
    return newNode;
}

//function to create a graph of V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->V=V;

    //create an array of adjacency lists, size of the array will be V 
    graph->array=(struct AdjList*)malloc(sizeof(struct AdjList)*V);

    //initialise each adjacency list by making each node as NULL
    for(int i=0;i<V;i++) 
        graph->array[i].head=NULL;
    return graph;
}

//function to add a new edge to an undirected graph
void addEdge(struct Graph *graph, int src, int dest) {
    struct AdjListNode *newNode=addNewNode(dest);
    newNode->next=graph->array[src].head;
    graph->array[src].head=newNode;
    //since the graph is undirected, add an edge the other way also 
    newNode=addNewNode(src);
    newNode->next=graph->array[dest].head;
    graph->array[dest].head=newNode;
}

//function to print the adjacency list of the graph
void printGraph(struct Graph *graph) {
    int v;
    for(v=0;v<graph->V;++v) {
        struct AdjListNode *pCrawl=graph->array[v].head;
        printf("Adjacency list of vertex %d\n head",v);
        while(pCrawl) {
            printf("->%d", pCrawl->dest);
            pCrawl=pCrawl->next;
        }
        printf("\n");
    }
}

int main() {
    int V,E,u,v;
    printf("Enter the number of vertices: ");
    scanf("%d",&V);
    struct Graph *graph=createGraph(V);
    printf("Enter the number of edges: ");
    scanf("%d",&E);
    printf("Enter the source and destination\n");
    for(int i=0;i<E;i++) {
        scanf("%d %d", &u,&v);
        addEdge(graph,u,v);
    }
    printGraph(graph);
    return 0;
}
