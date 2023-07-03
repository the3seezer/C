/*
theBitRiddler
7/3/2023
5:32 PM
Using operator sizeof to determine standard type sizes. 
*/
#include <stdio.h>
int main( void ) {
    char c = ' ';
    short s = 0;
    int i = 0;
    long l = 0;
    long long ll = 0;
    float f = 0.0F;
    double d = 0.0;
    long double ld = 0.0;
    int array[ 20 ] = { 0 };
    int * ptr = array;
    
    printf_s( "sizeof c = %2zu\t\tsizeof( char ) = %2zu\n", sizeof c , sizeof( char ) );
    printf_s( "sizeof s = %2zu\t\tsizeof( short ) = %2zu\n", sizeof s, sizeof( short ) );
    printf_s( "sizeof i = %2zu\t\tsizeof( int ) = %2zu\n", sizeof i, sizeof( int ) );
    printf_s( "sizeof l = %2zu\t\tsizeof( long ) = %2zu\n", sizeof l, sizeof( long ) );
    printf_s( "sizeof ll = %2zu\t\tsizeof( long long ) = %2zu\n", sizeof ll, sizeof( long long ) );
    printf_s( "sizeof f = %2zu\t\tsizeof( float ) = %2zu\n", sizeof f, sizeof( float ) );
    printf_s( "sizeof d = %zu\t\tsizeof( double ) = %2zu\n", sizeof d, sizeof( double ) );
    printf_s( "sizeof ld = %2zu\t\tsizeof( long double ) = %2zu\n", sizeof ld, sizeof( long double ) );
    printf_s( "sizeof array = %2zu\t\tsizeof ptr = %2zu\n", sizeof array, sizeof( ptr ) );

    return 0;
} /* end main */
