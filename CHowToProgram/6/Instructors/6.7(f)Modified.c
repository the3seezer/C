/* 
 theBitRiddler
 5/13/2023
 10:38 PM
 Mean, Median and Mode
 1, 2, 5, 6, 7, 7, 7
*/
#include <stdio.h>

#define SIZE 7

void mean( const int a[] );
void mode( const int a[], int Hz[] );
void median( int a[] );
void printArray( const int a[] );
void bubbleSort( int a[] );

int main( void ) {
    int array[ SIZE ] = { 1, 2, 5, 6, 7, 7, 7 };
    int freq[ 8 ] = {0};

    mean( array );
    median( array );
    mode( array, freq );
} /* end main */

void mean( const int a[] ) {

    printf_s( "%s", "-----------Mean----------\n" );
    int total = 0;

    for ( size_t i = 0; i < SIZE; i++ ) {
        total += a[ i ];
    } /* end for */
    printf_s( "The mean is %d\n", total / SIZE );
} /* end mean */

void median( int a[] ) {
    printf_s( "%s", "Array before sorting\n" );
    printArray( a );
    bubbleSort( a );
    printf_s( "%s", "Array after sorting\n" );
    printArray( a );

    printf( "The median is %d\n",  SIZE % 2 ? a[ SIZE / 2 ] : a[ SIZE / 2 - 1 ] );

}

void mode( const int a[], int Hz[] ) {

    printf_s( "%s", "----------Mode----------\n" );
    for ( size_t rating = 0; rating < 8; rating++ ) {
        Hz[ rating ] = 0;
    } /* end for */

    for ( size_t i = 0; i < SIZE; i++ ) {
        ++Hz[ a[ i ] ];
    } /* end for */

    int largest = 0;
    int modeValue = 0;
    for ( size_t rating = 1; rating <= 7; rating++ ) {
        if ( Hz[ rating ] ) {
            printf_s( "%8zu%11d", rating, Hz[ rating ]);

            if ( Hz[ rating ] > largest ) {
                largest = Hz[ rating ];
                modeValue = rating;
            }

            for ( int j = 1; j <= Hz[ rating ]; j++ ) {
                printf_s( "%s", "*" );
            }
        }
        else {
            continue;
        }

        puts("");
    }

    printf_s( "The mode is %d with value %d\n", modeValue, largest );

}

void bubbleSort( int a[] ) {
    for ( int i = 1; i < SIZE; i++ ) {
        for ( size_t j = 0; j < SIZE - 1; j++ ) {
            if ( a[ i ] > a[ i + 1 ] ) {
                int hold = a[ i ];
                a[ i ] = a[ i + 1 ];
                a[ i + 1 ] = hold;
            }
        }
    }
}

void printArray( const int a[] ) {
    for ( size_t i = 0; i < SIZE; i++ ) {
        printf_s( "%3d", a[ i ] );
    } /* end for */
    puts( "" );
}