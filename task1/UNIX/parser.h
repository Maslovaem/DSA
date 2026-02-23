#ifndef PARSER_H
#define PARSER_H

#include "stack.h"

#define MAX_DIR_LEN 255

void parser (char *str, struct Node **pStack);
char * formDir(struct Node *stack);

#endif
