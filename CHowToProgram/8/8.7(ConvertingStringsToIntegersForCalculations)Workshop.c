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
    // int a = 0, b = 0, c = 0, d = 0;
    int numbers[NUM] = { 0 };
    // char * numA = "", *numB = "", *numC = "", *numD = "";
    char * numStr[ NUM ] = { "" };
    char * numPtr[ NUM ] = { NULL };

    puts("Enter four strings representing integers" );
    // fgets( numA, SIZE, stdin );
    // fgets( numB, SIZE, stdin );
    // fgets( numC, SIZE, stdin );
    // fgets( numD, SIZE, stdin );
    for ( size_t i = 0; i < NUM; ++i ) {
        printf( "%s", "Enter an integer string: " );
        fgets( numStr[ i ], SIZE, stdin );
    } // end for

    // a = strtol( numA, &aP, 10 );
    // b = strtol( numB, &bP, 10 );
    // c = strtol( numC, &cP, 10 );
    // d = strtol( numD, &dP, 10 );
    for ( size_t i = 0; i < NUM; i++ )
        numbers[ i ] = strtol( numStr[ i ], &numPtr[ i ], 10 );
    
    int total = 0;
    for ( size_t i = 0; i < NUM; i++ )
        total += numbers[i];
    printf( "The sum of the integers is %d\n", total );

    return 0;

} /* end main */
