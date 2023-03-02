#include <stdio.h>
int main(void){
    int account1 = 0;
    int credit1 = 0;
    int balance1 = 0;

    int account2 = 0;
    int credit2 = 0;
    int balance2 = 0;

    int account3 = 0;
    int credit3 = 0;
    int balance3 = 0;
    for(int i = 0;i <= 3;i++){
        if(i == 1){
            printf("%s","Input the first user account number\n");
            scanf("%d",&account1);
            printf("%s","Input the credit limit\n");
            scanf("%d",&credit1);
            balance1 = credit1 / 2;
        }
        if(i == 2){
            printf("%s","Input the second user account number\n");
            scanf("%d",&account2);
            printf("%s","Input the credit limit\n");
            scanf("%d",&credit2);
            balance2 = credit2 / 2;
        }
        if(i == 3){
            printf("%s","Input the third user account number\n");
            scanf("%d",&account3);
            printf("%s","Input the credit limit\n");
            scanf("%d",&credit3);
            balance3 = credit3 / 2;
        }
    }
    printf("Account1 %d has %d credit limit and %d balance:\n",account1,credit1,balance1);
    printf("Account2 %d has %d credit limit and %d balance:\n",account2,credit2,balance2);
    printf("Account3 %d has %d credit limit and %d balance:\n",account3,credit3,balance3);
    if(balance1 > balance2 && balance1 > balance3){
    	printf("First Account balance accedes");
	}
	if(balance2 > balance1 && balance2 > balance3){
    	printf("Second Account balance accedes");
	}
	if(balance3 > balance2 && balance3 > balance1){
    	printf("Third Account balance accedes");
	}
}
