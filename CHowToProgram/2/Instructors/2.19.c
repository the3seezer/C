/* theBitRiddler
3/5/2023
7:29 PM
sum, average, product, smallest, largest 
*/
#include <stdio.h>
int main(void) {
	int a,b,c = 0;
	printf("%s", "input three integers ");
	scanf("%d%d%d", &a, &b, &c);
	
	printf("sum is %d\n", a + b + c);
	printf("average is %d\n", (a + b + c) / 3);
	printf("product is %d\n", a * b * c);
	
	int smallest = a;
	if (b < smallest) {
		smallest = b;
	}
	if (c < smallest) {
		smallest = c;
	}
	printf("smallest is %d\n", smallest);
	
	int largest = a;
	if (b > largest) {
		largest = b;
	}
	if (c > largest) {
		largest = c;
	}
	printf("largest is %d\n", largest);
} /* end main */
