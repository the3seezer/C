#include <stdio.h>

#define SIZE 15

int binarySearch( int a[], int key, size_t low, size_t high );
void printArray( int a[], size_t low, size_t mid, size_t high );
void header();

int main( void ) {
    int array[ SIZE ] = { 0 };
    int searchKey = 0;

    for ( size_t i = 0; i < SIZE; i++ ) {
        array[ i ] = i * 2;
    } /* end for */

    printf_s( "%s", "Enter a value \n");
    scanf_s( "%d", &searchKey );

    header();

    int element = binarySearch( array, searchKey, 0, SIZE - 1 );

    if ( element != -1 ) {
        printf_s( "\n%d found at index %d\n",searchKey, element);
    } /* end if */
    else {
        printf_s("\nElement not in the list.\n" );
    } /* end else */

    return 0;
} /* end main */

int binarySearch( int a[], int key, size_t low, size_t high ) {
    int middle = 0;

    while ( low <= high) {

        middle = (low + high ) / 2;

        printArray( a, low, middle, high);

        if ( a[ middle] == key ) {
            return middle;
        } /* end if */
        else if ( key < a[ middle ]) {
            high = middle - 1;
        } /* end else if */
        else if ( key > a[ middle ]) {
            low = middle + 1;
        } /* end else if */

    } /* end while */

    return -1;
} /* end function binarySearch */

void printArray( int a[], size_t low, size_t mid, size_t high ) {

    for ( size_t i = 0; i < SIZE; i++ ) {

        if ( i < low || i > high ) {
            printf_s( "%s", "    ");
        } /* end if */
        else if ( i == mid ) {
            printf_s( "%3d*", a[ i ]);
        } /* end else if */
        else {
            printf_s( "%3d ", a[ i ]);
        } /* end else */
    } /* end for */

    puts("");

} /* end function printArray */

void header() {
    for ( int i = 0; i < SIZE * 4; i++ ) {
        putchar('-');
    } /* end for */
    puts("");
    for ( int i = 0; i < SIZE; i++ ) {
        printf_s( "%3d ", i );
    } /* end for */
    puts("");
} /* end header */