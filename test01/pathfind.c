#include <stdio.h>
#include <stdbool.h>

#define MAX_X_POSITION 10
#define MAX_Y_POSITION 10
#define MAX_QUEUE_SIZE 100

typedef struct
{
    int x;
    int y;
} position;


bool visited[MAX_X_POSITION][MAX_Y_POSITION] = { false, };
int graph[MAX_X_POSITION][MAX_Y_POSITION] = { 0, };
int movable[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

position queue[MAX_QUEUE_SIZE] = { 0, };
int rear = 0;

bool isQueueEmpty() {
    return rear == 0;
}

void enqueue(position value) {
    queue[rear++] = value;
}

position dequeue() {
    position value = queue[0];

    for (int i = 1; i < rear; i++)
    {
        queue[i-1] = queue[i];
    }

    rear--;

    return value; 
}

void bfs(position p) {
    enqueue(p);
    visited[p.x][p.y] = true;

    while (!isQueueEmpty())
    {
        position next_p = dequeue();
        printf("[%d, %d]\n", next_p.x, next_p.y);

        for (size_t i = 0; i < count; i++)
        {
            /* code */
        }
        
    }
    
}