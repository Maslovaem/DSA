#include "parser.h"
#include "stack.h"

#define MAX_PATH 4096

int main()
{
    char input[MAX_PATH] = {0};
    struct Node *stack = stackCreate();

    fgets(input, MAX_PATH, stdin);

    int len = strlen(input);
    if (len > 0 && input[len-1] == '\n')
    {
        input[len-1] = '\0';
    }

    parser(input, &stack);

    char *result = formDir(stack);
    printf("%s\n", result);

    free(result);
    stackClear(&stack);
    return 0;
}
