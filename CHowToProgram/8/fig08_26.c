/*
    theBitRiddler
    1/19/2024
    2:22 PM
    Other functions of the String-Handling Library
        strerror  
                NOTE: Error numbers are defined in errno.h
*/
#include <stdio.h>
#include <string.h>
int main( void ) {

    printf( "%s\n", strerror( 2 ) );

} /* end main */