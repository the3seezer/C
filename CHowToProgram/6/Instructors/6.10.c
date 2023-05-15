/* 
theBitRiddler
5/15/2023
10:03 AM
salaries and on commission
*/
#include <stdio.h>
int main( void ) {
    int salaries[ 11 ] = {0};
    int sales = 0;
    double salary = 0.0;
    double i = .09;

    printf_s( "%s", "Enter amount of sales. ( -1 to end ): " );
    scanf_s( "%d", &sales );

    while ( sales != -1 ){
        
        salary = 200.0 + sales * i;
        printf_s( "Employee Commission is %.2f\n", salary );

        if ( salary < 1000 && salary >= 200 ) {
            ++salaries[ ( int ) salary / 100 ];
        } /* end if */
        else if ( salary >= 1000 ){
            ++salaries[ 10 ];
        } /* end else if */

        printf_s( "%s", "Enter amount of sales. ( -1 to end ): " );
        scanf_s( "%d", &sales );

    } /* end while */

    printf_s( "%s", "Employees in the range: \n" );
    printf_s( "$200 - $299  :  %d\n", salaries[ 2 ] );
    printf_s( "$300 - $399  :  %d\n", salaries[ 3 ] );
    printf_s( "$400 - $499  :  %d\n", salaries[ 4 ] );
    printf_s( "$500 - $599  :  %d\n", salaries[ 5 ] );
    printf_s( "$600 - $699  :  %d\n", salaries[ 6 ] );
    printf_s( "$700 - $799  :  %d\n", salaries[ 7 ] );
    printf_s( "$800 - $899  :  %d\n", salaries[ 8 ] );
    printf_s( "$900 - $999  :  %d\n", salaries[ 9 ] );
    printf_s( " Over $1000  :  %d\n", salaries[ 10 ] );

    return 0;
} /* end main */