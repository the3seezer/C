/*
 theBitRiddler
 3/30/2023
 12:39 PM
 Accounting
*/
#include <stdio.h>
#include <math.h>

int main(void) {
	int rate = 0;
	int year = 0;
	double amount = 0;
	double principal = 1000.0;
	
	for (rate = 5; rate <= 10; ++rate) {
		
		printf("Interest rate %f\n", rate / 100.0);
		printf("%s%21s\n", "Year", "Amount on deposit");
		
		for (year = 1; year <= 10; ++year) {
			amount = principal * pow(1 + (rate / 100.0), year);
			
			printf("%4d%21.2f\n", year, amount);
		}
		
		printf("%s", "\n");
	}
}
