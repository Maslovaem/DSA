struct Node {
    char *dir;
    int dirLen;
    struct Node *next;
};

struct Node * stackCreate();

void stackPrint(struct Node *Stack);
int stackEmpty(struct Node *Stack);
int stackSize(struct Node *Stack);
void stackClear(struct Node **pStack);

void stackPush(struct Node **pStack, char *dir, int dirLen);
void stackPop(struct Node **pStack);

