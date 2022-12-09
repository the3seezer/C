//theBitRiddler
//11-12-2022
//4:33pm
//Testing Math Library Functions
#include <stdio.h>
#include <math.h>
int main(void){
	puts("\nsqrt == Square root");
	printf("sqrt(900.0) %lf\n",sqrt(900.0));
	printf("sqrt(9.0) %lf\n",sqrt(9.0));
	puts("\ncbrt == cube root");
	printf("cbrt(27.0) %lf\n",cbrt(27.0));
	printf("cbrt(-8.0) %lf\n",cbrt(-8.0));
	puts("\nexp == Exponent");
	printf("exp(1.0) %lf\n",exp(1.0));
	printf("exp(2.0) %lf\n",exp(2.0));
	puts("\nlog");
	printf("log(2.718282) %lf\n",log(2.718282));
	printf("log(7.389056) %lf\n",log(7.389056));
	puts("\nlog10");
	printf("log10(1.0) %lf\n",log10(1.0));
	printf("log10(10.0) %lf\n",log10(10.0));
	printf("log10(100.0) %lf\n",log10(100.0));
	puts("\nfabs absolute value of x");
	printf("fabs(13.5) %lf\n",fabs(13.5));
	printf("fabs(0.0) %lf\n",fabs(0.0));
	printf("fabs(-13.5) %lf\n",fabs(-13.5));
	puts("\nCeil");
	printf("ceil(9.2) %lf\n",ceil(9.2));
	printf("ceil(-9.8) %lf\n",ceil(-9.8));
	puts("\nfloor");
	printf("floor(9.2) %lf\n",floor(9.2));
	printf("floor(-9.8) %lf\n",floor(-9.8));
	puts("\npow");
	printf("pow(2, 7) %lf\n",pow(2, 7));
	printf("pow(9, .5) %lf\n",pow(9, .5));
	puts("\nfmod == remainder");
	printf("fmod(13.657, 2.333) %lf\n",fmod(13.657, 2.333));
	puts("\nsin cos tan");
	printf("sin(0.0) %lf\n",sin(0.0));
	printf("cos(0.0) %lf\n",cos(0.0));
	printf("tan(0.0) %lf\n",tan(0.0));
}
