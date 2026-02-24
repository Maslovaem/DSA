#include "browser.h"

void browser(struct Node **pList, char *request)
{
    struct command parsed;

    char *strCpy = strdup(request);
    char *opcode = strtok(strCpy, " ");
    char *value = strtok(0, " ");

    if (!strcmp("forward", opcode)) {
        parsed.opcode = FORWARD;
        parsed.value = atoi(value);
    } else if (!strcmp("back", opcode)) {
        parsed.opcode = BACK;
        parsed.value = atoi(value);
    } else if (!strcmp("visit", opcode)) {
        parsed.opcode = VISIT;
        parsed.site = value;
    }

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
        char site[MAX_REQUEST];
	strcpy(site, parsed.site);

        if((*pList)->prev != NULL){
            struct Node *victimList = (*pList)->prev;
            victimList->next = NULL;

            while (victimList != NULL)
                delete(&victimList);
        }
        insert(pList, site);
    }
    free(strCpy);
}
