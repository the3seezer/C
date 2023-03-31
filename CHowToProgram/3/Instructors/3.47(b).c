<<<<<<< HEAD
/* 
 theBitRiddler
 3/27/2023
 12:34 PM
 The mathematical constant e
*/
#include <stdio.h>
int main(void) {
	int n = 0;
	int fact = 1;
	int accuracy = 10;
	double e = 0;
	
	while (n <= accuracy) {
		
		if (n == 0) {
			fact *= 1;
		}
		else {
			fact *= n;
		}
		
		e += 1.0 / fact;
		
		++n;
	}
	
	printf("e is %f\n", e);
}
=======
/* 
 theBitRiddler
 3/27/2023
 12:34 PM
 The mathematical constant e
*/
#include <stdio.h>
int main(void) {
	int n = 0;
	int fact = 1;
	int accuracy = 10;
	double e = 0;
	
	while (n <= accuracy) {
		
		if (n == 0) {
			fact *= 1;
		}
		else {
			fact *= n;
		}
		
		e += 1.0 / fact;
		
		++n;
	}
	
	printf("e is %f\n", e);
}
>>>>>>> 78d99489bc9fd084c8e4baa79a5431b5829ff12e
