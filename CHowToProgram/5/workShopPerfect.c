//TheBitRiddler
//10-16-2022
//7:33am
//Perfect number
#include <stdio.h>

int perfectNumber(int);

int main(void){
	puts("Enter a number to find the perfect numbers in it:Better try 1000 or above to test your PC");
	int x = 0;
	scanf("%d",&x);
	perfectNumber(x);
}

int perfectNumber(int x){
	int p = 0;//The perfect number
	for(int i = 1;i <= x;i++){
		int ft = 0;
		for(int j = 1;j <= i;j++){
			if((i % j) == 0 && j < i){
				ft += j;
			}
		}
		if(ft == i){
			for(int j = 1;j <= i;j++){
				if((i % j) == 0 && j < i){
					printf("The Factor:%d\n",j);
				}
			}
			printf("The perfect number:%d\n",ft);
		}
	}
}
