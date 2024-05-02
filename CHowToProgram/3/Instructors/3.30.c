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