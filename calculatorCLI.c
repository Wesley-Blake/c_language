#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void update_buffer(char *buffer, const size_t BUFFER_SIZE);
int get_number(char *buffer, const size_t BUFFER_SIZE);

int main(void)
{
    const size_t BUFFER_SIZE = 5;
    char buffer[BUFFER_SIZE];
    int first_int = 0;
    int second_int = 0;
    char operator = '_';

    // get first int
    printf("Please provide your first number!\n");
    update_buffer(buffer, BUFFER_SIZE);
    first_int = buffer[0] - '0';
    printf("Please provide your second number!\n");
    update_buffer(buffer, BUFFER_SIZE);
    second_int = buffer[0] - '0';
    printf("Please choose an operator: +, -, *, /: ");
    update_buffer(buffer, BUFFER_SIZE);
    operator = buffer[0];

    switch (operator)
    {
    case '+':
        printf("%d + %d = %d\n", first_int, second_int, first_int+second_int);
        break;
    case '-':
        printf("%d - %d = %d\n", first_int, second_int, first_int-second_int);
        break;
    case '*':
        printf("%d * %d = %d\n", first_int, second_int, first_int*second_int);
        break;
    case '/':
        printf("%d / %d = %d\n", first_int, second_int, first_int/second_int);
        break;
    default:
        printf("Please check your operator.");
        break;
    }
    return 0;
}

void update_buffer(char *buffer, const size_t BUFFER_SIZE)
{
    if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
    printf("Input Error!\n");
    }
    if (buffer[1] != '\n') while (getchar() != '\n');
}

int get_number(char *buffer, const size_t BUFFER_SIZE)
{
}