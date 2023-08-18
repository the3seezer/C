#include <stdio.h>
int main( void ) {
    int royal = 0;
    int copyFace[ 5 ] = { 0, 9, 10, 11, 12 };

    // for ( size_t i = 1; i < 5; i++ ) {
    //         if( copyFace[ i ] == (copyFace[ i + 1 ] - 1) && copyFace[ 0 ] == 0 && copyFace[ 1 ] == 9 ) { 
    //             ;
    //         } /* end if */
    //         else 
    //             noRoyal = 1;
    //     } /* end for */

    if ( copyFace[ 0 ] == 0 && copyFace[ 1 ] == 9 && copyFace[ 2 ] == 10 && copyFace[ 3 ] == 11 && copyFace[ 4 ] == 12 )
        royal = 1;
        
    if ( royal )
        printf_s( "%s", "Royal ");
}