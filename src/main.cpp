#include <TXLib.h>
#include <stdio.h>

#include "stack.h"
#include "checkError.h"
#include "paint.h"

int main(){
    size_t startSize = 8;
    stack_t stk = {};
    int getNumber = -1;
    size_t getSymbol = '0';

    if( !stackInit( &stk, startSize ) ){
        return 0;
    }

    colorPrintf(NOMODE, YELLOW, "Enter the elements of stack: ");
    while( scanf("%d", &getNumber ) == 1  ){
        if( !stackPush( &stk,getNumber ) ){
            return 0;
        }
        if( ( getSymbol = getchar() ) == '\n' ){
            break;
        }
    }

    colorPrintf(NOMODE, BLUE, "Enter the number of items you want to delete: ");
    scanf("%d", &getNumber );
    for( int count = 0; count < getNumber; count++ ){
        colorPrintf(NOMODE, BLUE, "delete stack[%zu] = %d\n", stk.size, stackPop( &stk ) );
    }

    if ( !stackPrint( &stk ) ){
        return 0;
    }
    
    stackDestroy( &stk );

    return 0;
}