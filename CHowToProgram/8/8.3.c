/*
    theBitRiddler
    1/21/2024
    10:25 AM
*/
#include <stdio.h>
#include <ctype.h> /* a, */
#include <string.h> /* b, */
int main( void ) {
    char s1[50] = "jack";
    char s2[50] = "jill";
    char s3[50] = "";

    /* a */
    printf("%c%s\n", toupper(s1[0]), &s1[1] );
    /* b */
    printf("%s\n", strcpy( s3, s2 ) );
    
}