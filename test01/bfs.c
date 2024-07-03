#include <stdio.h>
#include <stdbool.h>

#define NODE_COUNT 9
#define MAX_QUEUE_SIZE 1000

bool visited[NODE_COUNT] = {true, false, };

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

int queue[MAX_QUEUE_SIZE];
int front = 0;
int rear = 0;

bool isQueueEmpty() {
    return front == rear;
}

void enqueue(int value) {
    queue[rear++] = value;
}

int dequeue() {
    return queue[front++];
}

void bfs(int node){
    enqueue(node);
    visited[node] = true;

    while (!isQueueEmpty())
    {
        int next_node = dequeue();
        printf("%d\n", next_node);

        for (int i = 0; i < sizeof(graph[next_node]) / sizeof(graph[next_node][0]); i++)
        {
            int neighbor = graph[next_node][i];
            if (!visited[neighbor])
            {
                enqueue(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main(int args, char* argv[]) {    
    bfs(1);
    
    return 0;
}