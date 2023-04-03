/*
 theBitRiddler
 02/04/2023
 11:48
 Total retail value
*/
#include <stdio.h>
int main(void) {
	int product = 0; /* current product */
	int quantity = 0; /* current product quantity */
	double total = 0; /* total products value */
	
	printf("%s", "Enter pairs of item number and quantities\n");
	printf("%s", "Enter -1 for the item number to end input\n");
	scanf("%d", &product);
	
	while (product != -1) {
		scanf("%d", &quantity);
		
		switch (product) {
			case 1:
				total += quantity * 2.98;
				break;
			case 2:
				total += quantity * 4.50;
				break;
			case 3:
				total += quantity * 9.98;
				break;
			case 4:
				total += quantity * 4.49;
				break;
			case 5:
				total += quantity * 6.87;
				break;
			default:
				printf("Invalid product code %d\n", product);
				printf("            quantity %d\n", quantity);
				break;
		}
		
		scanf("%d", &product);
	}
	
	printf("The total retail value is %.2f\n", total);
}
