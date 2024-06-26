/* 
theBitRiddler
6/30/2023
11:03 AM
Binary Search
*/
#include <stdio.h>

#define SIZE 15

void printArray( int a[], size_t low, size_t mid, size_t high);
int binarySearch( int a[], int key, size_t low, size_t high );
void header( void );

int main( void ) {
    int array[ SIZE ] = { 0 };
    int searchKey = 0;
    int subscript = 0;

    for ( size_t i = 0; i < SIZE; i++ ) {
        array[ i ] = i * 2;
    } /* end for */

    printf_s( "%s", "Enter a value to be searched: ");
    scanf_s( "%d", &searchKey );

    header();

    subscript = binarySearch( array, searchKey, 0, SIZE - 1 );

    if ( subscript != -1 ) {
        printf_s( "%d value is found in subscript %d\n", searchKey, subscript );
    } /* end if */
    else {
        printf_s( "%d not found.\n", searchKey );
    }

    return 0;
} /* end main */

int binarySearch( int a[], int key, size_t low, size_t high ) {
    int middle = 0;

    middle = ( low + high ) / 2;

    printArray( a, low, middle, high );

    if ( a[ middle ] == key ) {
        return middle;
    } /* end if */
    else if ( !( low <= high ) ) {
        return -1;
    } /* end else if */
    else if ( key < a[ middle ]) {
        binarySearch( a, key, low, middle - 1 );
    } /* end else if */
    else if ( key > a[ middle ]) {
        binarySearch( a, key, middle + 1, high );
    } /* end else if */  

} /* end function binarySearch */

void printArray( int a[], size_t low, size_t mid, size_t high ) {

    for ( size_t i = 0; i < SIZE; i++ ) {

        if ( i < low || i > high ) {
            printf_s( "%s", "    ");
        } /* end if */
        else if ( mid == i ) {
            printf_s( "%3d*", a[ i ]);
        } /* end else if */
        else {
            printf_s("%3d ", a[ i ]);
        } /* end else */
    } /* end for */
    puts("");
} /* end function printArray */

void header( void ) {
    for ( int i = 0; i < SIZE * 4; i++ ) {
        putchar( '-');
    } /* end for */
    puts("");
    for ( int i = 0; i < SIZE; i++ ) {
        printf( "%3d ", i );
    } /* end for */
    puts("");
} /* end function header */