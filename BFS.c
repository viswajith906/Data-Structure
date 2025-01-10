#include <stdio.h>
#include <stdlib.h>

#define max_size 3

int adjmtx[max_size][max_size], bfsqueue[max_size], visited[max_size], s;
int front = -1, rear = -1, data, v, i, j;

int enqueue(int v) {
    if (front == (max_size - 1)) {
        printf("Queue is full\n");
        exit(1);
    }
    if ((front == -1) && (rear == -1)) {
        front++;
    }
    rear++;
    bfsqueue[rear] = v;
}

int dequeue() {
    if ((front == -1) && (rear == -1)) {
        printf("Queue is empty\n");
        exit(0);
    }
    data = bfsqueue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    front++; // Increment front to remove the dequeued element
    return data;
}

int bfs(int s) {
    enqueue(s);
    visited[s] = 1;
    printf("\n BFS order of graph is: ");
    while ((front != -1) && (rear != -1)) {
        v = dequeue();
        printf("%d ", v);
        for (i = 0; i < max_size; i++) {
            if (adjmtx[v][i] == 1) {
                if (visited[i] != 1) {
                    enqueue(i);
                    visited[i] = 1;
                }
            }
        }
    }
}

void main() {
    printf("\n Enter source vertex: ");
    scanf("%d", &s);

    printf("\n Enter the elements of adjacent matrix:\n");
    for (i = 0; i < max_size; i++) {
        for (j = 0; j < max_size; j++) {
            scanf("%d", &adjmtx[i][j]);
        }
    }

    bfs(s);
    printf("\n");
}