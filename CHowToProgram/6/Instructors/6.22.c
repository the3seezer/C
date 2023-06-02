/* 
 theBitRiddler
 5/31/2023
 6:28 PM
 Salespersons, product, value and totalsales by product and by person = 0;
*/
#include <stdio.h>
int main( void ) {
    double sales[ 4 ][ 5 ] = {0.0};
    double productSales[ 5 ] = {0.0}; /* by product */
    double totalSales = 0.0;  /* by salesPerson */
    int value = 0;
    int salesPerson = 0;
    int product = 0;

    printf_s( "%s", "Enter salesPerson, product and sales \n" );
    printf_s( "%s", "Enter -1 for salesPerson to end input: \n" );
    scanf_s( "%d", &salesPerson );

    while ( salesPerson != -1 ) {
        scanf_s( "%d%d", &product, &value );
        sales[ salesPerson ][ product ] = value;
        scanf_s( "%d", &salesPerson );
    }

    printf_s( "%s\n%s\n%s\n%s\n%s\n", "The total sales for each salesPerson ",
    "are displayed at the end of each", " row, and the total sales of each ",
    "are displayed at the bottom ", "of each column " ); 
    printf_s( " %8d%8d%8d%8d%8d\n", 1, 2, 3, 4, 5 );

    for ( size_t i = 0; i <= 3; i++ ) {
        totalSales = 0.0;
        printf_s( "%d", i );

        for ( size_t j = 0; j <= 4; j++ ) {
            totalSales += sales[ i ][ j ];
            printf_s( "%8.2f", sales[ i ][ j ] );
            productSales[ j ] += sales[ i ][ j ];
        }

        printf_s( "%8.2f\n", totalSales );

    }

    printf_s( "%s", " " );

    for ( size_t i = 0; i <= 4; i++ ) {
        printf_s( "%8.2f", productSales[ i ] );
    }

} /* end main */