 /* Exercise 2.19 Solution */
 #include <stdio.h>

 int main()
 { 
 int a; /* define first integer */
 int b; /* define second integer */
 int c; /* define third integer */
 int smallest; /* smallest integer */
 int largest; /* largest integer */
 
 printf( "Input three different integers: " ); /* prompt user */
 scanf( "%d%d%d", &a, &b, &c ); /* read three integers */

 /* output sum, average and product of the three integers */
 printf( "Sum is %d\n", a + b + c );
 printf( "Average is %d\n", ( a + b + c ) / 3 );
 printf( "Product is %d\n", a * b * c );
 
 smallest = a; /* assume first number is the smallest */
 
 if ( b < smallest ) { /* is b smaller? */
 smallest = b;
 } /* end if */
 
 if ( c < smallest ) { /* is c smaller? */
 smallest = c;
 } /* end if */
 
 printf( "Smallest is %d\n", smallest );

 largest = a; /* assume first number is the largest */
 
 if ( b > largest ) { /* is b larger? */
 largest = b;
 } /* end if */

 if ( c > largest ) { /* is c larger? */
 largest = c;
 } /* end if */

 printf( "Largest is %d\n", largest );

 return 0; /* indicate successful termination */

 } /* end main */
