#include "doublyLinkedList.h"

struct Node * createList(char *page)
{
    int pageLen = strlen(page);
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->page = (char *)malloc((pageLen + 1) * sizeof(char));

    for (int i = 0; i <= pageLen; i++)
    {
        p->page[i] = page[i];
    }

    p->next = NULL;
    p->prev = NULL;
    return p;
}

void insert(struct Node **pList, char *page)
{
    struct Node *p = createList(page);
    p->next = *pList;
    (*pList)->prev = p;
    *pList = p;
}

void delete(struct Node **pList)
{
    struct Node *p = *pList;
    *pList = (*pList)->prev;
    if (*pList != NULL) {
        (*pList)->next = NULL;
    }
    free(p->page);
    free(p);
}

void printListForward(struct Node *list)
{
    for (struct Node *p = list; p != NULL; p = p->next)
    {
        printf("%s\n", p->page);
    }
    printf("\n");
}

void printListReverse(struct Node *list)
{
    struct Node *p = list;
    while (p->next != NULL) {
        p = p->next;
    }

    while (p != NULL) {
        printf("%s\n", p->page);
        p = p->prev;
    }
    printf("\n");
}

void clear(struct Node **pList)
{
    struct Node *p = *pList;
    while (p->next != NULL)
    {
        p = p->next;
    }
    while (p != NULL)
    {
        delete(&p);
    }
}
