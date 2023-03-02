#include <stdio.h>

int main(void){
	int x = 1;
	int total = 0;
	
	while(x <= 10){
		int y = x * x;
		printf_s("%d\n",y);
		total += y;
		++x;
	}
	printf_s("Total is %d\n",total);
}
