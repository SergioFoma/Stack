#ifndef H_STACK
#define H_STACK

#include <stdlib.h>
#include <stdbool.h>

typedef int type;

const size_t poison_ = 765911;
const type canary = 179171341; // 0xAADF00D

enum stackErr_t  {
    CORRECT   = 0,
    ERR       = 1
};

struct stack_t{
    type* data;
    size_t size;
    size_t compacity;
    stackErr_t error;
};

bool stackInit( stack_t *stk, size_t startSize);

bool stackPush( stack_t *stk, type value );

type stackPop( stack_t *stk );

bool stackPrint( stack_t *stk );

void stackDestroy( stack_t *size );

void calculateTest( stack_t *size );

#endif