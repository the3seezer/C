/*
 theBitRiddler
 3/30/2023
 11:29 AM
 What does it do?
*/
#include <stdio.h>
int main(void) {
	int x = 0;
	int y = 0;
	int i = 0;
	int j = 0;
	
	printf("%s", "Enter two integers in the range of 1 to 20: ");
	scanf("%d%d", &x, &y);
	
	for (i = 1; i <= y; i++) {
		for (j = 1; j <= x; ++j) {
			printf("%s", "@");
		}
		printf("%s", "\n");
	}
}
