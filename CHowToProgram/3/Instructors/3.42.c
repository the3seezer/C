/*
 theBitRiddler
 3/26/2023
 2:04 PM
 The Diameter, circumference and Area
*/
#include <stdio.h>
int main(void) {
	float radius = 0;
	float pi = 3.14159;
	
	printf("%s", "Enter the radius ");
	scanf("%f", &radius);
	
	printf("The diameter is %.2f\n", radius * 2);
	
	printf("The circumference is %.2f\n", 2 * pi * radius);
	
	printf("The Area is %.2f\n", pi * radius * radius);
}
