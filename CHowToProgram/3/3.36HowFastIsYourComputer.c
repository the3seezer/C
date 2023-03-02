#include <stdio.h>
//measuring my own computer speed
int main(void){
	int counter = 1;
	while(counter <= 1000000000){
		if((counter % 100000000) == 0){
			printf_s("%d\n",counter);
		}
		counter++;
	}
}
