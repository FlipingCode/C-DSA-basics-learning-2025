#include <stdio.h>
#include <stdlib.h>

#define max 8
int s[max];
int top = -1;
int x;
void push(int x)
{
    if (top >= max - 1)
    {
        printf("stack overflow\n");
        return;
    }
    else
    {
        top = top + 1;
        s[top] = x;
    }
}
int pop()
{
    if (top == -1)
    {
        printf("stack underflow\n");
        return -1;
    }
    else
    {

        x = s[top];
        top = top - 1;
        return x;
    }
}
int peep(int i)
{
    if (top - i + 1 < 0)
    {
        printf("stack underflow\n");
        return 0;
    }
    else
    {
        return s[top - i + 1];
    }
}
int xchange(int i, int x)
{
    if (top - i + 1 <= 0)
    {
        printf("stack underflow\n");
        return 0;
    }
    else
    {
        s[top - i + 1] = x;
        return s[top - i + 1];
    }
}
int isempty()
{
    if (top == -1)
    {
        printf("empty\n");
        return 1;
    }
    else
    {
        printf("not empty\n");
        return 0;
    }
}
int isfull()
{
    if (top == max - 1)
    {
        printf("full\n");
        return 1;
    }
    else
    {
        printf("not full\n");
        return 0;
    }
}
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);

    printf("********peep \n\n");
    int x = peep(1);
    printf("the current value in the stack is: %d \n", x);

    x = peep(2);
    printf("the current value in the stack is: %d \n\n", x);

    xchange(1, 5);
    printf("********xchange \n\n");
    x = peep(1);
    printf("the current value in the stack is: %d \n\n", x);
    printf("********pop \n\n");
    pop();
    x = peep(1);
    printf("the current value in the stack is: %d \n", x);
    push(4);
    push(5);
    push(6);
    push(7);
    push(8);

    isfull();
    int j = 0;
    while (j < max)
    {
        if (j == 0)
        {
            printf("************\n");
        }

        x = peep(j);

        printf("value: %d \n", x);

        if (j == max - 1)
        {
            printf("************\n");
        }
        j = j + 1;
    }

    return 0;
}