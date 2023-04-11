 /* Exercise 4.34 Solution */
 #include <stdio.h>

 int main( void )
 { 
 int loop; /* loop counter */
 int number; /* current number */
 int temp1; /* temporary integer */

 /* print table headers */
 printf( "Decimal\t\tBinary\t\tOctal\t\tHexadecimal\n" );

 /* loop through values 1 to 256 */
 for ( loop = 1; loop <= 256; loop++ ) { 
 printf( "%d\t\t", loop );
 number = loop;

 /* binary numbers */
 printf( "%c", number == 256 ? '1' : '0' );

 printf( "%c", number < 256 && number >= 128 ? '1' : '0' );
 number %= 128;

 printf( "%c", number < 128 && number >= 64 ? '1' : '0' );
 number %= 64;

 printf( "%c", number < 64 && number >= 32 ? '1' : '0' );
 number %= 32;

 printf( "%c", number < 32 && number >= 16 ? '1' : '0' );
 number %= 16;

 printf( "%c", number < 16 && number >= 8 ? '1' : '0' );
 number %= 8;

 printf( "%c", number < 8 && number >= 4 ? '1' : '0' );
 number %= 4;

 printf( "%c", number < 4 && number >= 2 ? '1' : '0' );
 number %= 2;

 printf( "%c\t", number == 1 ? '1' : '0' );
 /* octal numbers */
 number = loop;

 printf( "%d", number < 512 && number >= 64 ? number / 64 : 0 );
 number %= 64;

 printf( "%d", number < 64 && number >= 8 ? number / 8 : 0 );
 number %= 8;

 printf( "%d\t\t", number == 0 ? 0 : number );

 /* hexadecimal numbers */
 number = loop;
 temp1 = 16;

 if ( number < 4096 && number >= 256 ) {
 printf( "%d", number / 256 );
 } /* end if */

 if ( number < 256 && number >= 16 ) { 
 temp1 = number / 16;
 number %= 16;
 } /* end if */
 else {
 printf( "0" );
 } /* end else */

 /* convert to letter if temp1 is above 9 */
 if ( temp1 <= 9 ) {
 printf( "%d", temp1 );
 } /* end if */
 else if ( temp1 >= 10 && temp1 <= 15 ) {
 printf( "%c", 'A' + ( temp1 - 10 ) );
 } /* end else if */

 /* convert to letter if number is above 9 */
 if ( number <= 9 ) {
 printf( "%d", number );
 } /* end if */
 else if ( number >= 10 && number <= 15 ) {
 printf( "%c", 'A' + ( number - 10 ) );
 } /* end else if */

 printf( "\n" );
 } /* end for */

 return 0; /* indicate successful termination */

 } 
