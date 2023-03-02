#include <stdio.h>
int main(void){
	int c = 1;
	int total = 0;
	while(c <= 10){
		printf("Enter ten grades,Marks %d\n",c);
		int grade = 0;
		scanf("%d",&grade);
		total += grade;
		c++;
	}
	printf("The Average:%f\n",(float)total / 10);
}
