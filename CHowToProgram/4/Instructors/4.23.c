/*
 theBitRiddler
 02/04/2023
 14:03
 year, rate, dollars, cents, in integers
*/
#include <stdio.h>
#include <math.h>

int main(void) {
	int year = 0;
	int amount = 0; /* in pennies */
	int dollars = 0;
	int cents = 0;
	int principal = 100000; /* in pennies */
	double rate = .05;
	
	printf("%s%21s\n", "Year", "Amount on deposit");
	
	for (year = 1; year <= 10; ++year) {
		
		amount = principal * pow(1.0 + rate, year);
		
		cents = amount % 100;
		
		dollars = amount / 100;
		
		printf("%4d%17d.", year, dollars);
		
		if (cents < 10) {
			printf("0%d\n", cents);
		}
		else {
			printf("%d\n", cents);
		}
	}
}
