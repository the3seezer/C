/*
    theBitRiddler
    1/18/2024
    5:37 PM
    String-Manipulation functions of the string-Handling library
        copying strings  
        strcpy and strncpy
*/
#include <stdio.h>
#include <string.h>
#define SIZE1 25
#define SIZE2 15
int main( void ) {
    char x[] = "Happy Birthday to You"; // initialize char array x
    char y[SIZE1] = ""; // create char array y
    char z[SIZE2] = ""; // Create char array z

    printf( "%s%s\n%s%s\n",
    "The string in array x is ", x, 
    "The string in array y is ", strcpy( y, x ) );

    strncpy( z, y, SIZE2 - 1 ); // Copy the first 14 characters in array y to z
    z[ SIZE2 - 1 ] = '\0'; // Terminate the string, because '\0' was not copied

    printf( "The string in array z is %s\n", z );
} /* end main */
