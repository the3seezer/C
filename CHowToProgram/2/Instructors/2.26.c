<<<<<<< HEAD
/* 
 theBitRiddler
 3/6/2023
 11/11 AM
 multiple check
*/
#include <stdio.h>
int main(void) {
	int integer1, integer2 = 0;
	printf("Enter two integers ");
	scanf("%d%d", &integer1, &integer2);
	if (integer1 % integer2 == 0) {
		printf("%d is a multiple of %d\n", integer1, integer2);
		printf("By a factor of %d\n", integer1 / integer2);
	}
	if (integer1 % integer2) {
		printf("%d is not a multiple of %d\n", integer1, integer2);
	}
	return 0;
}
=======
/* 
 theBitRiddler
 3/6/2023
 11/11 AM
 multiple check
*/
#include <stdio.h>
int main(void) {
	int integer1, integer2 = 0;
	printf("Enter two integers ");
	scanf("%d%d", &integer1, &integer2);
	if (integer1 % integer2 == 0) {
		printf("%d is a multiple of %d\n", integer1, integer2);
		printf("By a factor of %d\n", integer1 / integer2);
	}
	if (integer1 % integer2) {
		printf("%d is not a multiple of %d\n", integer1, integer2);
	}
	return 0;
}
>>>>>>> 78d99489bc9fd084c8e4baa79a5431b5829ff12e
