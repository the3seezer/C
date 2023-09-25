/*
theBitRiddler
9/23/2023
1:05 PM
(Calculator Using Function Pointers
 addition, substraction, multiplication and division ) 
*/
#include <stdio.h>

void add( double, double );
void minus( double, double );
void multiply( double, double );
void divide( double, double );
void printMenu( void );

int main(void) {
    void ( * operate[ 4 ] ) ( double, double ) = { add, minus, multiply, divide };

    double number1 = 0;
    double number2 = 0;
    int choice = 0;

    while ( choice >= 0 && choice < 4 ) {
        do {
            printMenu();
            scanf( "%d", &choice );
        }
        while ( choice < -1 || choice > 3 );

        if ( choice == -1 )
            break;

        printf_s( "%s", "\tEnter the first and the second number: ");
        scanf( "%lf%lf", &number1, &number2 );

        ( * operate[ choice ] ) ( number1, number2 );
    } // end while 

    printf_s( "%s", "Program ended\n" );
} /* end main */

void printMenu(void) {
    printf_s( "%s", "\n\tEnter a choice to operate: \n"
                    "\t0 Addition\n"
                    "\t1 Substration\n"
                    "\t2 Multiplication\n"
                    "\t3 Division\n"
                    "\t-1 to end\n"
                    "\t? ");
} /* end function printMenu */

void add( double num1, double num2 ) {
    printf_s( "\t%.2lf + %.2lf == %.2lf\n", num1, num2, num1 + num2 );
} /* end function add */

void minus( double num1, double num2 ) {
    printf_s( "\t%.2lf - %.2lf == %.2lf\n", num1, num2, num1 - num2 );
} /* end function minus */

void multiply( double num1, double num2 ) {
    printf_s( "\t%.2lf x %.2lf == %.2lf\n", num1, num2, num1 * num2 );
} /* end function multiply */

void divide( double num1, double num2 ) {
    printf_s( "\t%.2lf / %.2lf == %.2lf\n", num1, num2, num1 / num2 );
} /* end function divide */