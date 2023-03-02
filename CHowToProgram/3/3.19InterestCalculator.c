#include <stdio.h>
int main(void){
	float principal = 0;
	float rate = 0;
	int days = 0;
	printf_s("%s","Enter loan principal (-1 to end): ");
	scanf("%f",&principal);
	while(principal != -1){
		printf_s("%s","Enter interest rate: ");
		scanf("%f",&rate);
		printf_s("%s","Enter term of the loan in days: ");
		scanf("%d",&days);
		printf("The interest charge is $%.2f\n\n",principal * rate * days / 365);
		printf_s("%s","Enter loan principal (-1 to end): ");
		scanf("%f",&principal);
	}
}
