/*
    theBitRiddler
    1/21/2024
    10:25 AM
*/
#include <stdio.h>
#include <ctype.h> /* a, */
#include <string.h> /* b, c, d, e */
int main( void ) {
    char s1[50] = "jack";
    char s2[50] = "jill";
    char s3[50] = "";

    /* c */
    printf( "%s\n", strcat( strcat( strcpy( s3, s1 ), " and "), s2 ) );
    /* d */
    printf( "%zu\n", strlen( s1 ) + strlen( s2 ) );
    /* e */
    printf( "%zu\n", strlen( s3 ) );
    
} /* end main */