#include "browser.h"

struct command parser(char *request)
{
    struct command result;

    char* opcode = strtok(strdup(request), " ");
    char* value = strtok(0, " ");

    if (!strcmp("forward", opcode)) {
        result.opcode = FORWARD;
        result.value = atoi(value);
    } else if (!strcmp("back", opcode)) {
        result.opcode = BACK;
        result.value = atoi(value);
    } else if (!strcmp("visit", opcode)) {
        result.opcode = VISIT;
        result.site = value;
    }
    return result;
}

void browser(struct Node **pList, char *request)
{
    struct command parsed = parser(request);

    if(parsed.opcode == BACK) {
        int N = parsed.value;
        for(int i = 0; i < N; i++) {
            if ((*pList)->next == NULL)
                break;
            else
                *pList = (*pList)->next;
        }
    }

    if(parsed.opcode == FORWARD) {
        int N = parsed.value;
        for(int i = 0; i < N; i++) {
            if ((*pList)->prev == NULL)
                break;
            else
                (*pList) = (*pList)->prev;
        }
    }

    if(parsed.opcode == VISIT) {
        char *site = parsed.site;

        if((*pList)->prev != NULL){
            struct Node *victimList = (*pList)->prev;
            victimList->next = NULL;

            while (victimList->prev != NULL)
                delete(&victimList);
        }
        insert(pList, site);
    }
}
