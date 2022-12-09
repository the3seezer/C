#include <stdio.h>
int main(){
	float t_gallons = 0;
	float t_miles = 0;
	int gallons = 0;
	float miles = 0;
	
	printf("%s","Enter the gallons used (-1 to end): ");
	scanf("%d",&gallons);
	while(gallons != -1){
		t_gallons += gallons;
		
		printf("%s","Enter the miles driven: ");
		scanf("%f",&miles);
		t_miles += miles;
		float m_g =  miles / gallons;
		printf("The miles/gallon for this tank was %f \n",m_g);
		
		puts(" ");
		printf("%s","Enter the gallons used (-1 to end): ");
		scanf("%d",&gallons);
	}
	puts(" ");
	printf("The Overall average miles / gallon %f\n",t_miles / t_gallons);
}
