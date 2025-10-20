#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char buffer[2048];

char* readline(char* prompt)
{
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char* cpy = malloc(strlen(buffer) + 1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy) - 1] = '\0';
    return cpy;
}

int main(int argc, char *argv[])
{
    /*puts appends a newline automatically.*/
    puts("Mylisp Version 0.0.0.0.1");
    puts("Press Ctrl+C to Exit\n");

    while(1)
    {

        char* input = readline("lispy>");

        /*printf allows you to format strings.*/
        printf("ECHO: %s\n", input);
        free(input);
    }

    return 0;


}

    

