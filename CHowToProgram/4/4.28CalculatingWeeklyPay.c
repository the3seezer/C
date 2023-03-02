#include <stdio.h>
int main(void){
	int code = 0;
	int total_1 = 0;
	double total_2 = 0;
	double total_3 = 0;
	int total_4 = 0;
	printf("%s","Enter the code or -1 to End\n");
	scanf("%d",&code);
	while(code != -1){
		switch(code){
			case 1:
				puts("A Manager");
				puts("Enter number of weeks");
				int weeks = 0;
				scanf("%d",&weeks);
				int managers = 2000;
				total_1 = total_1 + weeks * managers;
				printf("Your total amount: %d",total_1);
				break;
			case 2:
				puts("Hourly Worker");
				int hourly = 5;
				double over_time = 7.5;
				puts("Enter a number of hours");
				int hours = 0;
				scanf("%d",&hours);
				if(hours > 40){
					total_2 = (hours - 40) * over_time + 40 * hourly;
				}
				else{
					total_2 = (double) hours * hourly;
				}
				printf("Your total amount: %f",total_2);
				break;
			case 3:
				puts("commission");
				int commission = 250;
				puts("Enter a number of weeks");
				weeks = 0;
				scanf("%d",&weeks);
				puts("Enter an amount of weekly sales");
				double weekly_sales = 0;
				double total_w_sales = 0;
				for(int i = 1;i <= weeks;i++){
					printf("Week %d\n",i);
					scanf("%lf",&weekly_sales);
					total_w_sales = total_w_sales + weekly_sales;
				}
				double gross_weekly_sales = 5.7 / 100;
				total_3 = commission * weeks + total_w_sales * gross_weekly_sales;
				printf("Your total amount: %f",total_3);
				break;
			case 4:
				puts("pieceworker");
				puts("Enter a number of items");
				int items = 0;
				scanf("%d",&items);
				int pieceworker = 50;
				total_4 = items * pieceworker;
				printf("Your total amount: %d",total_4);
				break;
			case '\n':
			case '\t':
			case ' ':
				break;
			default:
				puts("I\'m sorry you entered a wrong character");
				break;
		}
	printf("%s","\nEnter your code or -1 to End\n");
	scanf("%d",&code);	
	}
}
