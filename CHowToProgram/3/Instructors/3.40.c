<<<<<<< HEAD
/*
 theBitRiddler
 3/26/2023
 12:41 PM
 checkboard
*/
#include <stdio.h>
int main(void) {
	int side = 8;
	int row = 0;
	int mod = 0;
	
	while (side >= 1) {
		row = 8;
		mod = side % 2;
		
		while (row >= 1) {
			
			if (mod) {
				printf("%s", " ");
				mod = 0;
			}
			
			printf("%s", "* ");
			--row;
		}
		
		printf("%s", "\n");
		--side;
	}
}
=======
/*
 theBitRiddler
 3/26/2023
 12:41 PM
 checkboard
*/
#include <stdio.h>
int main(void) {
	int side = 8;
	int row = 0;
	int mod = 0;
	
	while (side >= 1) {
		row = 8;
		mod = side % 2;
		
		while (row >= 1) {
			
			if (mod) {
				printf("%s", " ");
				mod = 0;
			}
			
			printf("%s", "* ");
			--row;
		}
		
		printf("%s", "\n");
		--side;
	}
}
>>>>>>> 78d99489bc9fd084c8e4baa79a5431b5829ff12e
