/*
theBitRiddler
7/2/2023
11:14 AM
Using the & and * pointer operators
*/
#include <stdio.h>
int main( void ) {
    int a = 5;
    int *aPtr = &a;

    printf_s( "Address of a is %p\nValue of aPtr is %p\n\n", &a, aPtr );
    printf_s( "Value of a is %d\nValue of *aPtr is %d\n\n", a, *aPtr );
    printf_s( "%s", "Showing that * and & are complements of each other\n");
    printf_s( "&*aPtr = %p\n*&aPtr = %p\n", &*aPtr, *&aPtr );

}