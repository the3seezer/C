#include <stdio.h>

#define SIZE 1000

int main( void ) {
    int array[ SIZE ] = { 0 };
    int count = 0;

    for ( size_t loop = 0; loop < SIZE; loop++ ) {
        array[ loop ] = 1;
    } /* end for */

    for ( size_t loop = 1; loop < SIZE; loop++ ) {

        if ( array[ loop ] == 1 && loop != 1 ) {

            for ( size_t loop2 = loop; loop2 <= SIZE; loop2++ ) {
                
                if ( loop2 % loop == 0 && loop2 != loop ) {
                    array[ loop2 ] = 0;
                } /* end if */
            } /* end for*/
        } /* end if */
    } /* end for */

    for ( size_t loop = 2; loop < SIZE; loop++ ) {
        if ( array[ loop ] == 1) {
            printf_s( "%zu is a prime number\n", loop );
        } /* end if */
    } /* end for */

    return 0;

} /* end main */