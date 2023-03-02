//theBitRiddler
//9-27-2022
//10:10pm
//hypotenuse calculator
#include <stdio.h>
#include <math.h>

double hypotenuse(double ,double);

int main(void){
	double as1 = 3;//triangle A side 1
	double as2 = 4;
	double bs1 = 5;//triangle B side 1
	double bs2 = 12;
	double cs1 = 8;//triangle C side 1
	double cs2 = 15;
	printf("%s%15s%15s\n","Side I","Side 2","Hypotenuse");
	printf("%.1f%15.1f%15.1f\n",as1,as2,hypotenuse(as1,as2));
	printf("%.1f%15.1f%15.1f\n",bs1,bs2,hypotenuse(bs1,bs2));
	printf("%.1f%15.1f%15.1f\n",cs1,cs2,hypotenuse(cs1,cs2));
}

double hypotenuse(double sd1,double sd2){//enters side one and side two
	return sqrt(pow(sd1,2) + pow(sd2,2));
}
