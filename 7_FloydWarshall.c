//Floyd Warshall Algorithm using Dynamic Programming
//weight and direction

#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#define INF INT_MAX 
#define V 5 // number of vertices 

void printSolution(int dist[][V]) { 
    printf("Shortest distances between all pairs of vertices:\n"); 
    for (int i = 0; i< V; i++) { 
        for (int j = 0; j < V; j++) { 
            if (dist[i][j] == INF) { 
                printf("INF "); 
            } 
            else { 
                printf("%d ", dist[i][j]); 
            } 
        } 
        printf("\n"); 
    } 
} 
void floydWarshall(int graph[][V]) { 
    int dist[V][V], i, j, k; 
    for (i = 0; i< V; i++) { 
        for (j = 0; j < V; j++) { 
            dist[i][j] = graph[i][j]; 
        } 
    } 

    for (k = 0; k < V; k++) { 
        for (i = 0; i< V; i++) {
            for (j = 0; j < V; j++) { 
                if (dist[i][k] != INF &&dist[k][j] != INF &&dist[i][k] + dist[k][j] <dist[i][j]){ 
                    dist[i][j] = dist[i][k] + dist[k][j]; 
                } 
            } 
        } 
    } 
    printSolution(dist); 
} 

int main() { 
    int graph[V][V], i, j; 
    printf("Enter the graph in the form of an adjacency matrix:\n"); 
    for (i = 0; i< V; i++) { 
        for (j = 0; j < V; j++){ 
            scanf("%d", &graph[i][j]); 
            // -1 indicates absence of edge between vertices i and j 
            if (graph[i][j] == -1) { 
                graph[i][j] = INF; 
            } 
        } 
    } 
    floydWarshall(graph); 

    return 0; 
} 
