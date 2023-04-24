/* 
 theBitRiddler
 11:35 PM
 4/24/2023
 Pythogorean Triples
*/
#include <stdio.h>
int main(void) {
	int count = 0;
	long int side1 = 0;
	long int side2 = 0;
	long int hypotenuse = 0;
	long int hyptSquared = 0;
	long int sidesSquared = 0;
	
	for (side1 = 1; side1 <= 500; ++side1) {
		
		for (side2 = 1; side2 <= 500; ++side2) {
			
			for (hypotenuse = 1; hypotenuse <= 500; ++hypotenuse) {
				
				hyptSquared = hypotenuse * hypotenuse;
				sidesSquared = side1 * side1 + side2 * side2;
				
				if (hyptSquared == sidesSquared) {
					
					printf("%ld %ld %ld \n", side1, side2, hypotenuse);
					++count;
				}
			}
		}
	}
	
	printf("A total of %d triples were found\n", count);
}
