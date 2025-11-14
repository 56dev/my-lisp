#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mpc.h"
#include "evaluation.h"

int number_of_nodes(mpc_ast_t* t);

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
    

    mpc_parser_t* Number = mpc_new("number");
    mpc_parser_t* Symbol = mpc_new("symbol");
    mpc_parser_t* Sexpr = mpc_new("sexpr");
    mpc_parser_t* Expr = mpc_new("expr");
    mpc_parser_t* Lispy = mpc_new("lispy");

    mpca_lang(MPCA_LANG_DEFAULT, 
    "\
    number         : /-?[0-9]+/;                                          \
    symbol       : '+' | '-' | '*' | '/';                                 \
    sexpr          : '(' <expr>* ')' ;                                    \
    expr           : <number> | '(' <operator> <expr>+ ')' ;              \
    lispy          : /^/ <operator> <expr>+ /$/ ;", 
    Number, Symbol, Sexpr, Expr, Lispy);
    //              how sexy

    puts("Mylisp Version 0.0.0.0.1");
    puts("Press Ctrl+C to Exit\n");

    while(1)
    {
        
        char* input = readline("lispy>");
        mpc_result_t r;
        if(!mpc_parse("<stdin>", input, Lispy, &r))
        {
            mpc_err_print(r.error);
            mpc_err_delete(r.error);
            free(input);
            continue;
        }
        
        lval* x = lval_read(r.output);
        lval_println(x);
        lval_del(x);
        
        free(input);
    }

    mpc_cleanup(4, Number, Symbol, Sexpr, Expr, Lispy);
    return 0;


}

int number_of_nodes(mpc_ast_t* t)
{
    
    if(t->children_num == 0) { return 1; }
    if(t->children_num >= 1)
    {
        int total = 1;
        
        for(int i = 0; i < t->children_num; i++)
        {
            total = total + number_of_nodes(t->children[i]);
        }
        return total;
    }
    return 0; 
}
    

