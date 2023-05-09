/* 
 theBitRiddler
 5/9/2023
 2:34 PM
 The Greastest Common Divisor's Recursive Function
*/
#include <stdio.h>

unsigned gcd( unsigned, unsigned );

int main( void ) {
    unsigned x = 0;
    unsigned y = 0;

    printf( "%s", "Enter two integers: ");
    scanf( "%u%u", &x, &y );

    printf( "The greatest common divisor of %u and %u is %u", x, y, gcd( x, y ) );
} /* end main */

unsigned gcd ( unsigned xNum, unsigned yNum ) {

    if ( yNum == 0 ) {
        return xNum;
    }
    else {
        return gcd( yNum, xNum % yNum );
    }
}