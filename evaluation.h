#ifndef evaluation_h
#define evaluation_h

#include "mpc.h"

typedef struct lval
{
    int type;
    long num;
    char* err;
    char* sym;
    int count;
    struct lval** cell;
} lval;

// lval eval_op(lval x, char* op, lval y);
// lval eval(mpc_ast_t* t);
// lval lval_num(long x);
// lval lval_err(int x);
// void lval_print(lval v);

lval* lval_num(long x);
lval* lval_err(char* message);
lval* lval_sym(char* symbol);
lval* lval_sexpr(void);
lval* lval_read_num(mpc_ast_t* t);
lval* lval_read(mpc_ast_t* t);
lval* lval_add(lval* v, lval* x);
void lval_expr_print(lval* v, char open, char close);
void lval_print(lval* v);
void lval_println(lval* v);


enum {LVAL_NUM, LVAL_ERR, LVAL_SYM, LVAL_SEXPR};


#endif
