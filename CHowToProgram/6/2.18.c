 /* Exercise 2.18 Solution */
 #include <stdio.h>

 int main()
 { 
 int x; /* define first number */
 int y; /* define second number */
 
 printf( "Enter two numbers: " ); /* prompt */
 scanf( "%d%d", &x, &y ); /* read two integers */
 
 /* compare the two numbers */
 if ( x > y ) {
 printf( "%d is larger\n", x );
 } /* end if */

 if ( x < y ) {
 printf( "%d is larger\n", y );
 } /* end if */

 if ( x == y ) {
 printf( "These numbers are equal\n" );
 }
  return 0; /* indicate successful termination */

 } /* end main */
