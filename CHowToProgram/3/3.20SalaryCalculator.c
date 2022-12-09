#include <stdio.h>
int main(void){
	float hours = 0;
	float rate = 0;
	printf_s("%s","Enter # of hours worked (-1 to end): ");
	scanf("%f",&hours);
	while(hours != -1){
		printf_s("%s","Enter hourly rate of the worker ($00.0): ");
		scanf("%f",&rate);
		printf("Salary is $%.2f\n\n",(hours > 40 )? (((hours - 40) * .5) + hours) * rate : hours * rate);
		printf_s("%s","Enter # of hours worked (-1 to end): ");
		scanf("%f",&hours);
	}
}
