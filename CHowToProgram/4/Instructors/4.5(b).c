/*
 theBitRiddler
 3/30/2023
 9:04 AM
 error correcting
*/
#include <stdio.h>
int main(void) {
	int value = 0;
	printf("Enter a value to dectect weather it's even or odd ");
	scanf("%d", &value);
	
	switch(value % 2) {
		case 0:
			printf("%s", "value is even\n");
			break;
		case 1:
			printf("%s", "value is odd\n");
			break;
	}
}
