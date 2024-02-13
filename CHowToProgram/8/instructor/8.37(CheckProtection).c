#include <stdio.h>
int main( void ) {
    double base = 100000.0;
    double amount = 0;
    int i = 0;      // count

    printf( "%s", "Enter your check: ");
    scanf( "%lf", &amount );

    printf( "%s", "Protected amount is $" );

    // loop until amount is greater than base
    for ( i = 0; amount < base; i++ )
        base /= 10;
    
    // printf leading asterists
    for ( size_t j = 1; j <= i; j++ ) {
        printf( "%s", "*" );
    } // end for

    // print check
    printf( "%*.2f", 9 - i, amount );

    return 0; // indicate termination successful
} /* end main */