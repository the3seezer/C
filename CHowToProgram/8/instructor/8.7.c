#include <stdio.h>
#include <stdlib.h>
int main( void ) {
    char stringValue[6] = ""; // integer string input by user
    int sum = 0;             // result of the four integers
    int i = 0;               // loop counter

    // loop four times
    for ( i = 0; i < 4; i++ ) {
        printf( "%s", "Enter an integer string: " );
        scanf( "%s", stringValue );

        sum += atoi( stringValue );
    } // end for

    printf( "\n\nThe total of the values is %d\n", sum );
}