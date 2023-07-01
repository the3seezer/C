/* 
theBitRiddler
7/1/2023
9:19 AM
Print a string backward
*/

#include <stdio.h>

#define SIZE 30

void stringReverse( char string[]);

int main( void ) {
    char c[ SIZE ] = "Print this string backwards.";

    for ( size_t i = 0; i < SIZE; i++ ) {
        printf_s( "%c", c[ i ]);
    } /* end for */

    puts("\n\n");
    stringReverse( c );

    return 0;

} /* end main */

void stringReverse( char string[]) {
    
    if ( string[ 0 ] == '\0' ) {
        return;
    } /* end if */
    
        stringReverse( &string[ 1 ] );
        printf_s( "%c", string[ 0 ]);
   
} /* end function stringReverse */