#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool check_argc(int argc);
bool check_argv(char* arg_string);

int main(int argc, char *argv[])
{
    if (!check_argc(argc)) return -1;
    if (!check_argv(argv[1])) return -1;
    if (!check_argv(argv[3])) return -1;
    int a = atoi(argv[1]);
    int b = atoi(argv[3]);
    char op = argv[2][0];

    switch (op)
    {
    case '+':
        printf("%d + %d = %d", a, b, a+b);
        break;
    case '-':
        printf("%d - %d = %d", a, b, a-b);
        break;
    case 'x':
        printf("%d * %d = %d", a, b, a*b);
        break;
    case '/':
        printf("%d / %d = %d", a, b, a/b);
        break;
    case '%':
        printf("%d %% %d = %d", a, b, a%b);
        break;
    default:
        printf("Usage: %%d [+,-,/,x,%%] %%d\n");
        break;
    }
    printf("\n");
    return 0;
}

bool check_argc(int argc)
{
    if (argc == 4)
    {
        return true;
    }
    else 
    {
        if (argc < 4)
        {
            printf("Too few arguments!\n");
        }
        else
        {
            printf("Too many arguments!\n");
        }
        printf("Usage: %%d [+,-,/,x,%%] %%d\n");
        return false;
    }
}

bool check_argv(char* arg_string)
{
    size_t length = strlen(arg_string);
    for (size_t i = 0; i<length; i++)
    {
        if (!isdigit(arg_string[i])) return false;
    }
    return true;
}