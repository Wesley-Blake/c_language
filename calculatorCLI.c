#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

void update_buffer(char *buffer, const size_t BUFFER_SIZE);
int get_number(char *buffer, const size_t BUFFER_SIZE);
void clear_screen(void);

int main(void)
{
    const size_t BUFFER_SIZE = 5;
    char buffer[BUFFER_SIZE];
    int first_int = 0;
    int second_int = 0;
    char operator = '_';

    printf("Please provide your first number [0-9]: ");
    first_int = get_number(buffer, BUFFER_SIZE);
    printf("Please provide your second number [0-9]: ");
    second_int = get_number(buffer, BUFFER_SIZE);
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
        if ((second_int) == 0)
        {
            printf("You cannot divide by zero, but it can be the numerator!\n");
            return -1;
        }
        printf("%d / %d = %d\n", first_int, second_int, first_int/second_int);
        break;
    default:
        printf("Please check your operator.\n");
        return -1;
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
    int temp = 0;
    update_buffer(buffer, BUFFER_SIZE);
    if (isdigit(buffer[0]))
    {
        return buffer[0] - '0';
    } else {
        clear_screen();
        printf("That wasn't an int: ");
        temp = get_number(buffer, BUFFER_SIZE);
        return temp;
    }
}

void clear_screen(void)
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}