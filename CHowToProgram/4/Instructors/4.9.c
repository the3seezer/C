/*
 theBitRiddler
 3/30/2023
 11:36 AM
 sum of values
*/
#include <stdio.h>
int main(void) {
	int sum = 0;
	int value = 0;
	int number = 0;
	int i = 0;
	
	printf("%s", "Enter the number of values to be processed ");
	scanf("%d", &number);
	
	for (i = 1; i <= number; ++i) {
		printf("%s", "Enter the value ");
		scanf("%d", &value);
		
		sum += value;
	}
	
	printf("The sum of the %d value is %d\n", number, sum);
}
