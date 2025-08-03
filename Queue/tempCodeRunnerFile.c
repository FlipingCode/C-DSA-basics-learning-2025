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
    if (((ptr->j + 1) % ptr->size) == ptr->i)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty(queue *ptr)
{
    if (ptr->i == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(queue *ptr, int x)
{
    if (isfull(ptr) == 1)
    {
        printf("cant enqueue\n");
        return;
    }
    else
    {
        if (isempty(ptr) == 1)
        {
            ptr->i = 0;
            ptr->j = 0;
        }
        else
        {
            ptr->j = (ptr->j + 1) % ptr->size;
        }
        ptr->arr[ptr->j] = x;

        printf("current number enqueue %d is %d\n", ptr->j, ptr->arr[ptr->j]);
    }
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
        if (ptr->i == ptr->j)
        {
            // Queue becomes empty
            ptr->i = -1;
            ptr->j = -1;
        }
        else
        {
            ptr->i = (ptr->i + 1) % ptr->size;
        }
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
    enqueue(q, 60);
    printf("-----------\n");
    // Test dequeue
    printf("current number dequeue is %d\n", dequeue(q));
    printf("current number dequeue is %d\n", dequeue(q));
    printf("current number dequeue is %d\n", dequeue(q));
    printf("current number dequeue is %d\n", dequeue(q));
    printf("current number dequeue is %d\n", dequeue(q));
    // Free memory
    free(q->arr);
    free(q);
}
