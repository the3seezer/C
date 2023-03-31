/*
 theBitRiddler
 3/31/2023
 11:43 AM
 Triangles
*/
#include <stdio.h>
int main(void) {
	int row = 0;
	int col = 0;
	int space = 0;
	
	for (row = 1; row <= 10; ++row) {
		
		for (col = 1; col <= row; ++col) {
			printf("%s", "*");
		}
		
		printf("%s", "\n");
	}
	
	puts("\n");
	
	for (row = 10; row >= 1; --row) {
		
		for (col = 1; col <= row; ++col) {
			printf("%s", "*");
		}
		
		printf("%s", "\n");
	}
	
	puts("\n");
	
	for (row = 10; row >= 1; --row) {
		
		for (space = 1; space <= 10 - row; ++space) {
			printf("%s", " ");
		}
		
		for (col = 1; col <= row; ++col) {
			printf("%s", "*");
		}
		
		printf("%s", "\n");
	}
	
	puts("\n");
	
	for (row = 1; row <= 10; ++row) {
		
		for (space = 1; space <= 10 - row; ++space) {
			printf("%s", " ");
		}
		
		for (col = 1; col <= row; ++col) {
			printf("%s", "*");
		}
		
		printf("%s", "\n");
	}
}
