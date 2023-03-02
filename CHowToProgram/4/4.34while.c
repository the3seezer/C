#include <stdio.h>
int main(void){
	int total = 0;
	int n = 0;
	while(n < 10){
		int enter = 0;
		printf("Enter grade digit number %d\n",n + 1);
		scanf("%d",&enter);
		total += enter;
		n++;
	}
	printf("The average : %f\n",(float)total / n);
}
