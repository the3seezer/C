/* 
 theBitRiddler
 3/22/2023
 2:22 PM 
 Sales and Wages
*/
#include <stdio.h>
int main(void) {
	double sales = 0;
	double wages = 0;
	
	printf("%s", "Enter amount of sales (-1 to end): ");
	scanf("%lf", &sales);
	
	while (sales != -1.0) {
		wages = 200.0 + 0.09 * sales;
		printf("Salary is : %.2f\n\n", wages);
		
		printf("%s", "Enter amount of sales: -1 to end \n");
		scanf("%lf", &sales);
	}
}

