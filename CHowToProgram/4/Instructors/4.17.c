/*
 theBitRiddler
 3/31/2023
 12:04 PM
 account, limit and balance
*/
#include <stdio.h>
int main(void) {
	int account = 0;
	int i = 0;
	double limit = 0;
	double balance = 0;
	double newLimit = 0;
	
	for (i = 1; i <= 3; ++i) {
		
		printf("Enter account, limit and Balance ");
		scanf("%d%lf%lf", &account, &limit, &balance);
		
		newLimit = limit / 2.0;
		printf("New credit limit for account %d is %f\n", account, newLimit);
		
		if (balance > newLimit)
			printf("Limit exceeded for account %d\n\n", account);
	}
}
