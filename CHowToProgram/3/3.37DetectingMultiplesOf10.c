#include <stdio.h>
int main(void){
	int counter = 1;
	while(counter <= 100){
		printf_s("%s","*");
		if(counter % 10 == 0){
			puts("");
		}
		++counter;
	}
}
