#ifndef BROWSER_H
#define BROWSER_H

#include "doublyLinkedList.h"
#define MAX_REQUEST 40

enum opcode {
    FORWARD,
    BACK,
    VISIT
};

struct command {
    enum opcode opcode;
    int value;
    char *site;
};

struct command parser(char *request);
void browser(struct Node **list, char *request);

#endif
