#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size;
    int i;
    int j;
    int *arr;
} queue;

int isfull(queue *ptr)
{
    return ptr->j >= ptr->size - 1;
}
int isempty(queue *ptr)
{
    return ptr->i == -1 || ptr->i > ptr->j;
}
void enqueue(queue *ptr, int x)
{
    if (isfull(ptr) == 1)
    {
        printf("cant enqueue\n");
        return;
    }
    if (ptr->i == -1)
    {
        ptr->i = 0;
    }

    ptr->j++;
    ptr->arr[ptr->j] = x;
}

int dequeue(queue *ptr)
{
    if (isempty(ptr) == 1)
    {
        printf("cant dequeue\n");
        return -1;
    }
    else
    {

        int x = ptr->arr[ptr->i];
        ptr->i++;
        return x;
    }
}

int main()
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->size = 5;
    q->i = -1;
    q->j = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
    // functions
    // Test enqueue
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60); // Should fail

    // Test dequeue
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q); // Should fail
    isempty(q);
    // Free memory
    free(q->arr);
    free(q);
}
