/*
 theBitRiddler
 3/30/2023
 9:55 AM
 Error correcting
*/
#include <stdio.h>
int main(void) {
//	float x = 0;
//	 for (x = .000001; x <= .0001; x += .000001)
//	 	printf("%.7f\n", x);
	
	puts("\n");
	for (int x = 1; x <= 100; x += 1)
    	printf("%.7f\n", (double) x / 100000);	
}
