#include <stdio.h>
#include <stdbool.h>

#define MAX_X_POSITION 7
#define MAX_Y_POSITION 7
#define MAX_QUEUE_SIZE 100

typedef struct
{
    int x;
    int y;
} position;

int map[MAX_X_POSITION][MAX_Y_POSITION] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {1, 1, 0, 1, 0, 1, 1},
        {1, 1, 0, 1, 0, 0, 0},
        {1, 0, 0, 0, 1, 0, 0},
        {1, 0, 1, 0, 0, 0, 0}
    };

bool visited[MAX_X_POSITION][MAX_Y_POSITION] = { false, };
int distance[MAX_X_POSITION][MAX_Y_POSITION] = { 0, };
                // Move      Up     Right   Down    Left
position movable[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

position queue[MAX_QUEUE_SIZE];
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

void bfs(position start, position destination) {
    enqueue(start);
    visited[start.x][start.y] = true;

    while (!isQueueEmpty())
    {
        position current_position = dequeue();
        int current_distance = distance[current_position.x][current_position.y];
        printf("[%d, %d]\n", current_position.x, current_position.y);

        if (current_position.x == destination.x && current_position.y == destination.y)
        {
            break;
        }
        

        // Move to next position
        for (int i = 0; i < 4; i++) 
        {
            position neighbor;
            neighbor.x = current_position.x + movable[i]->x;
            neighbor.y = current_position.y + movable[i]->y;

            // Out of Maps' Range or cannot move to the position
            if ((neighbor.x < 0) || (neighbor.y < 0) || (neighbor.x >= MAX_X_POSITION) || (neighbor.y >= MAX_Y_POSITION) || (map[neighbor.x][neighbor.y] == 1)) 
            {
                continue;
            }

            if (!visited[neighbor.x][neighbor.y] && distance[neighbor.x][neighbor.y] == 0)
            {
                distance[neighbor.x][neighbor.y] = current_distance + 1;
            }
            

            if (!visited[neighbor.x][neighbor.y] && (current_distance + 1) <= distance[neighbor.x][neighbor.y])
            {
                enqueue(neighbor);
                visited[neighbor.x][neighbor.y] = true;
                distance[neighbor.x][neighbor.y] = current_distance + 1;
            }  
        }
    }
}

void printMap(int map[MAX_X_POSITION][MAX_Y_POSITION]){
    for (int i = 0; i < MAX_X_POSITION; i++)
    {
        for (int j = 0; j < MAX_Y_POSITION; j++)
        {
            printf("%4d ", map[i][j]);
        }
        printf("\n");
    }
    
}

int main(int args, char* argv[]) {
    position start = {0, 0};
    position destination = {MAX_X_POSITION-1, MAX_Y_POSITION-1};

    bfs(start, destination);

    printMap(distance);

    printf("%d", distance[destination.x][destination.y]);

    return 0;
}