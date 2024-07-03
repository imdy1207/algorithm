#include <stdio.h>
#include <stdbool.h>

#define NODE_COUNT 9

int graph[NODE_COUNT][NODE_COUNT] = {
    {}, // Node0 (Not Used)
    {2, 3, 4},  // Node1
    {1, 5, 6},  // Node2
    {1},        // Node3
    {1, 7},     // Node4
    {2, 8},     // Node5
    {2, 8},     // Node6
    {4},        // Node7
    {5, 6}      // Node8
};

bool visited[NODE_COUNT] = {true, false, };

void dfs(int node) {
    printf("%d\n", node);
    visited[node] = true;

    for (int i = 0; i < sizeof(graph[node])/sizeof(graph[node][0]); i++)
    {
        int neighbor = 0;
        neighbor = graph[node][i];

        if (!visited[neighbor])
        {
            dfs(neighbor);
        } 
    }
}

int main(int args, char* argv[]) {    
    dfs(1);

    return 0;
}