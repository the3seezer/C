/*
theBitRiddler
6/29/2023
11:25 AM
BucketSort
*/

#include <stdio.h>

#define SIZE 12

void bucketSort(int a[]);
void distributeElements(int a[], int bucket[][ SIZE ], int digit );
void collectElements(int a[], int bucket[][ SIZE ]);
int numberOfDigits(int a[]);
void zeroBucket(int bucket[][ SIZE ]);

int main( void ) {
    int array[ SIZE ] = { 19, 13, 5, 27, 1, 26, 31, 16, 2, 9, 11, 21 };

    printf_s( "%s", "Array elements in original order\n");

    for ( size_t i = 0; i < SIZE; i++ ) {
        printf_s("%3d", array[ i ]);
    } /* end for */

    printf_s( "%s","\n");

    bucketSort( array );

    printf_s("%s", "Array elements in sorted order\n");
    for ( size_t i = 0; i < SIZE; i++ ) {
        printf_s("%3d", array[ i ]);
    } /* end for */
    printf_s("%s", "\n");
    return 0;
    
} /* end main */

void bucketSort( int a[]) {
    int digits = 0;
    int buckets[ 10 ][ SIZE ] = { 0 };

    digits = numberOfDigits( a );

    for ( int i = 1; i <= digits; i++ ) {
        distributeElements(a, buckets, i );
        collectElements(a, buckets);

        if ( i != digits ) {
            zeroBucket( buckets );
        } /* end if */
    } /* end for */
} /* end function bucketSort */

void distributeElements( int a[], int bucket[][ SIZE ], int digit) {
    size_t bucketNumber = 0;
    size_t elementNumber = 0;
    int divisor = 10;

    for ( int i = 1; i < digit; i++ ) {
        divisor *= 10;
    } /* end for */

    for ( size_t i = 0; i < SIZE; i++ ) {
        bucketNumber = ( a[ i ] % divisor - a[ i ] % ( divisor / 10 ) ) / ( divisor / 10 );

        elementNumber = ++bucket[ bucketNumber ][ 0 ];
        bucket[ bucketNumber ][ elementNumber ] = a[ i ];
    } /* end for */
} /* end function distributeElements */

void  collectElements(int a[], int bucket[][ SIZE ]) {
    size_t subscript = 0;

    for ( size_t i = 0; i < SIZE; i++ ) {
        for ( size_t j = 1; j <= bucket[ i ][ 0 ]; j++ ) {
            a[ subscript++ ] = bucket[ i ][ j ];
        } /* end for */
    } /* end for */
} /* end function collectElements */

int numberOfDigits( int a[]) {
    int largest = a[ 0 ];
    int totalDigits = 0;

    for (size_t i = 1; i < SIZE; i++ ) {
        if ( a[ i ] > largest ) {
            largest = a[ i ];
        } /* end if */
    } /* end for */

    while ( largest != 0 ) {
        ++totalDigits;
        largest /= 10;
    } /* end while */

    return totalDigits;
}/* end function numberOfDigits */

void zeroBucket( int bucket[][ SIZE]) {
    for ( size_t i = 0; i < 10; i++ ) {
        for (size_t j = 0; j < SIZE; j++ ) {
            bucket[ i ][ j ] = 0;
        } /* end for */
    } /* end for */
} /* end function zeroBuckets */
