#include "tests.h"

void testPath(char *testPath, char *expPath)
{
    struct Node *stack = stackCreate();

    printf("testPath: %s\n", testPath);

    parser(testPath, &stack);
    char *result = formDir(stack);

    printf("currentPath: %s\n", result);
    printf("expPath: %s\n", expPath);
    printf("testResult = %s\n\n", (strcmp(result, expPath) == 0) ? "OK" : "FAILED");

    free(result);
    stackClear(&stack);
}
