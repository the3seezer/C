/*
 theBitRiddler
 4/25/2023
 5:15 PM
 Diamond shape
*/
#include <stdio.h>
int main(void) {
	int line = 0;
	int space = 0;
	int asterisk = 0;
	
	
	for (line = 1; line <= 9; line += 2) {
		
		for (space = (9 - line) / 2; space > 0; space--) {
			
			printf("%s", " ");
			
		}
		
		for (asterisk = 1; asterisk <= line; asterisk++) {
			
			printf("%s", "*");
			
		}
		
		printf("%s", "\n");
		
	}
	
	
	for (line = 7; line >= 1; line -= 2) {
		
		for (space = (9 - line) / 2; space > 0; space--) {
			
			printf("%s", " ");
			
		}
		
		for (asterisk = 1; asterisk <= line; asterisk++) {
			
			printf("%s", "*");
			
		}
		
		printf("%s", "\n");
		
	}
}
