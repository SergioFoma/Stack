#include <assert.h>
#include <stdio.h>

#include "stack.h"
#include "checkError.h"
#include "paint.h"

bool stackInit( stack_t *stk, size_t startSize ){
    (stk->data) = (type*)calloc( startSize, sizeof( type ) );
    stk->size = 0;
    stk->compacity = startSize;
    stk->error = CORRECT;

    return true;
}

bool stackPush( stack_t *stk, type value ){
    STACK_OK( stk );

    if( stk->size == stk->compacity ){
        (stk->compacity) *= 2;
        stk->data = (type*)realloc( stk->data, (stk->compacity) * sizeof( type ) );
    }
    (stk->data)[stk->size++] = value;
    
    return true;
}

type stackPop( stack_t *stk ){
    STACK_OK( stk );

    if( stk->size == 0 || stk->compacity == 0){
        return poison_;
    }
    return (stk->data)[--(stk->size)];
}

bool stackPrint( stack_t *stk ){
    STACK_OK( stk );

    colorPrintf(NOMODE, GREEN, "\nstack: \n");
    for( size_t index = 0; index < (stk->size); index++ ){
        colorPrintf(NOMODE, GREEN, "[%zu] = %d ", index, (stk->data)[index] );
    }
    printf("\n");

    return true;
}

void stackDestroy( stack_t *stk ){
    free( stk->data );
    stk->data = NULL;
    stk->compacity = -1;
    stk->size = -1;
    stk->error = CORRECT;

    return ;
}
