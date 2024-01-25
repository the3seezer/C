#include <stdio.h>
#include <stdlib.h>
int main( void ) {
    char stringValue[ 6 ] = "";
    double sum = 0;
    int i = 0;

    for ( i = 0; i < 4; i++ ) {
        printf( "%s", "Enter a doubleing point string: " );
        scanf( "%s", stringValue );

        sum += atof( stringValue );
    } // end for 
    printf( "\n\nThe total value is %f\n", sum );

    return 0; // indicate termination successful
} /* end main */