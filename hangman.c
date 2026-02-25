#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void) {
    // All variables I should need.
    int chances = 4;
    const char *secret = "The Mountains";
    const size_t length = strlen(secret);
    char printed_secret[length + 1];
    for (size_t i = 0; i < length; i++) {
        printed_secret[i] = '_';
    }
    printed_secret[length] = '\0';
    size_t correct_guesses = 0;
    const size_t BUFFER_SIZE = 10;
    char buffer[BUFFER_SIZE];
    char guess = '0';

    while (true) {
        // Check condition.
        if (chances <= 0) {
            printf("You didn't make it!\n");
            printf("The secret was \"%s\n\"", secret);
            return 0;
        }
        // Printing.
        printf("Current chances left: %d !\n", chances);
        printf("The secret word!\n");
        printf("%s\n", printed_secret);
        // Collecting input.
        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
            printf("Input Error!\n");
        }
        if (buffer[1] != '\n') while (getchar() != '\n');
        guess = buffer[0];
        // check if guess in secret word.
        //printf("Your guess: %c\n", guess);
        for (size_t i = 0; i < length; i++) {
            if (guess == secret[i]) {
                printed_secret[i] = secret[i];
                correct_guesses++;
                if (correct_guesses == length) {
                    printf("You win!\n");
                    return 0;
                }
            }
        }
    }
    return 0;
}