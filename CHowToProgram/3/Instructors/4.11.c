/*
 theBitRiddler
 3/30/2023
 11:57 AM
 smallest
*/
#include <stdio.h>
int main(void) {
	int value = 0;
	int number = 0;
	int i = 0;
	int smallest = 0;
	
	printf("%s", "Enter the number of integers to be processed ");
	scanf("%d", &number);
	
	printf("%s", "Enter an integer ");
	scanf("%d", &smallest);
	
	for (i = 1; i <= number; ++i) {
		
		printf("%s", "Enter next integer ");
		scanf("%d", &value);
		
		if (smallest > value) 
			smallest = value;
	}
	
	printf("The smallest integer is %d\n", smallest);
}
