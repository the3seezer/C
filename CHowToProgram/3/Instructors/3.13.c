/* 
 theBitRiddler
 3/6/2023
 12:47 PM
 Squares and their total
*/
#include <stdio.h>
int main(void) {
	int number = 1,total,y = 0;
	while (number <= 10) {
		y = number * number;
		printf("%d\n", y);
		total += y;
		number++;
	}
	printf("The total is %d\n", total);
}
