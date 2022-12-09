//theBitRiddler
//10-9-2022
//10:31pm
//the minimum number
#include <stdio.h>

float smallest(float, float, float);

int main(void){
	float a = 0;
	float b = 0;
	float c = 0;
	puts("Enter three numbers to find the smallest\n");
	scanf("%f%f%f",&a,&b,&c);
	printf("Smallest:%f\n",smallest(a,b,c));
}

float smallest(float a,float b,float c){
	float x = a;
	if(b < x){
		x = b;
	}
	else if(c < x){
		x = c;
	}
	return x;
}
