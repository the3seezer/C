 /* Exercise 6.31 Solution 
  (Bucket Sort) A bucket sort begins with an single-subscripted array of positive integers to be sorted, and a double-subscripted array of integers with rows subscripted from 0 to 9 and columns subscripted from 0 to n - 1 where n is the number of values in
the array to be sorted. Each row of the double-subscripted array is referred to as a bucket. Write a function bucketSort that takes
an integer array and the array size as arguments. 
The algorithm is as follows:
1) Loop through the single-subscripted array and place each of its values in a row of the bucket array based on its ones digit.
For example, 97 is placed in row 7, 3 is placed in row 3 and 100 is placed in row 0.
2) Loop through the bucket array and copy the values back to the original array. The new order of the above values in the
single-subscripted array is 100, 3 and 97.
3) Repeat this process for each subsequent digit position (tens, hundreds, thousands, etc.) and stop when the leftmost digit
of the largest number has be processed. 
On the second pass of the array, 100 is placed in row 0, 3 is placed in row 0 (it had only one digit) and 97 is placed in row 9. The
order of the values in the single-subscripted array is 100, 3 and 97. On the third pass, 100 is placed in row 1, 3 is placed in row zero
and 97 is placed in row zero (after 3). The bucket sort is guaranteed to have all the values properly sorted after processing the left most digit of the largest number. The bucket sort knows it is done when all the values are copied into row zero of the double-subscripted array. 
Note that the double-subscripted array of buckets is ten times the size of the integer array being sorted. This sorting technique
provides better performance than a bubble sort, but requires much larger storage capacity. Bubble sort requires only one additional
memory location for the type of data being sorted. Bucket sort is an example of a space-time trade-off. It uses more memory, but
performs better. This version of the bucket sort requires copying all the data back to the original array on each pass. Another possibility is to create a second double-subscripted bucket array and repeatedly move the data between the two bucket arrays until all the
data is copied into row zero of one of the arrays. Row zero then contains the sorted array.*/

 #include <stdio.h>

 /* symbolic constant SIZE must be defined as the array size
 for bucketSort to work */
 #define SIZE 12

 /* function prototypes */
 void bucketSort( int a[] );
 void distributeElements( int a[], int buckets[][ SIZE ], int digit );
 void collectElements( int a[], int buckets[][ SIZE ] );
 int numberOfDigits( int b[], int arraySize );
 void zeroBucket( int buckets[][ SIZE ] );

 int main()
 { 

 /* array to be sorted */
 int array[ SIZE ] = { 19, 13, 5, 27, 1, 26, 31, 16, 2, 9, 11, 21 };
 int i; /* loop counter */

 printf( "Array elements in original order:\n" );

 /* display the unsorted array */
 for ( i = 0; i < SIZE; i++ ) {
 printf( "%3d", array[ i ] );
 } /* end for */

 putchar( '\n' );
 bucketSort( array ); /* sort the array */

 printf( "\nArray elements in sorted order:\n" );

 /* display sorted array */
 for ( i = 0; i < SIZE; i++ ) {
 printf( "%3d", array[ i ] );
 } /* end for */

 putchar( '\n' );

 return 0; /* indicate successful termination */

 } /* end main */

 /* Perform the bucket sort algorithm */
 void bucketSort( int a[] )
 { 
 int totalDigits; /* largest # of digits in array */
 int i; /* loop counter */
 int bucket[ 10 ][ SIZE ] = { 0 }; /* initialize bucket array */

 totalDigits = numberOfDigits( a, SIZE ); 

 /* put elements in buckets for sorting 
 one sorted, get elements from buckets */
 for ( i = 1; i <= totalDigits; i++ ) { 
 distributeElements( a, bucket, i );
 collectElements( a, bucket );

 /* set all bucket contents to zero */
 if ( i != totalDigits ) {
 zeroBucket( bucket ); 
 } /* end if */

 } /* end for */

 } /* end function bucketSort */

 /* Determine the number of digits in the largest number */
 int numberOfDigits( int b[], int arraySize )
 { 
 int largest = b[ 0 ]; /* assume first element is largest */
 int i; /* loop counter */
 int digits = 0; /* total number of digits */

 /* find largest array element */
 for ( i = 1; i < arraySize; i++ ) {

 if ( b[ i ] > largest ) {
 largest = b[ i ];
 } /* end if */

 } /* end for */

 /* find number of digits of largest element */
 while ( largest != 0 ) { 
 ++digits;
 largest /= 10;
 } /* end while */

 return digits; /* return number of digits */

 } /* end function numberOfDigits */

 /* Distribute elements into buckets based on specified digit */
 void distributeElements( int a[], int buckets[][ SIZE ], int digit )
 { 
 int divisor = 10; /* used to get specific digit */
 int i; /* loop counter */
 int bucketNumber; /* current bucket number */
 int elementNumber; /* current element number */

 /* determine the divisor */
 for ( i = 1; i < digit; i++ ) { 
 divisor *= 10; 
 } /* end for */

 /* bucketNumber example for hundreds digit: */
 /* ( 1234 % 1000 - 1234 % 100 ) / 100 --> 2 */
 for ( i = 0; i < SIZE; i++ ) { 
 bucketNumber = ( a[ i ] % divisor - a[ i ] % ( divisor / 10 ) ) /
 ( divisor / 10 );

 /* retrieve value in buckets[ bucketNumber ][ 0 ] to determine */
 /* which element of the row to store a[ i ] in. */
 elementNumber = ++buckets[ bucketNumber ][ 0 ];
 buckets[ bucketNumber ][ elementNumber ] = a[ i ];
 } /* end for */

 } /* end function distributeElements */

 /* Return elements to original array */
 void collectElements( int a[], int buckets[][ SIZE ] )
 { 
 int i; /* loop counter */
 int j; /* loop counter */
 int subscript = 0; /* current subscript */

 /* retrieve elements from buckets */
 for ( i = 0; i < 10; i++ ) {

 for ( j = 1; j <= buckets[ i ][ 0 ]; j++ ) {
 a[ subscript++ ] = buckets[ i ][ j ];
 } /* end for */

 } /* end for */

 } /* end function collectElements */

 /* Set all buckets to zero */
 void zeroBucket( int buckets[][ SIZE ] )
 { 
 int i; /* loop counter */
 int j; /* loop counter */

 for ( i = 0; i < 10; i++ ) {

 for ( j = 0; j < SIZE; j++ ) {
 buckets[ i ][ j ] = 0;
 } /* end for */

 } /* end for */

 } /* end function zeroBucket */