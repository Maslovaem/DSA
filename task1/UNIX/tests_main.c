#include "parser.h"
#include "stack.h"
#include "tests.h"

int main()
{
    testPath("/", "/");
    testPath("/home/user/docs", "/home/user/docs");
    testPath("/home////user///docs//", "/home/user/docs");
    testPath("/home/./user/././docs", "/home/user/docs");
    testPath("/home/user/docs/../films", "/home/user/films");
    testPath("/home/./user/../docs/./films/..", "/home/docs");
    testPath("/home/.config", "/home/.config");
    testPath("/home/..config/...files", "/home/..config/...files");
    testPath("/home/../.config", "/.config");

    //попытка забраться выше корня
    struct Node *stack = stackCreate();
    parser("/home/../../..", &stack);
    stackClear(&stack);
    printf("\n");
    return 0;
}

