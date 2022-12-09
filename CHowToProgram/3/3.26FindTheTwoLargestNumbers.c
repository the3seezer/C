#include <stdio.h>
int main(void){
	int number = 0;
	int number2 = 0;
	int counter = 2;
	int larger = 0;
	int largest = 0;
	while(counter <= 10){
		printf_s("%s","Enter a number: \n");
		scanf_s("%d",&number);
		printf_s("%s","Enter another number: \n");
		scanf_s("%d",&number2);
		if(number < number2){
			if(larger < number){
				larger = number;
			}
			if(largest < number2){
				largest = number2;
			}	
		}//end if
		else if(number > number2){
			if(larger < number2){
				larger = number2;
			}
			if(largest < number){
				largest = number;
			}
		}
		printf_s("The largest number so far: %d\nThe lesser: %d\n",largest,larger);
		counter += 2;
	}
}
