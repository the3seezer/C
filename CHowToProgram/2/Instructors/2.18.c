/* 
theBitRiddler
3/5/2023
3:49 PM
*/
#include <stdio.h>
int main(void) {
	int x,y = 0;
	printf("%s ", "Enter two numbers");
	scanf("%d%d", &x, &y);
	
	if (x > y) {
		printf("%d is larger\n", x);
	}
	if (x < y) {
		printf("%d is larger\n", y);
	}
	if (x == y) {
		printf("they are both equal\n");
	}
}