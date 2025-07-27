#include <stdio.h>
#include <string.h>

int top = -1;
char x;
char p[] = "abaaaacaaaaba";
int max = 100;

char s[sizeof(p) - 2];
void push(char x)
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
char pop()
{
    if (top == -1)
    {
        printf("stack overflow\n");
        return 0;
    }
    else
    {
        x = s[top];
        top = top - 1;
        return x;
    }
}
char peep(int i)
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
int isempty()
{
    if (top == -1)
    {
        // printf("empty\n");
        return 1;
    }
    else
    {
        // printf("not empty\n");
        return 0;
    }
}
int main()
{

    printf("l: %c \n", p[strlen(p)]);
    // printf("l: %d \n", strlen(p));
    int i = 0;
    for (i; p[i] != 'c'; i = i + 1)
    {
        push(p[i]);
    }

    i = i + 1;
    // printf("ai: %d \n", i);
    int s = 1;
    // printf("pi: %c \n", p[i]);
    while (!isempty())
    {
        char x = pop();
        // printf("xi: %c \n", x);
        if (x != p[i])
        {
            printf("not a palindrome.\n");
            // printf("bi: %d \n", i);
            return s = 0;
        }
        // printf("wi: %d \n", i);
        i = i + 1;
    }
    // printf("ci: %d \n", i);
    if (s == 1)
    {
        printf("it is a palindrome.\n");
    }
    // printf("top: %d \n", top);
}