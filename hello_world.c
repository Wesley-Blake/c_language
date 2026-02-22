#include <stdio.h>
#include <stdbool.h>

int main(void) {

    bool x = true;
    int i = 3;
    float j = 3.14;
    char *s = "Hello world!";

    if (x) {
        printf("x: %d is true!\n", x);
    }

    printf("int: %d, float: %f, string: %s\n", i, j, s);

    printf("x: %zu\n", sizeof x);
    printf("i: %zu\n", sizeof i);
    printf("j: %zu\n", sizeof j);
    printf("s: %zu\n", sizeof s);
    printf("Size of int: %zu\n", sizeof(int));
    printf("Size of char: %zu\n", sizeof(char));
    printf("\n");
    return 0;
}