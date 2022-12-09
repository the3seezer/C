#include <stdio.h>
int main(void){
	int number = 0;
	int counter = 1;
	int largest = 0;
	while(counter <= 10){
		printf_s("%s","Enter a number: ");
		scanf("%d",&number);
		if(largest < number){
			largest = number;
		}
		printf_s("The largest number so far: %d\n",largest);
		counter++;		
	}
}
