//theBitRiddler
//10-9-2022
//11:03pm
//The Perfect Number
#include <stdio.h>

int perfectNumber(int);

int main(void){
	puts("Enter a number to find the perfect numbers in it:Better try 1000 or above to test your PC");
	int x = 0;
	scanf("%d",&x);
	for(int i = 1;i <= x;i++){//looking for a perfect number in i
		if(perfectNumber(i) != 1 && perfectNumber(i) != 0){
			printf("The perfect number is %d\n",perfectNumber(i));
		}
	}
}

int perfectNumber(int x){//looking for factors in the i series above
	int ft = 0;//factor total
	for(int j = x;j >= 1;j--){//looking for factors for each  number in j and to find a perfect factor
		if((x % j) == 0 && j < x){
				ft += j;
		}
	}
	if(ft == x){
		for(int j = x;j >= 1;j--){//displaying each factor
			if((x % j) == 0 && j < x){
					printf("The Factor:%d\n",j);
			}
		}	
		return ft;
	}else if(ft < x ||ft > x){
		return 1;
	}
}
