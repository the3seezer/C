/* 
 theBitRiddler
 12/04/2023
 11:03
 the pie
*/
#include <stdio.h>
int main(void) {
	long double pi = 0.0;
	long double num = 4.0; /* numerator */
	long double denom = 1.0; /* denominator */
	long int loop = 0;
	long int accuracy = 0;
	
	accuracy = 400; /* 400000 */
	
	printf("Accuracy set at %ld\n", accuracy);
	printf("%s\t\t  %s", "Term", "pi\n");
	
	for (loop = 1; loop <= accuracy; ++loop) {
		
		if (loop % 2) {
			pi += num / denom;
		}
		else {
			pi -= num / denom;
		}
		
		denom += 2.0;
		
		printf("%ld\t\t  %Lf\n", loop, pi);
	}
	
}
