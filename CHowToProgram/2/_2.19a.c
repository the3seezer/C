#include <stdio.h>
int main(){
	int a = 0;
	int b = 0;
	int c = 0;
	printf("%s","Enter three difference integers: \n");
	scanf("%d%d%d",&a,&b,&c);
	printf("Sum is %d\n",a + b + c);
	printf("Average is %d\n",(a + b + c) / 3);
	printf("Product is %d\n",a * b * c);
	//Smallest
	if((a < b) < c || a < (b == c) || (a == b) < c || (a == c) < b){
		printf("Smallest is %d",a);
	}
	if((b < a) < c || b < (a == c) || (b == a) < c || (b == c) < a){
		printf("Smallest is %d",b);
	}
	if((c < a) < b || c < (a == b) || (c == a) < b || (c == b) < a){
		printf("Smallest is %d",c);
	}
	//Largest
	if((a > b) > c || a > (b == c) || (a == b) > c || (a == c) > b){
		printf("Largest is %d",a);
	}
	if((b > a) > c || b > (a == c) || (b == a) > c || (b == c) > a){
		printf("Largest is %d",b);
	}
	if((c > a) > b || c > (a == b) || (c == a) > b || (c == b) > a){
		printf("Largest is %d",c);
	}			
}
