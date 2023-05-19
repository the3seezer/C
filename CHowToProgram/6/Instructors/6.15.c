/*
 theBitRiddler
 5/17/2023
 6:12 PM
 Nonduplicate values
*/
#include <stdio.h>

#define MAX 20

int main( void ) {
    int a[ MAX ] = {0};
    int duplicate = 0;
    int value = 0;
    size_t k = 0;


    printf_s( "%s", "Enter 20 integers between 10 and 100:\n" );
    
    for (size_t i = 0; i <= MAX - 1; i++ ) {
        duplicate = 0;
        scanf_s( "%d", &value );

        /* check whether it's a duplicate */
        for ( size_t j = 0; j < k; j++ )
            if ( value == a[ j ] ) {
                duplicate = 1;
            }

        if ( !duplicate )
            a[ k++ ] = value;

    } /* end for */

    printf_s( "%s", "\nThe Nonduplicate values are: \n" );

    for ( size_t i = 0; i < k; i++ )
        printf_s( "%3d", a[ i ] );

    return 0;
}