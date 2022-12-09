#include <stdio.h>
#include <math.h>
int main(void){
	int p = 100000;//pennies
	int r = 5;
	printf("%-21s%-21s\n","Year","Amount on deposites in Dollars");
	for(int n = 1;n <= 10;n++){
		int a = p * pow(1 + (float)r / 100,n);
		printf("%d\n",a);
		//double amp = pow(1 + r,n);
		//printf("power %lf\n",amp);
		printf("%-21d %d.%d\n",n,a / 100,a % 100);
	}
}
