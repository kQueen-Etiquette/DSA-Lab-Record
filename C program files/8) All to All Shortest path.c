#include <stdio.h>
#include <stdlib.h>
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
int V;
 
void PrintGraph(int graph[V][V]);
void ShortestPath(int graph[V][V]);
 
int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    int graph[V][V];
    printf("Enter '99999' for infinity!!\n");
    for (int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            printf("Enter the weight of the edge[%d][%d]: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
    ShortestPath(graph);
    return;
}

void ShortestPath(int graph[V][V]){
    for(int k = 0; k < V; k++){
        for(int j = 0; j < V; j++){
            for(int i = 0; i < V; i++){
                graph[i][j] = MIN(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    PrintGraph(graph);
}
 
void PrintGraph(int graph[V][V]){
    printf("All to All Shortest paths matrix \n");
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            if (graph[i][j] == 99999){
                printf(" INF ");
            }
            else{
                printf("  %d  ", graph[i][j]);
            }
        }
        printf("\n");
    }
}