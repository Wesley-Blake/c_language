#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int processBuffer(char *buffer, size_t size);

int main(void) {
    bool loop = true;
    char buffer[10]; // 10 because I ready it is convention, but 2 should do.
    char input = 'y'; // Shouldn't be an option.
    int cpu = 0; // I don't care if this is an option.

    while (loop) {
        printf("q: quit, s: scissors, r: rock, p: paper\n");
        processBuffer(buffer, sizeof(buffer) / sizeof(buffer[0]));
        
        input = buffer[0];
        cpu = rand() % 3;

        switch (input) {
            case 'q':
                printf("Thanks for playing!");
                loop = false;
                break;
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

    return 0;
}

int processBuffer(char *buffer, size_t size) {
    // Safe input collection.
    if (fgets(buffer, size, stdin) == NULL){
        printf("Input error, sorry.\n");
    } 
    // Skips all the nonsense till I see a new line.
    if (buffer[1] != '\n') while (getchar() != '\n');
    return 0;
}