/*
 theBitRiddler
 5/8/2023
 9:52 AM
 Towers of Hanoi
*/
#include <stdio.h>

void tower( int d, int s, int e, int t );

int main( void ) {
	int disks = 0;
	int start = 1;
	int end = 3;
	int temp = 2;
	
	printf( "%s", "Enter the starting number of disks. ");
	scanf( "%d", &disks );
	
	tower( disks, start, end, temp );
		
}

void tower( int d, int s, int e, int t ) {
	
	if ( d == 1 ) {
		printf("%d --> %d\n", s, e );
		return;
	}
	
	tower( d - 1, s, t, e );
	
	printf("%d --> %d\n", s, e );
	
	tower( d - 1, t, e, s );
	
}
