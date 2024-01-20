/*
    theBitRiddler
    1/18/2024
    5:37 PM
    String-Manipulation functions of the string-Handling library
        concatenating strings
        strcat and strncat
*/
#include <stdio.h>
#include <string.h>
int main( void ) {
    char s1[20] = "Happy "; // initialize char array s1
    char s2[] = "New Year "; // initialize char array s2
    char s3[40] = ""; // initialize char array s3 to empty

    printf( "s1 = %s\ns2 = %s\n", s1, s2 );

    // concatenate s2 to s1
    printf( "strcat( s1, s2 ) = %s\n", strcat( s1, s2 ) );

    // concatenate the first 6 character of s1 to s3
    printf( "strncat( s3, s1, 6 ) = %s\n", strncat( s3, s1, 6 ) );

    // concatenate s1 to s3
    printf( "strcat( s3, s1 ) = %s\n", strcat( s3, s1 ) );
} /* end main */