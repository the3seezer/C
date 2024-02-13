/*
    theBitRiddler
    2/6/2024
    11:43 PM
    8.33 (Check Protection) 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main( void ) {
    char check[10] = "";
    char *checkPtr = "";    // check pointer
    double num = 0;         // check in digits
    int posNum = 0;         // check integer
    int hundreds = 0;
    int thousands = 0;
    char astrk[10] = "";    // asteristics
    int zeroNum = 0;         // check decimal
    int i = 0;      // counter
    int a = 9;      // asteristics counter

    // Enter a check string
    printf( "%s", "Write on a check with nine spaces; less than or equil to 99999.99: " );
    fgets( check, 9, stdin );

    // get the number and the integer
    num = strtod( check, &checkPtr );
    posNum = num;

    // get thousands and the hundreds and the decimal places 
    thousands = posNum / 1000;
    hundreds = posNum % 1000;
    zeroNum = (num - posNum) * 100; // filter to two decimal places

    // get the length of posNum / integers
    while( posNum ) {
        posNum /= 10;
        i++;
    } // end while

    // prepare the asteristics to be filled on empty spaces
    if ( i >= 4 ) // if the check is in thousands
        a -= (i + 4 ); // include 4: for a comma and a decimal place
    else 
        a -= (i + 3); // include 3 for a decimal place
    
    // and the asteristic in the astrk array
    for ( size_t j = 0; j < a; j++ ) {
        astrk[j] = '*';
    } // end for

    // Display a check Protected
    if ( thousands )
        printf( "The check is: %s%d%s%d%s%d\n", astrk[0] ? astrk : "",
        thousands, ",", hundreds, ".", zeroNum );
    else 
        printf( "The check is: %s%d%s%d\n", astrk,
        hundreds, ".", zeroNum );

    return 0; // indicate termination successful
} /* end main */