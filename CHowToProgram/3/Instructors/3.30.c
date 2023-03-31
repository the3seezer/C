<<<<<<< HEAD
/* 
 theBitRiddler
 3/23/2023
 12:43 PM
 rows and columns: what does this do?
*/
#include <stdio.h>
int main(void) {
	int row = 10;
	int column = 0;
	
	while (row >= 1) {
		column = 1;
		
		while (column <= 10) {
			printf("%s", row % 2 ? "<" : ">");
			++column;
		}
		--row;
		printf("%s", "\n");
	}
}
=======
/* 
 theBitRiddler
 3/23/2023
 12:43 PM
 rows and columns: what does this do?
*/
#include <stdio.h>
int main(void) {
	int row = 10;
	int column = 0;
	
	while (row >= 1) {
		column = 1;
		
		while (column <= 10) {
			printf("%s", row % 2 ? "<" : ">");
			++column;
		}
		--row;
		printf("%s", "\n");
	}
}
>>>>>>> 78d99489bc9fd084c8e4baa79a5431b5829ff12e
