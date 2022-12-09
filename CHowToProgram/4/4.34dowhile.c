#include <stdio.h>
int main(void){
	int c = 1;
	int total = 0;
	do{
		printf("Enter ten grades: number:%d\n",c);
		int grade = 0;
		scanf("%d",&grade);
		total += grade;
	}while(++c <= 10);
	printf("The Average:%f\n",(float) total / 10);
}
