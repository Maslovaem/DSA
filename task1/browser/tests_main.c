#include "browser.h"

void resetBrowser(struct Node **list) {
    if (*list != NULL) {
        clear(list);
    }
    *list = createList("homepage");
}

void runCommands(struct Node **list, char *commands[], int count, char *expected[], int expected_count) {
    char *output[100];
    int output_count = 0;

    output[output_count] = (char *)malloc(100 * sizeof(char));
    strcpy(output[output_count], "homepage");
    output_count++;

    for (int i = 0; i < count; i++) {
        printf("%s\n", commands[i]);
        browser(list, commands[i]);

        output[output_count] = (char*)malloc(100 * sizeof(char));
        strcpy(output[output_count], (*list)->page);
        output_count++;
    }

    printf("\nRESULTS:\n");
    for (int i = 0; i < output_count; i++) {
        printf("%s\n", output[i]);
    }

    printf("\nEXPECTING:\n");
    for (int i = 0; i < expected_count; i++) {
        printf("%s\n", expected[i]);
    }

    int passed = 1;
    if (output_count != expected_count) {
        passed = 0;
        printf("FAILED: Количество строк не совпадает: получили %d, ожидали %d\n",
               output_count, expected_count);
    } else {
        for (int i = 0; i < output_count; i++) {
            if (strcmp(output[i], expected[i]) != 0) {
                passed = 0;
                printf("FAILED: Строка %d: получили '%s', ожидали '%s'\n",
                       i+1, output[i], expected[i]);
            }
        }
    }

    if (passed) {
        printf("PASSED\n");
    }
    printf("\n");

    for (int i = 0; i < output_count; i++) {
        free(output[i]);
    }
}

int main() {
    struct Node *list = NULL;

    resetBrowser(&list);
    char *commands1[] = {
        "visit google.com",
        "back 2",
        "back 1",
        "forward 1"
    };
    char *expected1[] = {
        "homepage",
        "google.com",
        "homepage",
        "homepage",
        "google.com"
    };
    printf("TEST 1:\n");
    runCommands(&list, commands1, 4, expected1, 5);

    resetBrowser(&list);
    char *commands2[] = {
        "visit google.com",
        "visit linux.org",
        "visit youtube.com",
        "back 1",
        "visit facebook.com",
        "back 1",
        "forward 1"
    };
    char *expected2[] = {
        "homepage",
        "google.com",
        "linux.org",
        "youtube.com",
        "linux.org",
        "facebook.com",
        "linux.org",
        "facebook.com"
    };
    printf("TEST 2:\n");
    runCommands(&list, commands2, 7, expected2, 8);

    resetBrowser(&list);
    char *commands3[] = {
        "visit google.com",
        "back 5"
    };
    char *expected3[] = {
        "homepage",
        "google.com",
        "homepage"
    };
    printf("TEST 3:\n");
    runCommands(&list, commands3, 2, expected3, 3);

    resetBrowser(&list);
    char *commands4[] = {
        "visit google.com",
        "back 1",
        "forward 5"
    };
    char *expected4[] = {
        "homepage",
        "google.com",
        "homepage",
        "google.com"
    };
    printf("TEST 4:\n");
    runCommands(&list, commands4, 3, expected4, 4);

    resetBrowser(&list);
    char *commands5[] = {
        "visit google.com",
        "visit linux.org",
        "back 1",
        "visit facebook.com",
        "forward 1"
    };
    char *expected5[] = {
        "homepage",
        "google.com",
        "linux.org",
        "google.com",
        "facebook.com",
        "facebook.com"
    };
    printf("TEST 5:\n");
    runCommands(&list, commands5, 5, expected5, 6);

    resetBrowser(&list);
    char *commands6[] = {
        "visit a.com",
        "visit b.com",
        "visit c.com",
        "back 2",
        "forward 1",
        "back 1",
        "forward 2"
    };
    char *expected6[] = {
        "homepage",
        "a.com",
        "b.com",
        "c.com",
        "a.com",
        "b.com",
        "a.com",
        "c.com"
    };
    printf("TEST 6:\n");
    runCommands(&list, commands6, 7, expected6, 8);

    resetBrowser(&list);
    char *commands7[] = {
        "visit x.com",
        "visit y.com",
        "visit z.com",
        "back 3",
        "forward 2"
    };
    char *expected7[] = {
        "homepage",
        "x.com",
        "y.com",
        "z.com",
        "homepage",
        "y.com"
    };
    printf("TEST 7:\n");
    runCommands(&list, commands7, 5, expected7, 6);

    resetBrowser(&list);
    char *commands8[] = {
        "visit one.com",
        "visit two.com",
        "back 2",
        "visit three.com",
        "back 1",
        "forward 1"
    };
    char *expected8[] = {
        "homepage",
        "one.com",
        "two.com",
        "homepage",
        "three.com",
        "homepage",
        "three.com"
    };
    printf("TEST 8:\n");
    runCommands(&list, commands8, 6, expected8, 7);

    if (list != NULL) {
        clear(&list);
    }

    return 0;
}
