#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
void traversal(node *i)
{

    while (i != NULL)
    {
        printf("%d\n", i->data);
        i = i->next;
    }
}
node *insertatbeginning(node *head, int data)
{
    node *p = (node *)malloc(sizeof(node));
    p->next = head;
    p->data = data;
    return p;
}
node *insertatmiddle(node *n, int data, int i)
{
    node *p = (node *)malloc(sizeof(node));
    p->next = n;
    p->data = data;
    return p;
}
int main()
{
    node *head = (node *)malloc(sizeof(node));
    node *second = (node *)malloc(sizeof(node));
    node *third = (node *)malloc(sizeof(node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;
    // head = insertatbeginning(head, 11);
    printf("-------\n");
    traversal(head);

    insertatmiddle(second, 22, 2);
    printf("-------\n");
    traversal(head);

    return 0;
}