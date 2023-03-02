#include <stdio.h>
int main(void){
	float pi = 3.14159;
	double r = 0;
	printf_s("%s","Input a radius: \n");
	scanf("%lf",&r);//l is required in convergence specification;scanf
	printf("The diameter: %.2f\n", 2 * r);
	printf("The circumference: %.2f\n", 2 * pi * r);
	//float area = (float) pi * r * r;printf("%f\n",pi);printf("%d\n",r);//printf("%d\n",area);
	printf("The area: %f\n",pi * r * r);
}
