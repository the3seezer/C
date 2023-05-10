/*
 theBitRiddler
 5/10/2023
 4:24 PM
 What does this do modified the previous for negative b integer
 */
 #include <stdio.h>

int mystery( int, int );

int main( void ) {
    int x = 0;
    int y = 0;

    printf( "%s", "Enter two integers. " );
    scanf_s( "%d%d", &x, &y );

    printf_s( "The results is %d\n", mystery( x, y ) );

    return 0;
} /* end main */

int mystery( int a, int b ) {

    if ( ( b < 0 && a < 0 ) || b < 0 ) {
        a *= -1;
        b *= -1;
    } /* end if */

    if ( b == 1 ) {
        return a;
    } /* end if */
    else {
        return a + mystery( a, b - 1 );
    } /* else if */
} /* end function mystery */