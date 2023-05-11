/* 
 theBitRiddler
 5/10/2023
 4:41 PM
 Test Math library Functions
*/
#include <stdio.h>
#include <math.h>

int main( void ) {
    int loop = 0;
    double loop2 = 0;
    
    for ( int count = 1; count <= 14; count++ ) {

        switch ( count ) {
            case 1:
                printf( "%s     ", "funct" );
                for ( loop = 1; loop < 6; loop++ ) {
                    printf( "%10d", loop );
                }; 
                break;

            case 2:
                printf( "\n\n\n%-10s", "sqrt()" );
                for ( loop = 1; loop < 6; loop++ ) {
                    printf( "%10.2f", sqrt( loop ) );
                }
                break;

            case 3:
                printf( "\n\n%-10s", "exp()" );
                for ( loop = 1; loop < 6; loop++ ) {
                    printf( "%10.2f", exp( loop ) );
                }
                break;

            case 4:
                printf( "\n\n%-10s", "log()");
                for ( loop = 1; loop < 6; loop++ ) {
                    printf( "%10.2f", log( loop ) );
                }
                break;

            case 5:
                printf( "\n\n%-10s", "log10()" );
                for ( loop = 1; loop < 6; loop++ ) {
                    printf( "%10.2f", log10( loop ) );
                }
                break;

            case 6:
                printf( "\n\n%10s", "pow( 2, x )" );
                for ( loop = 1; loop < 6; loop++ ) {
                    printf( "%10.2f", pow( 2, loop ) );
                }
                break;

            case 7:
                printf( "\n\n\n%s", "funct     " );
                for ( loop2 = -1.5; loop2 < 3.0; loop2 += 1.1 ) {
                    printf( "%10.2f", loop2 );
                }
                break;

            case 8:
                printf( "\n\n%-10s", "fabs()" );
                for ( loop2 = -1.5; loop2 < 3.0; loop2 += 1.1 ) {
                    printf( "%10.2f", fabs( loop2 ) );
                }
                break;

            case 9:
                printf( "\n\n%-10s", "ceil()" );
                for ( loop2 = -1.5; loop2 < 3.0; loop2 += 1.1 ) {
                    printf( "%10.2f", ceil( loop2 ) );
                }
                break;

            case 10:
                printf( "\n\n%-10s", "floor()" );
                for ( loop2 = -1.5; loop2 < 3.0; loop2 += 1.1 ) {
                    printf( "%10.2f", floor( loop2 ) );
                }
                break;

            case 11: 
                printf( "\n\n%-10s", "sin()" );
                for ( loop2 = -1.5; loop2 < 3.0; loop2 += 1.1 ) {
                    printf( "%10.2f", sin( loop2 ) );
                }
                break;

            case 12: 
                printf( "\n\n%-10s", "cos()" );
                for ( loop2 = -1.5; loop2 < 3.0; loop2 += 1.1 ) {
                    printf( "%10.2f", cos( loop2 ) );
                }
                break;

            case 13: 
                printf( "\n\n%-10s", "tan()" );
                for ( loop2 = -1.5; loop2 < 3.0; loop2 += 1.1 ) {
                    printf( "%10.2f", tan( loop2 ) );
                }
                break;
        } /* end switch */
        
        printf( "%s", "\n" );

    } /* end for */
    return 0;

} /* end main */