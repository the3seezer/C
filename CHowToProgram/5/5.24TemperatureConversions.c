//theBitRiddler
//10-8-2022
//4:03pm
//Temperature Conversion
#include <stdio.h>

double toCelcius(int);
double toFahrenheit(int);

int main(void){
	printf("%10s%30s\n","Celcius","Fahrenheit");
	for(int i = 0;i <= 100;i++){
		printf("%10d%30f\n",i,toFahrenheit(i));
	}
	puts("\n\n");
	printf("%10s%30s\n","Fahrenheit","Celcius");
	for(int i = 32;i <= 212;i++){
		printf("%10d%30lf\n",i,toCelcius(i));
	}
}

double toCelcius(int x){
	return  (double) 5/9 * (x - 32);
}

double toFahrenheit(int x){
	return (double) 9/5 * x + 32;
}
