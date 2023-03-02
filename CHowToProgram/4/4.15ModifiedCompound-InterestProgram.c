 // fig04_04.c
 // Calculating compound interest.
 #include <stdio.h>
 #include <math.h> 

 int main(void) {
 double principal = 1000.0; // starting principal
 //double rate = 0.05; // annual interest rate

 // output table column heads
 printf("%4s%21s\n", "Year", "Amount on deposit");

 // calculate amount on deposit for each of ten years
 for (int year = 1; year <= 10; ++year) {

 // calculate new amount for specified year for each rate;
 	for(int i = 5;i <= 10;i++){
 		double rate = (double) i / 100;
 		printf("Rate :%lf\n",rate);
 		double amount = principal * pow(1.0 + rate, year);
 		printf("%4d%21.2f\n", year, amount);
	 }
 puts("");
 // output one table row 
 } 
 } 
