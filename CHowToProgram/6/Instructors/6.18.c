/* 
 theBitRiddler
 5/18/2023
 5:22 PM
 what does it do? 
*/
#include <stdio.h>

#define SIZE 10
void printArray( const int a[], size_t startIndex, size_t size );

int main( void ) {

    int array[ SIZE ] = {  8, 3, 1, 2, 6, 0, 9, 7, 4, 5 };
    printArray( array, 0, SIZE );

    return 0;
} /* end main */

void printArray( const int a[], size_t startIndex, size_t size ) {
    if ( startIndex < size ) {
        printArray( a, startIndex + 1, size );
        printf_s( "%3d", a[ startIndex ] );
    }
}