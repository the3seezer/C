#include <stdio.h>
int main(){
	puts("Target Heart-Rate Calculator: ");
	int age = 0;
	printf("%s","Enter your age\n");
	scanf("%d",&age);
	//maximum heart rate
	int m_rate = 220 - age;
	//Target heart rate
	//minimum heart rate
	int min_t = (50 * m_rate) / 100;
	//maximum heart rate
	int max_t = (85 * m_rate) / 100;
	printf("Your max and min heart range is %d and %d",min_t,max_t);
}
