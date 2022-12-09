#include <stdio.h>
int main(void){
	float total_retail_week = 0; 
	for(int week = 1;week <= 7;week++){
		if(week == 1){
			puts("Monday\n");
		}
		if(week == 2){
			puts("Tuesday\n");
		}
		if(week == 3){
			puts("Wednesday\n");
		}
		if(week == 4){
			puts("Thursday\n");
		}
		if(week == 5){
			puts("Friday\n");
		}
		if(week == 6){
			puts("Saturday\n");
		}
		if(week == 7){
			puts("Sunday\n");
		}
		//products
		int one = 0;
		int two = 0;
		int three = 0;
		int four = 0;
		int five = 0;
	
		float quantinty_one = 0;
		float quantinty_two = 0;
		float quantinty_three = 0;
		float quantinty_four = 0;
		float quantinty_five = 0;
	
		float retail_price_one = 0;
		float retail_price_two = 0;
		float retail_price_three = 0;
		float retail_price_four = 0;
		float retail_price_five = 0;
	
		int product_number = 0;
		printf("%s","Enter product number:-1 to end\n");
		scanf("%d",&product_number);
		while(product_number != -1){
			switch(product_number){
				case 1:
					one++;
					retail_price_one = 2.98;
				break;
				case 2:
					two++;
					retail_price_two = 4.50;
				break;
				case 3:
					three++;
					retail_price_three = 9.98;
				break;
				case 4:
					four++;
					retail_price_four = 4.49;
				break;
				case 5:
					five++;
					retail_price_five = 6.87;
				break;
				default:
					printf("%s","Incorrect number entered. ");
					puts("Enter a new number");
				break;
			}
			printf("%s","Enter product number:-1 to end\n");
			scanf("%d",&product_number);
		}
		
		if(week == 1){
			puts("Monday\n");
		}
		if(week == 2){
			puts("Tuesday\n");
		}
		if(week == 3){
			puts("Wednesday\n");
		}
		if(week == 4){
			puts("Thursday\n");
		}
		if(week == 5){
			puts("Friday\n");
		}
		if(week == 6){
			puts("Saturday\n");
		}
		if(week == 7){
			puts("Sunday\n");
		}
		printf("%-21s%-21s","Product number","Quantity sold for one day\n");
		printf("%-21d%-21d\n",1,one);
		printf("%-21d%-21d\n",2,two);
		printf("%-21d%-21d\n",3,three);
		printf("%-21d%-21d\n",4,four);
		printf("%-21d%-21d\n",5,five);
		float total_retail = one * retail_price_one + two * retail_price_two + three * retail_price_three + four * retail_price_four + five * retail_price_five;
		printf("The total retail value:$%.2f\n\n\n",total_retail);
		
		total_retail_week += total_retail;
	}
	printf("The total week retail value:$%.2f",total_retail_week);
}
