//Kruskal’s Algorithm using Union Find (Greedy Approach)
//weighted graph

#include <stdio.h>
#include <stdlib.h>

#define N 100006

int parent[N];
int sz[N];

void make_set(int v){
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v){
    if (v == parent[v]){
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);

    if (a != b){
        if (sz[a] < sz[b]) {
            int temp = a;
            a = b; 
            b = temp;
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int cmp(const void* a, const void* b){
    int* x = *(int(*)[3])a;
    int* y = *(int(*)[3])b;
    return x[0] - y[0];
}

int main(){
    for (int i = 0; i < N; i++)
    {
        make_set(i);
    }

    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    int edges[m][3];
    printf("Enter edges in the format vertice 1, vertice 2, weight\n");
    for (int i = 0; i < m; i++){
        int u, v, w;
        printf("Enter edge %d: ", i + 1);
        scanf("%d %d %d", &u, &v, &w);
        edges[i][0] = w;
        edges[i][1] = u;
        edges[i][2] = v;
    }

    qsort(edges, m, sizeof(edges[0]), cmp);

    int cost = 0;
    for (int i = 0; i < m; i++){
        int w = edges[i][0];
        int u = edges[i][1];
        int v = edges[i][2];
        int x = find_set(u);
        int y = find_set(v);
        if (x == y){
            continue;
        }else{
            printf("%d %d\n", u, v);
            cost += w;
            union_sets(u, v);
        }
    }
    printf("Cost: %d\n", cost);
}
