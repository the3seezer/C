#include <stdio.h>
int main(void){
	int counter = 1;
	int one = 0;
	int two = 0;
	int three = 0;
	int four = 0;
	int five = 0;
	for(;counter <= 5;counter++){
		if(counter == 1){
			one = counter;
		}
		if(counter == 2){
			two = counter;
		}
		if(counter == 3){
			three = counter;
		}
		if(counter == 4){
			four = counter;
		}
		if(counter == 5){
			five = counter;
		}
	}
	printf("%d\t%d\t%d\t%d\t%d",one,two,three,four,five);
}
