<<<<<<< HEAD
/* 
 theBitRiddler
 3/27/2023
 1:43 PM
 The value of e^x
*/
#include <stdio.h>
int main(void) {
	int n = 0;
	int accuracy = 15;
	int x = 3;
	int times = 0;
	int count = 0;
	double e = 1.0;
	double exp = 0.0;
	double fact = 1.0;
	
	while (n <= accuracy) {
		count = n;
		
		if (n == 0) {
			fact *= 1.0;
		}
		else {
			fact *= n;
		}
		
		/* calculate x raised to n */
		while (times < count) {
			
			if (times == 0) {
				exp = 1.0;
				exp *= x;
			}
			else {
				exp *= x;
			}
			
			++times;
		}
		
		e += exp / fact;
		++n;
	}
	
	printf("e raised to the power %d is %f\n", x, e);
}
=======
/* 
 theBitRiddler
 3/27/2023
 1:43 PM
 The value of e^x
*/
#include <stdio.h>
int main(void) {
	int n = 0;
	int accuracy = 15;
	int x = 3;
	int times = 0;
	int count = 0;
	double e = 1.0;
	double exp = 0.0;
	double fact = 1.0;
	
	while (n <= accuracy) {
		count = n;
		
		if (n == 0) {
			fact *= 1.0;
		}
		else {
			fact *= n;
		}
		
		/* calculate x raised to n */
		while (times < count) {
			
			if (times == 0) {
				exp = 1.0;
				exp *= x;
			}
			else {
				exp *= x;
			}
			
			++times;
		}
		
		e += exp / fact;
		++n;
	}
	
	printf("e raised to the power %d is %f\n", x, e);
}
>>>>>>> 78d99489bc9fd084c8e4baa79a5431b5829ff12e
