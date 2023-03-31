/*
 theBitRiddler
 3/30/2023
 10:18 AM
 Error correcting
*/
#include <stdio.h>
int main(void) {
	int counter = 2;
	
	do {
		printf("%d\n", counter);
		counter += 2;
	}
	while (counter <= 100);
}
