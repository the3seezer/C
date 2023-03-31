/* 
theBitRiddler
3/5/2023
3:09 PM
sum, product, difference, quotient, remainder
*/
#include <stdio.h>
int main(void) {
	int x = 0;
	int y = 0;
	puts("enter the value of x and y respectively");

	scanf("%d%d", &x, &y);
	
	printf("The sum is %d\n", x + y);
	printf("The product is %d\n", x * y);
	printf("The difference is %d\n", x - y);
	printf("The quotient is %d\n", x / y);
	printf("The remainder is %d\n", x % y);
}

