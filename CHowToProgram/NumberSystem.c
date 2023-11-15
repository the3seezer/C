#include <stdio.h>

int main( void ) {
    // number = A; you can't initialize with an hexadecimal value
    int number = 0;
    printf_s( "%s", "Enter A:an hexadecimal number ");
    scanf( "%x", &number );
    if ( number == 10 ) 
        printf_s( " 10 equals %x\n", number );

    // printf_s( "%s", "Enter 10: a decimal number ");
    // scanf( "%d", &number );
    // if ( number == A ) // You can't use hexadecimal values in comparison since it will be recognised as an undeclared variable
    //     printf_s( " %d equals to A ", &number );

} /* end main */