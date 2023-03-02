// theBitRiddler
// 12/22/2022
// 10:18 PM
// Random theory
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	/* if x + rand() % y; then z = x + y - 1
	   provided: x is the margin (lower margin)
	   			 y is the size
				 z is the other margin(upper margin) */
	srand(time(NULL));
	for (int i = 0; i < 500; ++i) {
		if (i % 20 == 0) {
			puts("");
		}
		printf("%4d ", 10 + rand() % 91);
	}	
}
