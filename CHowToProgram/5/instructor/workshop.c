/* 
 theBitRiddler
 5/3/2023
 7:18 pm
 workshop
*/
#include <stdio.h>
int main( void ) {
	long double y = 0.0;
	printf( "%s", "Enter any digit: ");
	scanf( "%lf", &y );
	
	printf( "The long double is %Lf\n", y );
	
	
	/* The character issue is not checked out */
	char x = '0';
	printf( "%s", "Enter a character: " );
	scanf( "%c", &x );
	
	printf("The character is %c\n", x );
	
	
	
}
