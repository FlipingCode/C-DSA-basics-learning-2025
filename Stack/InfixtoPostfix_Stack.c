#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int size;
    int top;
    char *arr;
} stack;

int isempty(stack *ptr)
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
int isfull(stack *ptr)
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
int push(stack *ptr, char x)
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
int pop(stack *ptr)
{
    if (isempty(ptr) == 1)
    {
        printf("stack underflow \n");
        return '\0';
    }
    else
    {

        char x = ptr->arr[ptr->top];
        ptr->top--;
        return x;
    }
}
int peep(stack *ptr, char i)
{
    if (i <= 0 || ptr->top - i + 1 < 0)

    {

        return '\0';
    }
    else
    {

        char x = ptr->arr[(ptr->top) - i + 1];

        return x;
    }
}
int xchange(stack *ptr, char i, char x)
{
    if (i <= 0 || ptr->top - i + 1 < 0)

    {
        printf("stack is empty \n");
        return '\0';
    }
    else
    {

        ptr->arr[(ptr->top) - i + 1] = x;

        return x;
    }
}
char stacktop(stack *ptr)
{
    if (!isempty(ptr))
        return ptr->arr[ptr->top];
    return '\0';
}
char isanoperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
char precedence(char c)
{
    if (c == '*' || c == '/')
    {
        return 3;
    }
    if (c == '+' || c == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
char *infix_to_postfix(char *infix)
{
    stack *s = (stack *)malloc(sizeof(stack));

    s->size = 10;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0;
    int p = 0;
    while (infix[i] != '\0')
    {
        if (!isanoperator(infix[i]))
        {
            postfix[p++] = infix[i++];
        }
        else
        {
            while (!isempty(s) && precedence(infix[i]) <= precedence(stacktop(s)))
            {
                postfix[p++] = pop(s);
            }
            push(s, infix[i++]);
        }
    }

    while (!isempty(s))
    {
        postfix[p++] = pop(s);
    }

    postfix[p] = '\0';

    free(s->arr);
    free(s);

    return postfix;
}

int main()
{
    char *infix = "a+b-c*d";
    printf("postfix is %s", infix_to_postfix(infix));
    return 0;
}