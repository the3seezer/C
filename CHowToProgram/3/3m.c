#include <stdio.h>
int main(){
	//3.2
	int x = 0;
	printf_s("%d\n",++x);
	x = 0;
	x++;
	printf_s("%d\n",x);
	x = 0;
	printf_s("%d\n",x = x + 1);
	x = 0;
	printf_s("%d\n",x = 1 + x);
	//3.3
	//(e) and (f)
	float p = 123.4567;
	printf("%.2f\n",p);
	p = 3.14159;
	printf("%.3f\n",p);
	//(a) and (b)
	int q = 4;
	printf_s("%d\n",q*=2);
	q = 4;
	printf_s("%d\n",q = q * 2);
	//remainders(d)
	printf_s("%s\n","input two digits");
	int a = 0; int b = 0;
	scanf_s("%d%d",&a,&b);
	int quo = a % b;//remainder
	printf_s("The remainders:\n%d\n",quo);
	printf_s("%d\n",a - ((a / b) * b));
	
}
