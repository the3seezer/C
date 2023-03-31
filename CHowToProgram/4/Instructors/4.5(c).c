/*
 theBitRiddler
 3/30/2023
 9:37 AM
 error correcting
*/
#include <stdio.h>
int main(void) {
	int intval = 0;
	int charval = 0;
	
	printf("%s", "Enter an integer and a character ");
	scanf("%d", &intval);
//	charval = getchar(); 
							/*  charVal will read the return character
						 when the user types in intVal and hits return.
						 But it works perfectly!!! */
	/* solution: scanf should
		be used to read in charVal. */
	scanf("\n%c", &charval);
	printf("Integer %d\nCharacter %c\n", intval, charval);
}
