#include <stdio.h>
int main(){
	float PI = 3.14159;
	puts("Enter the value of the radius: ");
	float r = 0;
	scanf("%f",&r);
	printf("diameter: %f\n",2 * r);
	printf("circumference: %f\n",2 * PI * r);
	printf("area: %f",PI * r * r);
	
} 
