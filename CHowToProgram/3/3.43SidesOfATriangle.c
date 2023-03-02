#include <stdio.h>
int main(void){//The Triangle inequality Theorem
	int a = 0;
	int b = 0;
	int c = 0;
	printf_s("%s","Enter three values: \n");
	scanf_s("%d%d%d",&a,&b,&c);
	if(a + b > c && a + c > b && b + c > a){
		printf_s("The sides are a triangle: \n");
	}
}
