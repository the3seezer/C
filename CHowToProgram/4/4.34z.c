#include <stdio.h>
int main(void){
	int n = 0;
	int total = 0;
	do{
		int enter = 0;
		printf("Enter ten grade in digit number %d: \n",n + 1);
		scanf("%d",&enter);
		total += enter;
	}while(++n < 10);
	printf("The average: %f\n",(float)total / n);printf("%d",n);
}
