#include <stdio.h>
#include <stdlib.h>

#define max 5
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
int cpeep(int i)
{
    if (i < 0)
    {
        return 0;
    }
    else
    {
        return s[i];
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
int display(int t)
{
    int j = max - 1;
    printf("stack stage %d\n", t);

    while (j > -1)
    {

        if (j == max - 1)
        {
            printf("************\n");
        }

        x = cpeep(j);
        printf("value: %d \n", x);

        if (j == 0)
        {
            printf("************\n");
        }

        j = j - 1;
    }

    return 0;
}
int main()
{

    //  int a[12];
    push(10);
    display(1);
    push(15);
    display(2);
    push(13);
    display(3);
    push(6);
    display(4);
    push(7);
    display(5);
    pop();
    display(6);
    pop();
    display(7);
    pop();
    display(8);
    push(8);
    display(9);
    push(21);
    display(10);
    push(22);
    display(11);
    push(40);
    display(12);
    return 0;
}