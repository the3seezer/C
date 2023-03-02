#include <stdio.h>
int main(void){
	int sevens = 0;
	int counter = 1;
	printf_s("%s","print a 5 digits or fewer integer");
	int number = 0;
	scanf_s("%d",&number);
	int store = number;
	while(counter <= 5){
		int remainder = number % 10;printf("%d\n",remainder);
		if(remainder == 7){
			++sevens;
		}
		number /= 10;
		counter++;
	}
	printf_s("%d sevens in %d",sevens,store);
}

