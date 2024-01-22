/*
    theBitRiddler
    1/20/2024
    11:35 AM

*/
#include <ctype.h> /* a, b, c, h, k */
#include <stdio.h> /* d, e, g, i, l, q */
#include <string.h> /* f, j, m, n, o, p, r */

#define SIZE 100
int main( void ) {
    char c = 'a';
    int x = 1, y = 2, z = 3;
    double d = 0.0, e = 0.0, f = 0.0;
    char * ptr = NULL;
    char s1[ SIZE ] = "";
    char s2[ SIZE ] = "";

    /* a*/
    c = toupper( c );
    /* b */
    printf( "%s%s%s\n", "Variable c ", isdigit( c ) ? "is a " : "is not a ", "digit" );
    /* c */
    printf( "%s%s%s\n", "Variable c ", iscntrl( c ) ? "is a " : "is not a ", "control character" );
    /* d */
    fgets( s1, SIZE, stdin );
    /* e */
    puts(s1);
    /* f */
    ptr = strrchr(s1, c );
    /* g */
    putchar( c );
    // puts("");
    /* h */
    printf( "\n%s%s%s\n", "Variable c ", isalpha( c ) ? "is a " : "is not a ", "letter\n" );
    /* i */
    c = getchar();
    /* j */
    scanf( "%99s", s2 ); // NOTE: gets and fgets doesn't work here. why?!
    ptr = strstr( s1, s2 );
    /* k */
    printf( "%c%s%s\n", c, isprint( c ) ? " is a " : " is not a ", "printing character" );
    /* l */
    sscanf( "1.27 10.3 9.432", "%lf%lf%lf", &d, &e, &f ); 
    // sscanf( "1.27 10.3 9.432", "%f%f%f", &d, &e, &f ); This couldn't work here
    /* m */
    strcpy( s1, s2 );
    /* n */
    ptr = strpbrk( s1, s2 );
    /* o */
    printf( "s1 = %s\ns2 = %s\n%s%2d\n",
    s1, s2, 
    "strcmp( s1, s2 ) = ", strcmp( s1, s2 ) );
    /* p */
    ptr = strchr( s1, c );
    /* q */
    sprintf( s1, "%7d%7d%7d\n", x, y, z );
    /* r */
    strncat( s1, s2, 10 );
    /* s */
    printf( "strlen( s1 ) = %d\n", strlen( s1 ) );
    /* t */
    // ptr = strtok( s2, ',' ); the second argument must be a pointer to a char not a char const/ int
    ptr = strtok( s2, "," );

} /* end main */