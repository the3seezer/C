/* 
 theBitRiddler
 4/25/2023
 7:18 PM
 Roman and Decimal numerals
*/
#include <stdio.h>
int main (void) {
	int loop = 0;
	int div = 0; /* tens digits */
	int mod = 0; /* ones digits */
	
	printf("%s", "Roman\nNumeral\t\tDecimal\n");
	
	for (loop = 1; loop <= 100; ++loop) {
		
		div = loop / 10;
		mod = loop % 10;
		
		switch (div) {
			
			case 0:
				break;
			
			case 1:
				printf("%s", "X");
				break;
			
			case 2:
				printf("%s", "XX");
				break;
				
			case 3:
				printf("%s", "XXX");
				break;
				
			case 4:
				printf("%s", "XL");
				break;
				
			case 5:
				printf("%s", "L");
				break;
				
			case 6:
				printf("%s", "LX");
				break;
				
			case 7:
				printf("%s", "LXX");
				break;
				
			case 8:
				printf("%s", "LXXX");
				break;
				
			case 9:
				printf("%s", "XC");
				break;
				
			case 10:
				printf("%s", "C");
			
		}
		
		
		switch (mod) {
			case 0:
				printf("\t\t%4d\n", div * 10 + mod);
				break;
				
			case 1:
				printf("I\t\t%4d\n", div * 10 + mod);
				break;
				
			case 2:
				printf("II\t\t%4d\n", div * 10 + mod);
				break;
				
			case 3:
				printf("III\t\t%4d\n", div * 10 + mod);
				break;
				
			case 4:
				printf("IV\t\t%4d\n", div * 10 + mod);
				break;
				
			case 5:
				printf("V\t\t%4d\n", div * 10 + mod);
				break;
				
			case 6:
				printf("VI\t\t%4d\n", div * 10 + mod);
				break;
				
			case 7:
				printf("VII\t\t%4d\n", div * 10 + mod);
				break;
				
			case 8:
				printf("VIII\t\t%4d\n", div * 10 + mod);
				break;
				
			case 9:
				printf("IX\t\t%4d\n", div * 10 + mod);
				break;
				
			case 10:
				printf("X\t\t%4d\n", div * 10 + mod);
				break;
		}
		
	}
	
}
