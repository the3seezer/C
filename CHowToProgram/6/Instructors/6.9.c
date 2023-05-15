/*
 theBitRiddler
 5/14/2023
 12:48 PM
 6.9
*/
#include <stdio.h>
int main( void ) {
    int t[ 2 ][ 5 ] = {0};
    /* (a) definition for t int t[ 2 ][ 5 ]; 
       (b), (c) and (d) t has 2 rows, 5 column and 10 elements
       (e) names of all elements in the second row: t[ 1 ][ 0 ], t[ 1 ][ 1 ], t[ 1 ][ 2 ], t[ 1 ][ 3 ] and t[ 1 ][ 4 ].
       (f) all elements in the third column: t[ 0 ][ 2 ] and t[ 1 ][ 2 ].
       (g) t[ 0 ][ 1 ] = 0;
       (h) t[ 0 ][ 0 ] = 0;
           t[ 0 ][ 1 ] = 0;
           t[ 0 ][ 2 ] = 0;
           t[ 0 ][ 3 ] = 0;
           t[ 0 ][ 4 ] = 0;
           t[ 1 ][ 0 ] = 0;
           t[ 1 ][ 1 ] = 0;
           t[ 1 ][ 2 ] = 0;
           t[ 1 ][ 3 ] = 0;
           t[ 1 ][ 4 ] = 0;
    */
    /* i */
    for ( size_t i = 0; i < 2; i++ )
        for ( size_t j = 0; j < 5; j++ )
            t[ i ][ j ] = 0;

    /* j */
    for ( size_t i = 0; i < 2; i++ )
        for (size_t j = 0; j < 5; j++ ) {
            printf_s( "%s", "Enter an integer: ");
            scanf_s( "%d", &t[ i ][ j ] );
        }

    /* k */
    int smallest = t[ 0 ][ 0 ];
    for ( size_t i = 0; i < 2; i++ )
        for ( size_t j = 0; j < 5; j++ )
            if ( t[ i ][ j ] < smallest )
                smallest = t[ i ][ j ];

    printf_s( "The smallest value is %d\n\nElements of the first row: ", smallest);

    /* (l): A statement that displays the elements of the first row of t */
    for ( size_t i = 0; i < 5; i++ )
        printf_s( "%3d", t[ 0 ][ i ] );
    puts( "" );
    
    /* (m) total the third column of t*/
    int total = 0;
    for ( size_t i = 0; i < 2; i++ )
        total += t[ i ][ 2 ];

    /* (n): write a series of statements that prints array elements in a tabular format */
    printf_s( "%s", "   0\t1\t2\t3\t4\n" );
    for ( size_t i = 0; i < 2; i++ ) {
        printf_s( "%d  ", i );

        for ( size_t j = 0; j < 5; j++ )
            printf_s( "%d\t", t[ i ][ j ] );
        
        puts("");
    }

}