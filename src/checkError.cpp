#include <stdio.h>
#include "stack.h"

const int poison = 765911;

bool stackDump( const char* file, const char* func, int line, stack_t *stk ){

    FILE* fileForDump = fopen("StackStatus.txt", "a");

    if( file == NULL ){
        fprintf( fileForDump, "\nName of file %s - NULL PTR in function %s, in line %d\n", file, func, line);
        fclose( fileForDump );
        return false;
    }
    if( func == NULL ){
        fprintf( fileForDump, "\nName of function %s - NULL PTR in file %s, in line %d\n",
                  func, file, line );
        fclose( fileForDump );
        return false;
    }
    if ( line < 0 ){
        fprintf( fileForDump, "\nThe line %d is less than zero in file %s, in function %s\n",
                 line, file, func);
        fclose( fileForDump );
        return false;
    }
    if ( stk->data == NULL ){
        fprintf( fileForDump, "\nThe pointer to the zero date in file %s, in function %s, in line %d\n",
                file, func, line);
        stk->error = ERR;
        fclose( fileForDump );
        return false;
    }
    if ( stk->compacity < 0 ){
        fprintf(fileForDump, "\nSize of data %zu is less than zero in file %s, in function %s, in line %d\n",
                stk->compacity, file, func, line);
        stk->error = ERR;
        fclose( fileForDump );
        return false;
    }
    if ( stk->size < 0 ){
        fprintf( fileForDump, "\nNo elements in stack: %zu in file %s, in function %s, in line %d\n",
                 stk->size, file, func, line );
        stk->error = ERR;
        fclose( fileForDump );
        return false;
    }
    if ( stk->error == ERR ){
        fprintf( fileForDump, "\nCode of error - 1 in file %s, in function %s, in line %d\n", file, func, line);
        fclose( fileForDump );
        return false;
    }
    fprintf( fileForDump, "\nstackDump called from file %s, in function %s, in line %d\n", file, func, line);
    fprintf( fileForDump, "stack[%p]\nSize = %zu\nCompacity = %zu\n.data[%p]\nCode of error = %d\n", 
            stk, stk->size, stk->compacity, stk->data, stk->error );
    for( size_t index = 0; index < ( stk->compacity ); index++ ){
        if( index < (stk->size) || index == stk->compacity - 1 ){
            fprintf( fileForDump, "*[%zu] = %d\n", index, (stk->data)[index] );
        }
        else{
            fprintf( fileForDump, " [%zu] = %d( POISON )\n", index, poison);
        }
    }
    fclose( fileForDump );

    return true;
}