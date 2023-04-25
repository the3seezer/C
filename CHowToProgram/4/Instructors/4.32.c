/*
 theBitRiddler
 4/25/2023
 5:44 PM
 Optimizable diamond size (1 to 19) in 
 even number
*/
#include <stdio.h>
int main(void) {
	int line = 0;
	int space = 0;
	int asterisk = 0;
	int size = 0;
	
	printf("%s", "Enter an odd number for the diamond size ( 1-19 ):\n" );
	scanf("%d", &size);
	
	for (line = 1; line <= size - 2; line += 2) {
		
		for (space = (size - line) / 2; space > 0; space--) {
			
			printf("%s", " ");
			
		}
		
		for (asterisk = 1; asterisk <= line; asterisk++) {
			
			printf("%s", "*");
			
		}
		
		printf("%s", "\n");
		
	}
	
	
	for (line = size; line >= 1; line -= 2) {
		
		for (space = (size - line) /2; space > 0; space--) {
			
			printf("%s", " ");
			
		}
		
		for (asterisk = 1; asterisk <= line; asterisk++) {
			
			printf("%s", "*");
			
		}
		
		printf("%s", "\n");
		
	}
	
}
