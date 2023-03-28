 /* Exercise 2.20 Solution */
 #include <stdio.h>

 int main()
 { 
 int radius; /* circle radius */

 printf( "Input the circle radius: " ); /* prompt user */
 scanf( "%d", &radius ); /* read integer radius */

 /* calculate and output diameter, circumference and area */
 printf( "\nThe diameter is %d\n", 2 * radius );
 printf( "The circumference is %f\n", 2 * 3.14159 * radius );
 printf( "The area is %f\n", 3.14159 * radius * radius );

 return 0; /* indicate successful termination */

 } /* end main */
