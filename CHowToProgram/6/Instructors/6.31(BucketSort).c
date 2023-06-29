#include <stdio.h>

#define SIZE 12

void bucketSort(int a[]);
void distributeElements( int a[], int bucket[][ SIZE ], int digit);
void collectElements( int a[], int bucket[][SIZE]);
int numberOfDigits( int a[], int arraySize);
void zeroBucket( int bucket[][ SIZE ]);

int main( void ) {
int array[ SIZE ] = { 19, 13, 5, 27, 1, 26, 31, 16, 2, 9, 11, 21 };

    printf_s( "%s", "array elements in original order\n");
    
    for ( size_t i = 0; i < SIZE; i++ ) {
        printf_s( "%4d", array[ i ]);
    } /* end for */
    printf_s( "%s", "\n");

    bucketSort( array );

    printf_s( "%s", "array Elements in sorted order\n");
    for (size_t i = 0; i < SIZE; i++ ) {
        printf_s( "%4d", array[ i ]);
    } /* end for*/
    printf_s( "%s", "\n");

    return 0;
} /* end main */

void bucketSort( int a[] ) {
    int digits = 0;
    int bucket[ 10 ][ SIZE ] = { 0 };

    digits = numberOfDigits( a, SIZE);

    for ( int i = 1;i <= digits; i++ ) {
        distributeElements( a, bucket, i );
        collectElements( a, bucket);

        if ( i != digits) {
            zeroBucket( bucket );
        } /* end if */

    } /* end for */
} /* end function bucketSort */

int numberOfDigits( int a[], int arraySize) {
    int largest = a[ 0 ];;
    int digits = 0;

    for ( size_t i = 1; i < arraySize; i++ ) {
        if ( a[ i ] > largest) {
            largest = a[ i ];
        } /* end if */
    } /* end for */
    
    while( largest != 0) {
        ++digits;
        largest /= 10;
    } /* end while */

    return digits;
} /* end function numberOfDigits */

void distributeElements( int a[], int bucket[][ SIZE ], int digit ) {
    size_t bucketNumber = 0;
    size_t elementNumber = 0;
    int divisor = 10;

    for  ( int i = 1; i < digit; i++) {
        divisor *= 10;
    } /* end for */

    for ( int i = 0; i < SIZE; i++ ) {
        bucketNumber = ( a[ i ] % divisor - a[ i ] % (divisor / 10) ) / ( divisor / 10 );

        elementNumber = ++bucket[ bucketNumber ][ 0 ];
        bucket[ bucketNumber ][elementNumber] = a[ i ];
    } /* end for */

} /* end function distributeElement*/

void collectElements( int a[], int bucket[][ SIZE ]) {
    size_t subscript = 0;

    for ( size_t i = 0; i < 10; i++ ) {
        for ( size_t j = 1; j <= bucket[ i ][ 0 ]; j++ ) {
            a[ subscript++ ] = bucket[ i ][ j ];
        } /* end for */
    } /* end for */

} /* end function collectElement */

void zeroBucket( int bucket[][ SIZE]) {
    for ( size_t i = 0; i < 10; i++ ) {
        for ( size_t j = 0; j < 10; j++ ) {
            bucket[i][j] = 0;
        } /* end for */
    } /* end for */
} /* end function zeroBucket */
