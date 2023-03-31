<<<<<<< HEAD
/*
 theBitRiddler
 3/25/2023
 9:07 AM
 print the squares
*/
#include <stdio.h>
int main(void) {
	int side = 0; /* side counter */
	int temp = 0; /* temporary integer */
	int asterisk = 0; /* asterisk counter */
	
	printf("%s", "Enter the square side ");
	scanf("%d", &side);
	
	temp = side;
	
	/* loop throught row */
	while (side-- > 0) {
		asterisk = temp;
		
		/* loop throught column */
		while (asterisk-- > 0) {
			printf("%s", "*");
		}
		
		putchar('\n');
	}
}
=======
/*
 theBitRiddler
 3/25/2023
 9:07 AM
 print the squares
*/
#include <stdio.h>
int main(void) {
	int side = 0; /* side counter */
	int temp = 0; /* temporary integer */
	int asterisk = 0; /* asterisk counter */
	
	printf("%s", "Enter the square side ");
	scanf("%d", &side);
	
	temp = side;
	
	/* loop throught row */
	while (side-- > 0) {
		asterisk = temp;
		
		/* loop throught column */
		while (asterisk-- > 0) {
			printf("%s", "*");
		}
		
		putchar('\n');
	}
}
>>>>>>> 78d99489bc9fd084c8e4baa79a5431b5829ff12e
