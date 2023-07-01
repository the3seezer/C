/* 
theBitRiddler
7/1/2023
7:40 AM
Print an Array
*/
#include <stdio.h>

#define SIZE 20

void printArray( int a[], int size );

int main( void ) {
    int array[ SIZE ] = { 0 };

    for ( size_t i = 0; i < SIZE; i++ ) {
        array[ i ] = i + 1;
    } /* end for */
    printf_s( "%s", "Array printed in main\n");
    for ( size_t i = 0; i < SIZE; i++ ) {
        printf_s( "%5d", array[ i ]);
    } /* end for */

    printf_s( "%s", "\nArray printed in printArray\n");
    printArray( array, SIZE - 1);

    return 0;

} /* end main */

void printArray( int a[], int size ) {
    if ( size >= 0 ) {
        printArray(a, size - 1 );
        printf_s( "%5d", a[ size ]);
    }
}
