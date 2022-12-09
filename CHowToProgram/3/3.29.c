#include <stdio.h>
int main(void){
	int row = 10;
	while(row >= 1){
		int column = 1;
		while(column <= 10){
			printf("%s", row % 2 ? "<" : ">");//printf_s("%d",row);
			++column;
		}
		--row;
		puts("");
	}
}
