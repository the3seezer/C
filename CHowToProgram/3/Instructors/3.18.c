/* 
 theBitRiddler
 3/6/2023
 2:29 PM
 Account, Balance, Charges, Credits and Limits
*/
#include <stdio.h>
int main(void) {
	double account = 0;
	double balance = 0;
	double charges = 0;
	double credits = 0;
	double limits = 0;
	
	printf("%s", "Enter account number (-1 to end) ");
	scanf("%lf", &account);
	
	while (account != -1) {
		printf("%s", "Enter beginning balance ");
		scanf("%lf", &balance);
		
		printf("%s", "Enter total charges ");
		scanf("%lf", &charges);
		
		printf("%s", "Enter total credits ");
		scanf("%lf", &credits);
		
		printf("%s", "Enter credit limit ");
		scanf("%lf", &limits);
		
		balance += charges - credits;
		
		if (balance > limits) {
			printf("%s%f\n%s%f\n%s%f\n%s",
			"Account       ", account, "Credit Limit ", limits, 
			"Balance     ", balance, "Credit Limit exceeded");
		}
		
		printf("%s", "\nEnter account number (-1 to end) ");
		scanf("%lf", &account);
	}
}
