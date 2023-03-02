#include <stdio.h>
int main(){
	//3.2
	int x = 0;
	printf("%d\n",++x);
	x = 0;
	x++;
	printf("%d\n",x);
	x = 0;
	printf("%d\n",x = x + 1);
	x = 0;
	printf("%d\n",x = 1 + x);
	//3.3
	//(a) and (b)
	int q = 4;
	printf("%d\n",q*=2);
	q = 4;
	printf("%d\n",q = q * 2);
	//remainders(d)
	printf("%s\n","input two numbers");
	int quotient = 0;
	int divisor = 0;
	scanf("%d%d",&quotient,&divisor);
	quotient = quotient % divisor;
	printf("remainder : %d\n",quotient);
	
	printf("%s\n","input two numbers");
	quotient = 0;
    divisor = 0;
	scanf("%d%d",&quotient,&divisor);
	quotient %= divisor;
	printf("remainder: %d\n",quotient);
		
	//(e) and (f)
	float p = 123.4567;
	printf("%.2f\n",p);
	p = 3.14159;
	printf("%.3f\n",p);
	

	
}
