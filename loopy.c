#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int i = 0;

    while (i++ < 10) {
        printf("Yes, you can do this!\n");
    }
    printf("\n");

    for (int j; j < 10; j++) printf("This is also a loop!\n");
    printf("\n");

    int r;
    srand(time(NULL));
    do {
        r = rand() % 100;
        printf("%d\n", r);
    } while (r != 10);
    printf("\n");

    int goat_example = 2;

    printf("Your goat count: %d\n", goat_example);
    switch (goat_example) {
        case 0:
            printf("No goats.\n");
            break;
        case 1:
            printf("1 goat!\n");
            break;
        case 2:
            printf("Weird to have more than 1 goat...\n");
            __attribute__((fallthrough)); // Apparenlty this only works on gcc and clang. Comments are recomended.
        default:
            printf("That is a lot of goats dude.");
            break;
    }
    printf("\n");

    printf("\n");
    return 0;
}