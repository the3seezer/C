/* 
theBitRiddler
6/18/2023
11:09 PM
 (Duplicate Elimination)
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

int main( void ) {
    int randomNumber = 0;
    int duplicate = 0;
    size_t subscript = 0;
    int array[ SIZE ] = { 0 };

    srand( time( NULL ) );

    for ( int loop = 0; loop <= SIZE - 1; loop++ ) {
        duplicate = 0;
        randomNumber = 1 + rand() % 20;

        for ( size_t loop2 = 0; loop2 <= subscript; loop2++ ) {

            if ( randomNumber == array[ loop2 ] ) {
                duplicate = 1;
                break;
            } /* end if */
        } /* end for */

        if ( !duplicate ) {
            array[ subscript++ ] = randomNumber;
        } /* end if */

    } /* end for */

    printf_s( "%s", "Non-repetitive array values are:\n");

    for ( size_t loop = 0; array[ loop ] != 0; loop++ ) {
        printf_s( "\t\t\t array[ %zu ] == %d \n", loop, array[ loop ] );
    } /* end for */

    return 0;
} /* end main */