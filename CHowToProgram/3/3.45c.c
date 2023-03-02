#include <stdio.h>
int main(void){
	float e = 1;
	int n = 0;
	int x = 0;
	int num = 1;
	printf("%s","Enter the the times of incrimation \nand the value of x: \n");
	scanf("%d%d",&n,&x);
	while(num <= n){
		float num2 = num;
		float factorial = 1;
		while(num2 >= 1){
			factorial *= num2;
			num2--;
		}
		num <= n ? ( n > 1 ? x *= x : x ) :  x ;
		e = e + ( x / factorial);
		num++;
	}
	printf("%.10f",e);
}
