/* 
 theBitRiddler
 3/22/2023
 2:39 PM
 principal, rate, term and interest
*/
#include <stdio.h>
int main(void) {
	double principal = 0;
	double rate = 0;
	double days = 0;
	double interest = 0;
	
	printf("%s", "Enter loan principal (-1 to end): ");
	scanf("%lf", &principal);
	
	while (principal != -1.0) {
		printf("%s", "Enter interest rate: ");
		scanf("%lf", &rate);
		
		printf("%s", "Enter term of the loan in days: ");
		scanf("%lf", &days);
		
		interest = principal * rate * days / 365;
		
		printf("The interest charge is : %.2f\n\n", interest);
		
		printf("%s", "Enter loan principal (-1 to end): ");
		scanf("%lf", &principal);
	}
}