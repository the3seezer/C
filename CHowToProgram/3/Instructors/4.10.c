/*
 theBitRiddler
 3/30/2023
 11:44 AM
 Average
*/
#include <stdio.h>
int main(void) {
	int value = 0;
	int count = 0;
	int total = 0;
	
	printf("%s", "Enter an integer (9999 to end) ");
	scanf("%d", &value);
	
	while (value != 9999) {
		total += value;
		count++;
		
		printf("%s", "Enter next integer (9999 to end) ");
		scanf("%d", &value);
	}
	
	if (count != 0) {
		printf("The average is %.2f\n", (double) total / count);
	}
	else {
		printf("%s", "No value was entered \n");
	}
}
