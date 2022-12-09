#include <stdio.h>
int main(void){
	int A = 3;
	int counter = 1;
	printf_s("A\tA+2\tA+4\tA+6\n\n");
	while(counter <= 5){
		printf_s("%d\t%d\t%d\t%d\n",A,A + 2,A + 4,A + 6);
		A += 3;
		counter++;
	}
}
