/* 
 theBitRiddler
 5/18/2023
 5:47 PM
 Dice rolling 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 13

int main( void ) {
    int x = 0;
    int y = 0;

    int sum[ SIZE ] = {0};

    /* array expected contains counts for the expected
     number of times each sum occurs in 36 rolls of the dice */
    int expected[ 13 ] = {  0, 0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1 };

    for ( size_t i = 0; i < 36000; i++ ) {
        x = 1 + rand() % 6;
        y = 1 + rand() % 6;
        ++sum[ x + y ];
    }

    printf_s( "%10s%10s%10s%10s\n", "Sum", "Total", "Expected", "Actual" );

    for ( size_t j = 2; j <= 12; j++ )
        printf_s( "%10zu%10d%9.3f%9.3f\n", j, sum[ j ],
        100.0 * expected[ j ] / 36, 100.0 * sum[ j ] / 36000 );

    return 0;
}