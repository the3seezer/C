/* 
	theBitRiddler
	3/5/2023
	7:43 PM
	Circle diameter, circumference, Area
*/
#include <stdio.h>
int main(void) {
	int radius = 0;
	printf("Enter a radius; ");
	scanf("%d", &radius);
	
	printf("Diameter is %d\n", 2 * radius);
	printf("Circumference is %f\n", 2 * 3.14139 * radius);
	printf("Area is %f\n", 3.14139 * radius * radius);
}
