#include "parser.h"

void parser (char *str, struct Node **pStack)
{
    int i = 0;
    int dirLen = 0;
    char dir[MAX_DIR_LEN] = {0};
    int strLen = strlen(str);

    while (i < strLen)
    {
        dirLen = 0;
        while (i < strLen && str[i] != '/')
        {
            dir[dirLen] = str[i];
            dirLen++;
            i++;
        }

        if (dirLen == 1 && dir[0] == '.')
        {
            ;
        }
        else if (dirLen == 2 && dir[0] == '.' && dir[1] == '.')
        {
            if (stackEmpty(*pStack))
            {
                printf("Going upper than the root directory is not possible.\n");
            }
            else
            {
                stackPop(pStack);
            }
        }
        else if (dirLen > 0)
        {
            stackPush(pStack, dir, dirLen);
        }
        else if (dirLen == 0)
        {
            i++;
        }
    }
}

char * formDir(struct Node *stack)
{
    char *result = (char *)malloc(MAX_DIR_LEN * sizeof(char));

    result[0] = '\0';

    int stackDepth = stackSize(stack);

    struct Node **nodes = (struct Node**)malloc(stackDepth * sizeof(struct Node*));

    int i = 0;
    for (struct Node *p = stack; p != NULL; p = p->next) {
        nodes[i] = p;
        i++;
    }

    if (stackDepth == 0)
    {
        strcat(result, "/");
    }
    else
    {
        for (i = stackDepth - 1; i >= 0; i--)
        {
            strcat(result, "/");
            strncat(result, nodes[i]->dir, nodes[i]->dirLen);
        }
    }

    free(nodes);
    return result;
}

