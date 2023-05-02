/*
 theBitRiddler
 5/2/2023
 12:12 PM
  For each of the following sets of integers, 
  write a single statement that will print a 
  number at random from the set.
  a) 2, 4, 6, 8, 10
  b) 3, 5, 7, 9, 11
  c) 6, 10, 14, 18, 22
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void) {
	srand( time( NULL ) );
	
	/* (a) */
	printf("a)  %d\n", 2 * ( 1 + rand() % 5 ) );
	
	printf("b)  %d\n", 1 + 2 * ( 1 + rand() % 5 ) );
	
	printf("c)  %d or %d\n", 6 + 4 * ( rand() % 5 ), 2 + 4 * ( 1 + rand() % 5 ) );
	
}
