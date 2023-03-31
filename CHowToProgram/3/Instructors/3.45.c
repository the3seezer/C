/*
 theBitRiddler
 3/26/2023
 4:50 PM
 Triangle or not
*/
#include <stdio.h>
int main(void) {
	int a = 0;
	int b = 0;
	int c = 0;
	
	printf("%s", "Enter the three integer point numbers ");
	scanf("%d%d%d", &a, &b, &c);
	
	if (c * c == b * b + a * a) {
		printf("%s", "The three numbers could be sides of a triangle\n");
	}
	else {
		printf("%s", "The three numbers probability ");
		printf("%s", "are not the sides of a triangle\n");
	}
}
