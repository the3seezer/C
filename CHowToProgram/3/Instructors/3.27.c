/*
 theBitRiddler
 3/23/2023
 11:32 AM
 Largest and Second Largest
*/
#include <stdio.h>
int main(void) {
	int largest = 0;
	int secondLargest = 0;
	int number = 0;
	int counter = 0;
	
	printf("%s", "Enter the first number: ");
	scanf("%d", &largest);
	counter = 2;
	
	while (counter <= 10) {
		printf("%s", "Enter the next number: ");
		scanf("%d", &number);
		
		if (number > largest) {
			secondLargest = largest;
			largest = number;
		}
		else {
			if (number > secondLargest) {
				secondLargest = number;	
			}
		}
		counter++;
	} /* end while */
	
	printf("Largest is %d\nSecond Largest is %d\n", largest, secondLargest);
}
