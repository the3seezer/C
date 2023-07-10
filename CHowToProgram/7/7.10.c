/*
theBitRiddler
7/10/2023
6:17 PM
7.10
*/
#include <stdio.h>
int main( void ) {
    long value1 = 200000;
    long value2 = 0;

    /*(a)*/
    long * lPtr;

    /*(b)*/
    lPtr = &value1;

    /*(c)*/
    printf_s("value of lPtr is %ld\n", * lPtr );

    /*(d)*/
    value2 = * lPtr;

    /*(e)*/
    printf_s("Value of value2 is %ld\n", value2 );

    /*(f)*/
    printf_s( "Address of value1 is %p\n", &value1 );

    /*(g)*/
    printf_s( "Address stored in lPtr is %p\n", lPtr );
    // yes, they are the same.
}