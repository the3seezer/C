/* 
 theBitRiddler
 5/17/2023
 4:44 PM
 workshop
*/
#include <stdio.h>

#define SIZE 100

void mean( const int answer[] );
void median( int answer[] );
void mode( const int answer[], int freq[] );

int main( void ) {
    int frequency[ 10 ] = {0};
    int response[ SIZE ] = {
         6, 7, 8, 9, 8, 7, 8, 9, 8, 9,
         7, 8, 9, 5, 9, 8, 7, 8, 7, 1,
         6, 7, 8, 9, 3, 9, 8, 7, 1, 7,
         7, 8, 9, 8, 9, 8, 9, 7, 1, 9,
         6, 7, 8, 7, 8, 7, 9, 8, 9, 2,
         7, 8, 9, 8, 9, 8, 9, 7, 5, 3,
         5, 6, 7, 2, 5, 3, 9, 4, 6, 4,
         7, 8, 9, 6, 8, 7, 8, 9, 7, 1,
         7, 4, 4, 2, 5, 3, 8, 7, 5, 6,
         4, 5, 6, 1, 6, 5, 7, 8, 7, 9
    };

    mean( response );
    median( response );
    mode( response, frequency );

    return 0;
}

void mean( const int answer[] ) {
    int total = 0;
    for ( size_t i = 0; i < SIZE; i++ )
        total += answer[ i ];

    printf_s( "The mean is %.4f\n", (double) total / SIZE );
}

void median( int answer[] ) {
    int first = 0;
    for ( size_t i = 0, first = 1; i < SIZE; i++ ) {
        if ( i % 20 == 0 && !first ) {
            printf_s( "%s", "\n" );
        }

        printf_s( "%3d", answer[ i ] );
        first = 0;
    }
    puts("\n\n\n");

    for ( int pass = 1; pass < SIZE; pass++ ) {
        for ( size_t i = 0; i < SIZE - pass; i++ ) 
            if ( answer[ i ] > answer[ i + 1 ] ) {
                int hold = answer[ i ];
                answer[ i ] = answer[ i + 1 ];
                answer[ i + 1 ] = hold;
            } /* end if and for loop */

    } /* end for */

    for ( size_t i = 0, first = 1; i < SIZE; i++ ) {
        if ( i % 20 == 0 && !first ) {
            printf_s( "%s", "\n" );
        }

        printf_s( "%3d", answer[ i ] );
        first = 0;
    }

    if ( SIZE % 2 ) {
        printf_s( "\nThe median is %d\n", answer[ ( SIZE + 1 ) / 2 - 1 ] );
    }
    else {
        printf_s( "\nThe median is %.2f\n", (double) ( answer[ ( SIZE + 1 ) / 2 ] + answer[ ( SIZE + 1 ) / 2 + 1 ] ) );
    }

}

void mode( const int answer[], int freq[] ) {
    int largest = 0;
    int count = 0;
    int array[ 10 ] = {0};

    for ( size_t rating = 0; rating < SIZE; rating++ ) 
        freq[ rating ] = 0;

    for ( size_t i = 0; i < SIZE; i++ )
        ++freq[ answer[ i ] ];

    for ( size_t rating = 1; rating <= 9; rating++ ) {
        printf_s( "%8d%11d ", rating, freq[ rating ] );

        if ( freq[ rating ] > largest ) {
            largest = freq[ rating ];

            for ( size_t i = 0; i < 10; i++ )
                array[ i ] = 0;

            array[ rating ] = largest;
            ++count;
        }
        else if ( freq[ rating ] == largest ) {
            array[ rating ] = largest;
            ++count;
        }

        for ( size_t i = 1; i <= freq[ rating ]; i++ )
            printf_s( "%s", "*" );

        puts("");

    } /* end for */

    if ( count ) {
        printf_s( "%s", "The modes are   " );
    }
    else {
        printf_s( "%s", "The mode is    " );
    }

    for ( size_t loop = 1; loop <= 9; loop++ )
        if ( array[ loop ] )
            printf_s( "%d with frequency of %d\n\t\t", loop, array[ loop ] );
}
