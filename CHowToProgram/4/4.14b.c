#include <stdio.h>
int main(void){
	for(int i = 1;i <= 20;i++){
		int factorial = 1;
		for(int j = 1;j <= i;j++){
			factorial *= j;
			if(j == i){
				printf("Factorial of %d is %d\n",i,factorial);
			}
			puts("");
		}
	}
}
