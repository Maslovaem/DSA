#ifndef DLL_H
#define DLL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node {
    char * page;
    struct Node* next;
    struct Node* prev;
};

struct Node * createList(char *page);
void insert(struct Node **pList, char *page);
void delete(struct Node **pList);
void printListForward(struct Node *list);
void printListReverse(struct Node *list);
void clear(struct Node **pList);

#endif
