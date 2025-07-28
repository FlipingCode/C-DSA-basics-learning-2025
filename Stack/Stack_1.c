#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isempty(struct stack *ptr)
{
    if (ptr->top <= -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(struct stack *ptr)
{
    if (ptr->top >= ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int push(struct stack *ptr, int x)
{
    if (isfull(ptr) == 1)
    {
        printf("stack overflow \n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = x;
        return 1;
    }
}
int pop(struct stack *ptr)
{
    if (isempty(ptr) == 1)
    {
        printf("stack underflow \n");
        return -1;
    }
    else
    {

        int x = ptr->arr[ptr->top];
        ptr->top--;
        return x;
    }
}
int peep(struct stack *ptr, int i)
{
    if (i <= 0 || ptr->top - i + 1 < 0)

    {
        printf("stack is empty \n");
        return -1;
    }
    else
    {

        int x = ptr->arr[(ptr->top) - i + 1];

        return x;
    }
}
int xchange(struct stack *ptr, int i, int x)
{
    if (i <= 0 || ptr->top - i + 1 < 0)

    {
        printf("stack is empty \n");
        return -1;
    }
    else
    {

        ptr->arr[(ptr->top) - i + 1] = x;

        return x;
    }
}
int main()
{

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));

    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 1);

    printf("stack element popped is %d\n", pop(s));
    // popped
    push(s, 2);
    push(s, 3);
    push(s, 4);
    printf("stack element 1 is %d\n", peep(s, 1));
    printf("stack element 0 is %d\n", s->arr[0]);
    xchange(s, 1, 11);
    printf("stack element 1 is %d\n", peep(s, 1));
    printf("stack element 0 is %d\n", s->arr[0]);
    free(s->arr);
    free(s);

    return 0;
}