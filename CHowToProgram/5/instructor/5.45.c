/*
 theBitRiddler
 5/10/2023
 3:27 PM
 Distance between two points
*/
#include <stdio.h>
#include <math.h>

double distance( double, double, double, double );

int main( void ) {
    double x1 = 0;
    double y1 = 0;
    double x2 = 0;
    double y2 = 0;

    printf( "%s", "Enter the first point.");
    scanf_s( "%lf%lf", &x1, &y1 );

    printf( "%s", "Enter the second point. ");
    scanf_s( "%lf%lf", &x2, &y2 );

    printf( "The distance between ( %.2f, %.2f ) and ( %.2f, %.2f ) is %.2f\n", x1, y1, x2, y2, distance( x1, y1, x2, y2 ) );
} /* end main */

double distance( double xOne, double yOne, double xTwo, double yTwo ) {
    return sqrt( pow( xOne - xTwo, 2 ) + pow( yOne - yTwo, 2 ) );
}