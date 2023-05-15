/*
 theBitRiddler
 5/15/2023
 10:59 AM
 Modified Bubble sort
*/
#include <stdio.h>

#define MAX 10

int main( void ) {
    int array[ MAX ] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int swap = 0; /* the swap flag */
    int hold = 0; /* template */

    printf_s( "%s", "Data item in the original order.\n" );
    for ( size_t i = 0; i < MAX; i++ ) 
        printf_s( "%d ", array[ i ] );
    

    for ( int pass = 1; pass < MAX; pass++ ) {
        swap = 0; /* not nessesary. but showing a point */

        for ( size_t i = 0; i < MAX - pass; i++ ) 
            if ( array[ i ] > array[ i + 1 ] ) {
                swap = 1;
                hold = array[ i ];
                array[ i ] = array[ i + 1 ];
                array[ i + 1 ] = hold;
            } /* end if and for */

        /* Display the array after every swap */
        printf_s( "\nAfter pass %d: ", pass );

        for ( size_t i = 0; i <= MAX - pass; i++ )
            printf_s( "%d ", array[ i ] );


        if ( !swap ) 
            break;
        
        
    } /* end for */

    printf_s( "%s", "\nData in ascending order.\n" );
    for ( size_t i = 0; i < MAX; i++ )
        printf_s( "%d ", array[ i ] );
}