/*
 theBitRiddler
 3/22/2023
 2:58 PM
 gross pay
*/
#include <stdio.h>
int main(void) {
	double hours = 0;
	double rate = 0;
	double salary = 0;
	
	printf("%s", "Enter the number of hours worked (-1 to end): ");
	scanf("%lf", &hours);
	
	while (hours != -1.0) {
		printf("%s", "Enter hourly rate of the worker ($00.0): ");
		scanf("%lf", &rate);
		
		if (hours <= 40.0) {
			salary = hours * rate;
		}
		else {
			salary = 40.0 * rate + (hours - 40) * rate * 1.5;
		}
		
		printf("Salary is %.2f\n\n", salary);
		
		printf("%s", "Enter the number of hours worked (-1 to end): ");
		scanf("%lf", &hours);
	}
}
