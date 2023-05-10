/* 
 theBitRiddler
 5/10/2023
 4:14 PM
 What does it do?
*/
#include <stdio.h>

int mystery( int a, int b );

int main( void ) {
    int x = 0;
    int y = 0;

    printf_s( "%s", "Enter two integers. " );
    scanf_s( "%d%d", &x, &y );

    printf_s( "The result of %d and %d is %d\n", x, y, mystery( x, y ) );

    return 0;
} /* end main */

int mystery( int a, int b ) {
    if ( b == 1 ) {
        return a;
    }
    else {
        return a + mystery( a, b - 1 );
    }
}