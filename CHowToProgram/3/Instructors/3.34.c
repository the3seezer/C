/* 
 theBitRiddler
 3/25/2023
 9:24 AM
 Print Hollow Squares
*/
#include <stdio.h>
int main(void) {
	int side = 0; /* side counter */
	int rowPosition = 0; /* row counter */
	int size = 0; /* size of the square */
	
	printf("%s", "Enter the square side ");
	scanf("%d", &side);
	
	size = side;
	
	/* loop throught side */
	while (side > 0) {
		rowPosition = size;
		
		/* loop throught row */
		while (rowPosition > 0) {
			
			if (side == size) {
				printf("%s", "*");
			}
			else if (side == 1) {
				printf("%s", "*");
			}
			else if (rowPosition == size) {
				printf("%s", "*");
			}
			else if (rowPosition == 1) {
				printf("%s", "*");
			}
			else {
				printf("%s", " ");
			}
			
			rowPosition--;
		} /* end while */
		
		printf("%s", "\n");
		side--;
	} /* end while */
}