#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Trying out functions.
int process_buffer(char *buffer, size_t size);
// I just wanted to make another function :D.
void process_input(char input);
// Clear screen and detects operating system.
void clear_screen(void);

int main(void) {
    // 10 because I ready it is convention, but 2 should do.
    char buffer[10];
    // I don't want this value default value to be valid.
    char input = 'y';

    // The game!
    while (true) {
        printf("q: quit, s: scissors, r: rock, p: paper\n");
        process_buffer(buffer, sizeof(buffer) / sizeof(buffer[0]));
        input = buffer[0];
        if (input == 'q') {
            printf("Thanks for playing!\n");
            break;
        }
        clear_screen();
        process_input(input);
    }
    return 0;
}

int process_buffer(char *buffer, size_t size) {
    // Safe input collection.
    if (fgets(buffer, size, stdin) == NULL){
        printf("Input error, sorry.\n");
    } 
    // Skips all the nonsense till I see a new line.
    if (buffer[1] != '\n') while (getchar() != '\n');
    return 0;
}

void process_input(char input) {
    int cpu = rand() % 3;
    switch (input) {
        case 's':
            // logic
            if (cpu == 0) printf("cpu: s tie!");
            if (cpu == 1) printf("cpu: r You lost!");
            if (cpu == 2) printf("cpu: p You win!");
            break;
        case 'r':
            // logic
            if (cpu == 0) printf("cpu: s You win!");
            if (cpu == 1) printf("cpu: r tie!");
            if (cpu == 2) printf("cpu: p You lost!");
            break;
        case 'p':
            // logic
            if (cpu == 0) printf("cpu: s You lost!");
            if (cpu == 1) printf("cpu: r You win!");
            if (cpu == 2) printf("cpu: p tie!");
            break;
        default:
            printf("This seems to be invalide input!");
            break;
    }
    printf("\n\n");
}

void clear_screen(void) {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}