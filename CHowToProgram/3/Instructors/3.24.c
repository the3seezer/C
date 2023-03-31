<<<<<<< HEAD
/*
 theBitRiddler
 3/22/2023
 3:26 PM
 Largest number
*/
#include <stdio.h>
int main(void) {
	int largest = 0;
	int number = 0;
	int counter = 0;
	
	printf("%s", "Enter the first number: ");
	scanf("%d", &largest);
	counter = 2;
	
	while (counter <= 10) {
		printf("%s", "Enter the next number: ");
		scanf("%d", &number);
		
		if (largest < number) {
			largest = number;
		}
		
		counter++;
	}
	
	printf("Largest is %d", largest);
}
=======
/*
 theBitRiddler
 3/22/2023
 3:26 PM
 Largest number
*/
#include <stdio.h>
int main(void) {
	int largest = 0;
	int number = 0;
	int counter = 0;
	
	printf("%s", "Enter the first number: ");
	scanf("%d", &largest);
	counter = 2;
	
	while (counter <= 10) {
		printf("%s", "Enter the next number: ");
		scanf("%d", &number);
		
		if (largest < number) {
			largest = number;
		}
		
		counter++;
	}
	
	printf("Largest is %d", largest);
}
>>>>>>> 78d99489bc9fd084c8e4baa79a5431b5829ff12e
