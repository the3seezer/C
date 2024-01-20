/*
    theBitRiddler
    1/18/2024
    11/19 AM
    Standard input / output library functions
        sscanf
*/
#include <stdio.h>
int main( void ) {
    char s[] = "318278  85.93";
    int x = 0;
    double y = 0;

    sscanf( s, "%d%lf", &x, &y );
    puts( "The values stored in character array s are: ");
    printf( "integer:%7d\ndouble:%8.3f\n", x, y );

} /* end main */