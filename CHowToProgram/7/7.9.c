/*
theBitRiddler
7/10/2023
3:08 PM
7.9
*/
#include <stdio.h>

#define SIZE 5

int main( void ) {
    /*(a)*/
    int values[ SIZE ] = { 0 };

    for ( size_t i = 0; i < SIZE; i++ ) {
        values[ i ] = (1 + i) * 2;
    } /* end for */

    /*(b)*/
    int *vPtr;

    /*(c)*/
    for ( size_t i = 0; i < SIZE; i++ ) {
        printf_s( "%5d", values[ i ]);
    } /* end for */
    puts("");

    /*(d)*/
    vPtr = values;
    vPtr = &values[ 0 ];

    /*(e)*/
    for ( size_t i = 0; i < SIZE; i++ ) {
        printf_s( "%5d", *( vPtr + i ));
    }
    puts("");

    /*(f)*/
    for ( size_t i = 0; i < SIZE; i++ ) {
        printf_s( "%5d", *( values + i ) );
    }
    puts("");

    /*(g)*/
    for ( size_t i = 0; i < SIZE; i++ ) {
        printf_s( "%5d", vPtr[ i ]);
    }
    puts("");

    /*(h)*/
    puts("element 4");
    printf_s( "values[ 3 ] == %d, *( values + 3) == %d,"
              "vPtr[ 3 ] == %d, *(vPtr + 3 ) == %d\n", values[ 3 ], *( values + 3 ), vPtr[ 3 ], *(vPtr + 3 ));

    /*(i)*/
    printf_s( "Address of vPtr + 3 == %p\nValue is %d\n", vPtr + 3, *(vPtr + 3 ) );

    /*(j)*/
    vPtr = &values[4];
    vPtr -= 4;
    printf_s( "Addres of vPtr -= 4 == %p\nValue is %d\n", vPtr, * vPtr );
}