/*
 theBitRiddler
 4/28/2023
 2:07 PM
 Replace unstructured continue with a structured statement
*/
#include <stdio.h>
int main(void) {
	
	int x = 0;
	
	for (x = 1; x <= 10; x++) {
		
		if (x == 5) {
			
			++x; 
			
		}
		
		printf("%d ", x);
		
	}
	
	printf("%s", "\nUsed ++x to skip printing the value of 5\n");
	
}
