#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
int traversal(node *p)
{
    while (p != NULL)
    {
        printf("data:%d\n", p->data);
        p = p->next;
    }
}
node *insert_before_first(node **head, int data)
{
    if (head == NULL)
        return NULL;
    node *p = (node *)malloc(sizeof(node));
    p->next = *head;
    p->data = data;
    *head = p;
    return *head;
}
node *insert_before_index(node **head, int data, int index)
{
    // empty
    if (*head == NULL)
    {
        return 0;
    }
    if (index == 0)
    {
        node *ptr = (node *)malloc(sizeof(node));
        ptr->data = data;
        ptr->next = *head;
        *head = ptr;
        return *head;
    }
    // between
    for (int i = 0; i == index; i++)
    {
        /* code */
    }
}
node *insert_after_node(node *p, node *pn, int data)
{

    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = pn->next;
    pn->next = ptr;
    return p;
}
node *insert_at_end(node *p, int data)
{
    while (p->next != NULL)
    {

        p = p->next;
    }
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;
    return p;
}
node *delete_first(node **head)
{

    node *temp = *head;
    *head = (*head)->next;
    free(temp);
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

    /*
    insert_before_first(&head, 11);//address
    traversal(head);

    printf("-------\n");
    insert_at_end(head, 33);
    traversal(head);
    printf("-------\n");
    insert_after_node(head, third, 44);
    traversal(head);
    printf("-------\n");
    */
    traversal(head);
    printf("-------\n");
    delete_first(&head); //
    traversal(head);
    printf("-------\n");

    insert_before_index(head, 1, 0); //
    traversal(head);
}