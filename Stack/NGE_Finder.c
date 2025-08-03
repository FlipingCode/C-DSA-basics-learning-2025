#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size;
    int top;
    int *arr;
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
int push(stack *ptr, int x)
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
        return -1;
    }
    else
    {

        int x = ptr->arr[ptr->top];
        ptr->top--;
        return x;
    }
}
int peep(stack *ptr, int i)
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
int xchange(stack *ptr, int i, int x)
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

int *nextGreaterElement(int *nums1, int nums1size, int *nums2, int nums2size, int *returnsize)
{
    for (int i = 0; i <= nums1size; i++)
    {
        int p = -1;
        for (int j = 0; i <= nums2size; j++)
        {
        }
        {
        }
    }
}
int main()
{

    int nums1[] = {4, 1, 2};
    int nums2[] = {1, 3, 4, 2};
    int returnSize;

    int *result = nextGreaterElement(nums1, 3, nums2, 4, &returnSize);

    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }
    free(result);

    return 0;
}