/* 
theBitRiddler
6/30/2023
10:00 AM
Linear Search
*/
#include <stdio.h>
#define SIZE 100

int linearSearch( const int array[], int key, size_t size );

int main( void ) {
    int a[ SIZE ] = { 0 };

    for ( size_t i = 0; i < SIZE; i++ ) {
        a[ i ] = i * 2;
    } /* end for */

    printf_s( "%s", "Enter integer search key\n");
    int searchKey = 0;
    scanf_s( "%d", &searchKey );

    int subscript = linearSearch( a, searchKey, SIZE - 1 );

    if ( subscript != -1 ) {
        printf_s( "Found value at subsript %d\n", subscript );
    } /* end if */
    else {
        printf_s( "Value not found\n");
    } /* end else */

    return 0;
} /* end main */

int linearSearch(const int array[], int key, size_t size ) {
    
    if ( array[ size ] == key ) {
        return size;
    } /* end if */
    else if ( size < 0 ) {
        return -1;
    } /* end else if */
    linearSearch( array, key, size - 1 );

} /* end linearSearch */
