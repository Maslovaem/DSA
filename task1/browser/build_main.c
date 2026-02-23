#include "browser.h"

int main()
{
    struct Node *list = createList("homepage");
    printf("%s\n", list->page);
    char input[MAX_REQUEST] = {0};
    while(1)
    {
        fgets(input, MAX_REQUEST, stdin);

        int len = strlen(input);
        if (len > 0 && input[len-1] == '\n')
        {
            input[len-1] = '\0';
        }

        if(!strcmp("q", input))
            break;

        browser(&list, input);
        printf("%s\n", list->page);
    }

    return 0;
}


