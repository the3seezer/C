/* 
 theBitRiddler
 2/5/2023
 9:30 PM
 five integers find smallest and largest
 */
#include <stdio.h>
int main(void) {
	int smallest,largest,int1,int2,int3 = 0;
	int temp = 0;
	printf("Enter five integers ");
	scanf("%d%d%d%d%d", &smallest, &largest, &int1, &int2, &int3);
	
	if (smallest > largest) {
		temp = smallest;
		smallest = largest;
		largest = temp;
	} 
	
	if (smallest > int1) {
		smallest = int1;
	}
	if (largest < int1) {
		largest = int1;
	}
	
	if (smallest > int2) {
		smallest = int2;
	}
	if (largest < int2) {
		largest = int2;
	}
	
	if (smallest > int3) {
		smallest = int3;
	}
	if (largest < int3) {
		largest = int3;
	}
	
	printf("The smallest is %d\nThe largest is %d\n", smallest, largest);
} /* end main */
