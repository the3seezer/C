/*
    theBitRiddler
    1/18/2024
    5:37 PM
    String-Manipulation functions of the string-Handling library
        comparison functions of the string-Handling library
        strcmp and strncmp
*/
#include <stdio.h>
#include <string.h>
int main( void ) {
    char s1[] = "Happy New Year";
    char s2[] = "Happy New Year";
    char s3[] = "Happy Holiday";

    printf( "s1 = %s\ns2 = %s\ns3 = %s\n%s%2d\n%s%2d\n%s%2d\n\n",
    s1, s2, s3,
    "strcmp( s1, s2 ) = ", strcmp( s1, s2 ),
    "strcmp( s1, s3 ) = ", strcmp( s1, s3 ),
    "strcmp( s3, s1 ) = ", strcmp( s3, s1 ) );

    printf( "%s%2d\n%s%2d\n%s%2d",
    "strncmp( s1, s3, 6 ) = ", strncmp( s1, s3, 6 ),
    "strncmp( s1, s3, 7 ) = ", strncmp( s1, s3, 7 ),
    "strncmp( s3, s1, 7 ) = ", strncmp( s3, s1, 7 ) );

} /* end main */