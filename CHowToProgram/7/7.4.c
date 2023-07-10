/*
theBitRiddler
7/10/2023
11:08 AM
7.4
*/
#include <stdio.h>
int main( void ) {
    float number1 = 7.3;
    float number2 = 0;

    /*(a)*/
    float *fPtr;

    /*(b)*/
    fPtr = &number1;

    /*(c)*/
    printf_s( "%.1f", *fPtr );
    puts("");

    /*(d)*/
    number2 = *fPtr;

    /*(e)*/
    printf_s( "%.1f", number2 );
    puts("");

    /*(f)*/
    printf_s( "%p", &number1 );
    puts("");

    /*(g)*/
    printf_s( "%p", fPtr );


}
