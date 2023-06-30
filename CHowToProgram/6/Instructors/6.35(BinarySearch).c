/* 
theBitRiddler
6/30/2023
8:00 PM
Binary Search 
*/
#include <stdio.h>

#define SIZE 15

int binarySearch( int a[], int key, size_t low, size_t high );
void printRow( int a[], size_t low, size_t mid, size_t high );
void header( void );

int main( void ) {
    int array[ SIZE ] = { 0 };
    int searchKey = 0;
    int subscript = 0;

    for ( size_t i = 0; i < SIZE; i++ ) {
        array[ i ] = i * 2;
    } /* end for */

    printf_s( "%s", "Enter a value to be searched:  ");
    scanf_s( "%d", &searchKey );

    header();

    subscript = binarySearch( array, searchKey, 0, SIZE - 1 );

    if ( subscript != -1 ) {
        printf_s( "\n%d is found at index %d\n", searchKey, subscript);
    } /* end if */
    else {
        printf_s( "\nValue not found in the list.\n" );
    } //end of outer IF statement

    return 0;

} /* end main */

int binarySearch( int a[], int key, size_t low, size_t high ) {
    int middle = 0;

    if ( low <= high ) {
        middle = (low + high) / 2;

        printRow( a, low, middle, high );

        if ( a[ middle ] == key ) {
            return middle;
        } /* end if */
        else if ( key < a[ middle ]) {
            return binarySearch( a, key, low, middle - 1 );
        } /* end if */
        else {
            return binarySearch( a, key, middle + 1, high );
        } /* end else */
    } /* end if */

    return -1;

} /* end function binarySearch */

void printRow( int a[], size_t low, size_t mid, size_t high ) {

    for ( size_t i = 0; i < SIZE; i++ ) {
        if ( i < low || i > high ) {
            printf_s("    ");
        } /* end if */
        else if ( i == mid ) {
            printf_s( "%3d*", a[ i ]);
        } /* end else if */
        else {
            printf_s("%3d ",a[ i ]);
        } /* end else */
    } /* end for */
    puts("");
} /* end function printRow */

void header( void ) {
    for ( int i = 0; i < SIZE * 4; i++ ) {
        printf_s( "%s", "*");
    } /* end for */
    puts("\n");

    for ( int i = 0; i < SIZE; i++ ) {
        printf_s( "%3d ", i );
    } /* end for */
    putchar('\n');
} /* end function header */