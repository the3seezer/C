#include <stdio.h>
int main(){
	int account = 0;
	float balance = 0;
	float charges = 0;
	float credits = 0;
	float credit_limits = 0;
	//inputs
	printf("%s","Enter account number (-1 to end): ");
	scanf("%d",&account);
	while(account != -1){
		printf("%s","Enter beginning balance: ");
		scanf("%f",&balance);//printf("%d",balance);
		printf("%s","Enter total charges: ");
		scanf("%f",&charges);
		printf("%s","Enter total credits: ");
		scanf("%f",&credits);
		printf("%s","Enter credit limit: ");
		scanf("%f",&credit_limits);
		//outputs
		double new_balance = balance + charges - credits;
		if(new_balance > credit_limits){
			printf("Account:	 %d\n",account);
			printf("Credit Limit:	%.2f\n",credit_limits);
			printf("Balance:	 %.2f\n",new_balance);
			puts("Credit Limit Exceeded\n");
		}//end if
		else{
			puts(" ");
		}
	printf("%s","Enter account number (-1 to end): ");
	scanf("%d",&account);
	}
}
