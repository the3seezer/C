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
	if(a < b){
		if(a < c){
			printf("Smallest is %d",a);
		}
	}
	if(b < a){
		if(b < c){
			printf("Smallest is %d",b);
		}
	}
	if(c < b){
		if(c < a){
			printf("Smallest is %d",c);
		}
	}
	printf("\n");
	//Largest
	if(a > b){
		if(a > c){
			printf("Largest is %d",a);
		}
	}
	if(b > a){
		if(b > c){
			printf("Largest is %d",b);
		}
	}
	if(c > b){
		if(c > a){
			printf("Largest is %d",c);
		}
	}
}
