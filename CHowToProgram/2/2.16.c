/* Exercise 2.16 Solution */
 #include <stdio.h>

 int main()
 {
 int x; /* define first number */
 int y; /* define second number */
 
 printf( "Enter two numbers: "); /* prompt user */
 scanf( "%d%d", &x, &y ); /* read values from keyboard */ 
 
 /* output results */
 printf( "The sum is %d\n", x + y );
 printf( "The product is %d\n", x * y );
 printf( "The difference is %d\n", x - y );
 printf( "The quotient is %d\n", x / y );
 printf( "The modulus is %d\n", x % y );

 return 0; /* indicate successful termination */

 } /* end main */
