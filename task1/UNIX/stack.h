#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char *dir;
    int dirLen;
    struct Node *next;
};

struct Node * stackCreate();

int stackEmpty(struct Node *Stack);
int stackSize(struct Node *Stack);
void stackClear(struct Node **pStack);

void stackPush(struct Node **pStack, char *dir, int dirLen);
void stackPop(struct Node **pStack);

#endif
