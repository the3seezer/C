/*
theBitRiddler
7/10/2023
9:21 AM

7.1 (a) Address
    (b) NULL, 0 and variable's address
    (c) 0

7.2 (a) False, it leads to syntax error
    (b) True, 

correction
7.2 a) False. A pointer to void cannot be dereferenced, because there’s no way to
know exactly how many bytes of memory to dereference.
 b) False. Pointers of type
void can be assigned pointers of other types, and pointers of type void can be assigned
to pointers of other types.

*/
#include <stdio.h>

#define SIZE 10

int main( void ) {

    /*7.3*/
    /*(a)*/ 
    float numbers[ SIZE ] = { 0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9 };

    /*(b)*/ 
    float * nPtr;

    /*(c)*/
    for ( size_t i = 0; i < SIZE; i++ ) {
        printf_s( "%5.1f", numbers[ i ]);
    }
    puts("");

    /*(d)*/
    nPtr = numbers;
    nPtr = &numbers[ 0 ];

    /*(e)*/
    for ( size_t i = 0; i < SIZE; i++ ) {
        printf_s( "%5.1f", *( nPtr + i ) );
    }
    puts("");

    /*(f)*/
    for ( size_t i = 0; i < SIZE; i++ ) {
        printf_s( "%5.1f", *(numbers + i ) );
    }
    puts("");

    /*(g)*/
    for ( size_t i = 0; i < SIZE; i++ ) {
        printf_s( "%5.1f", nPtr[ i ] );
    }
    puts("");

    /*(h)*/
    printf_s( "%5.1f", numbers[ 3 ]); printf_s( "%5.1f", *( numbers + 3 )); printf_s( "%5.1f", nPtr[ 3 ]);  printf_s( "%5.1f", *( nPtr + 3 ));
    puts("");

    /*(i)*/
    printf_s( "  nPtr = %p, nPtr + 8 = %p with value %5.1f\n", nPtr, nPtr + 8, *(nPtr + 8 ) );
    puts("");

    /*(j)*/
    nPtr = &numbers[ 5 ];
    printf_s( "  %p", nPtr );
    nPtr -= 4;
    printf_s( "  %p", nPtr );
    
}