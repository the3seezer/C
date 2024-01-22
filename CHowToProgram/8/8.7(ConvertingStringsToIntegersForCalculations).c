/*
 theBitRiddler
 1/22/2024
 5:19 PM
 8.7 (Converting Strings to Integers for Calculations) 
*/
#include <stdio.h>
#include <stdlib.h>
#define NUM 4
#define SIZE 20
int main( void ) {
    int numbers[NUM] = { 0 };
    int total = 0;
    char * numStr[ NUM ] = { "" };
    char * numPtr[ NUM ] = { NULL };

    puts("Enter four strings representing integers" );

    for ( size_t i = 0; i < NUM; ++i ) {
        printf( "%s", "Enter an integer string: " );
        scanf( "%s", &numStr[ i ] );
        puts("");
    } // end for

    for ( size_t i = 0; i < NUM; i++ )
        numbers[ i ] = strtol( numStr[ i ], &numPtr[ i ], 0 );

    for ( size_t i = 0; i < NUM; i++ )
        total += numbers[i];

    printf( "The sum of the integers is %d\n", total );

    return 0;

} /* end main */
