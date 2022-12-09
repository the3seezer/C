#include <stdio.h>
int main(void){
	int row = 1;
	while(row <= 8){
		int column = 1;
		while(column <= 8){
			printf_s("%s","* ");
			++column;
		}
		puts("");//outputs a newline
		if(row % 2){
			printf_s("%s"," ");
		}
		//row % 2 ? printf_s("%s"," ") : printf_s("");//odds are true and evens are false
		//printf_s("%s",row % 2 == 0 ? " " : ""); multiples of 2
		row++;
	}
}
