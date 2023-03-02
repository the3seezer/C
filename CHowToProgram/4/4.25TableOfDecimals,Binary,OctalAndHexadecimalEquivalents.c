#include <stdio.h>
#include <math.h>
int main(void){
	printf("%21s%21s%21s%21s\n","Decimals","Binary","Octal","Hexadecimal");
	for(int i = 1;i <= 256;i++){
		int n = i;
		//int n = 0;
		int ten_p = 0;//determines the position of the individual remainder
		int rem = 0;//remainder the bits
		//puts("Enter a number");
		//scanf("%d",&n);
		while(n){
			if(n % 2){
				n - 1;
				n /= 2;
				rem += 1 * pow(10,ten_p); 
				ten_p++;
			}
			if(!(n % 2)){
				n /= 2;
				rem += 0;
				ten_p++;
			}
		}
		printf("%21d%21d%21o%21x\n",i,rem,i,i);
	}
}
