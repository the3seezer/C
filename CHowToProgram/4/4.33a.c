#include <stdio.h>
int main(void){
	printf("%21s%21s\n","Arabic Numerals","Roman Numerals");
	for(int i = 1;i <= 10;i++){
		printf("%21d",i);
		for(int j = 1;j <= i;++j){
			if(i >= 10){
				printf("%21s","X");
				j += 10;
			}
			if(i >= 9){
				printf("%21s","IX");
				j += 9;
			}
			else if(i >= 5){
				printf("%21s","V");
				j += 5;
			}
			else if(i >= 4){
				printf("%21s","IV");
				j += 4;
			}
			else if(i >= 1){
				printf("%21s","I");
			}
			
		}
		puts("");
	}
}
