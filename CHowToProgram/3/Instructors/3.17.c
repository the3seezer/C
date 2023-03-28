/* 
 theBitRiddler
 3/6/2023
 1:41 PM
 Gallons per miles
*/
#include <stdio.h>
int main(void) {
	double gallons = 0;
	double miles = 0;
	double total_gallons = 0;
	double total_miles = 0;
	printf("%s", "Enter gallons used (-1 to end) ");
	scanf("%lf", &gallons);
	while (gallons != -1) {
		total_gallons += gallons; 
		
		printf("%s", "Enter miles traveled ");
		scanf("%lf", &miles);
		total_miles += miles;
		printf("The miles / gallons for this is %f\n\n", miles / gallons);
		
		
		printf("%s", "Enter gallons used (-1 to end) ");
		scanf("%lf", &gallons);
	}
	printf("The overall average miles / gallons is %f", total_miles / total_gallons);
}
