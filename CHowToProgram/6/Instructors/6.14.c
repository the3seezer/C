/* 
 theBitRiddler
 5/17/2023
 11:24 AM 
 Modied Mean, Median and Mode; 
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
} /* end main */

void mean( const int answer[] ) {
    int total = 0;

    for ( size_t i = 0; i < SIZE; i++ ) {
        total += answer[ i ];
    } /* end for */

    printf_s( "The mean is %.4f\n", ( double ) total / SIZE );
} /* end function mean */

void median( int answer[] ) {
    int firstRow = 0;
    /* unsorted array */
    for ( size_t i = 0, firstRow = 1; i < SIZE; i++ ) {
        printf_s( "%3d", answer[ i ] );

        if ( i % 20 == 0 && !firstRow ) {
            printf_s( "%s", "\n" );
        } /* end if */
        firstRow = 0;
    } /* end for */

    puts("");

    /* bubble sort */
    for ( int pass = 1; pass < SIZE; pass++ ) {
        for ( size_t i = 0; i < SIZE - pass; i++ ) {
            if ( answer[ i ] > answer[ i + 1 ] ) {
                int hold = answer[ i ];
                answer[ i ] = answer[ i + 1 ];
                answer[ i + 1 ] = hold;
            } /* end if */
        } /* end for */
    } /* end for */

    /* sorted */
    for ( size_t i = 0, firstRow = 1; i < SIZE; i++ ) {

        if ( i % 20 == 0 && !firstRow ) {
            printf_s( "%s", "\n" );
        } /* end if */

        printf_s( "%3d", answer[ i ] );

        firstRow = 0;
    } /* end for */
    puts("");

    /* odd numbers */
    if ( SIZE % 2 ) {
        printf_s( "The median is %d\n", answer[ ( SIZE + 1 ) / 2 - 1 ]);
    } /* end if */
     /* even numbers */
    else{
        printf_s( "The median is %.2f\n", ( double ) ( answer[ ( SIZE + 1 ) / 2 ]  + answer[ ( SIZE + 1 ) / 2 + 1 ] ) / 2 );
    } /* end else */
} /* end function median */

void mode( const int answer[], int freq[] ) {
    int array[ 10 ] = {0};
    int largest = 0;
    int loop = 0;
    int count = 0;

    for ( size_t rating = 0; rating < 10; rating++ ) 
        freq[ rating ] = 0;

    for ( size_t i = 0; i < SIZE; i++ ) 
        ++freq[ answer[ i ] ];

    for ( size_t rating = 1; rating <= 9; rating++ ) {
        printf_s( "%8d%11d ", rating, freq[ rating ] );

        if ( freq[ rating ] > largest ) {
            largest = freq[ rating ];

            for ( loop = 0; loop < 10; loop++ ) 
                array[ loop ] = 0;

            array[ rating ] = largest;
            ++count;
        } /* end if */
        else if ( freq[ rating ] == largest ) {
            array[ rating ] = largest;
            ++count;
        } /* end else if */

        for ( loop = 0; loop < freq[ rating ]; loop++ )
            printf_s( "%s", "*" );

        puts("");

    } /* end for */

    if ( count > 1 ) {
        printf_s( "%s", "Modes are:      " );
    }
    else {
        printf_s( "%s", "The mode is:    " );
    }

    for ( loop = 1; loop < 10; loop++ ) {
        if ( array[ loop ] ) {
            printf_s( "%d with a frequency of %d\n\t\t", loop, array[ loop ] );
        }
    }
    
}