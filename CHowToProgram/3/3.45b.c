#include <stdio.h>
int main(void){
	float e = 1;
	int n = 0;
	int num = 1;
	printf_s("%s\n","Please enter the final coeficcient: ");
	sscanf_s("%d",&n);
	while(num <= n){
		float num2 = num;
		float factorial = 1;
		while(num2 >= 1){
		    factorial *= num2;
			num2--;
		}
		e = e + (1 / factorial);
		num++;
	}
	printf("The value of e : %.9f",e);
}
