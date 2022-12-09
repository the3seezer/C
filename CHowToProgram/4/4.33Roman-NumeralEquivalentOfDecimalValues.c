#include <stdio.h>
int main(void){
	int n;
	printf("%-21s%-21s\n","Arabic Numerals","Roman Numerals");
	for(int i = 1;i <= 100;i++){
		n = i;
		printf("%-21d",i);
		while(n != 0){
			if(n >= 1000){
				printf("%s","M");
				n -= 1000;
			}
			else if(n >= 900){
				printf("%s","CM");
				n -= 900;
			}
			else if(n >= 500){
				printf("%s","L");
				n -= 500;
			}
			else if(n >= 400){
				printf("%s","CL");
			}
			else if(n >= 100){
				printf("%s","C");
				n -= 100;
			}
			else if(n >= 90){
				printf("%s","XC");
				n -= 90;
			}
			else if(n >= 50){
				printf("%s","L");
				n -= 50;
			}
			else if(n >= 40){
				printf("%s","XL");
				n -= 40;
			}
			else if(n >= 10){
				printf("%s","X");
				n -= 10;
			}
			else if(n >= 9){
				printf("%s","IX");
				n -= 9;
			}
			else if(n >= 5){
				printf("%s","V");
				n -= 5;
			}
			else if(n >= 4){
				printf("%s","IV");
				n -= 4;
			}
			else if(n >= 1){
				printf("%s","I");
				n--;
			}
		}
		puts("");
	}
}
