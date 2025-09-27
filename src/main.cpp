#include <TXLib.h>
#include <stdio.h>

#include "stack.h"
#include "checkError.h"
#include "paint.h"

int main(){
    size_t startSize = 8;
    size_t getSymbol = '0';
    int getNumber = -1;
    stack_t stk = {};

    stackInit( &stk, startSize );

    colorPrintf(NOMODE, YELLOW, "Enter the elements of stack: ");
    while( scanf("%d", &getNumber ) == 1  ){
        stackPush( &stk,getNumber );
        if( ( getSymbol = getchar() ) == '\n' ){
            break;
        }
    }

    colorPrintf(NOMODE, BLUE, "Enter the number of items you want to delete: ");
    scanf("%d", &getNumber );
    for( int count = 0; count < getNumber; count++ ){
        colorPrintf(NOMODE, BLUE, "delete stack[%zu] = %d\n", stk.size - 1, stackPop( &stk ) );
    }

    stackPrint( &stk );
    
    stackDestroy( &stk );
    

    return 0;
}