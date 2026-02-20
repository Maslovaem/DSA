#include <stdio.h>
#include <cstdlib>

#include "stack.h"

void stackPrint(struct Node *Stack)
{
    for (struct Node *p = Stack; p != NULL; p = p->next)
        for (int i = 0; i < p->dirLen; i++)
            printf("%c", *(p->dir + i));
    printf("\n");
}

void stackPush(struct Node **pStack, char *dir, int dirLen)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->dir = (char *)malloc(dirLen);
    p->dirLen = dirLen;
    p->next = *pStack;
    *pStack = p;
}

int stackEmpty(struct Node *Stack)
{
    return (Stack == NULL);
}

void stackPop(struct Node **pStack)
{
    struct Node *p = *pStack;
    *pStack = p->next;
    free(p->dir);
    free(p);
}

struct Node * stackCreate()
{
    struct Node *Stack = NULL;
    return Stack;
}

int stackSize(struct Node *Stack)
{
    int size = 0;
    for (struct Node *p = Stack; p != NULL; p = p->next) size++;
    return size;
}

void stackClear(struct Node **pStack)
{
    for ( ; *pStack != NULL; ) stackPop(pStack);
}


