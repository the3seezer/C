#include <stdio.h>
int main(void){
	int factorial = 1;
	for(int i = 1;i <= 5;i++){
		factorial *= i;
	}
	printf("%d\n",factorial);
}
