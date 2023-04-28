/*
 theBitRiddler
 4/28/2023
 1:56 PM
 Replacing unstructured break with a structured statement
*/
#include <stdio.h>
int main (void) {
	int x = 0;
	int breakOut = 1;
	
	for (x = 1; x <= 10 && breakOut == 1; x++) {
		
		if (x == 4) {
			
			breakOut = -1;
			
		}
		
		printf("%d ", x);
		
	}
	
	printf("\nBroke out of loop at %d\n", x);
}
