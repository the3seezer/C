#include <stdio.h>
int main(){
	float sales = 0;
	
	printf_s("%s","Enter sales in dollars (-1 to end): ");
	scanf("%f",&sales);
	while(sales != -1){
		printf("Salary is: $%.2f\n\n",(0.09 * sales) + 200);
		printf_s("%s","Enter sales in dollars (-1 to end): ");
		scanf("%f",&sales);
	}
}
