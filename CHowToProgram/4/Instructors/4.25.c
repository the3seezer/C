/*
 theBitRiddler
 11/04/2023
 15:13 
 Decimal, Binary, Octal and Hexadecimal
*/
#include <stdio.h>
int main(void) {
	int loop = 0;
	int number = 0;
	int temp = 0;
	
	printf("%s", "Decimal\tBinary\t\tOctal\tHexadecimal\n");
	
	for (loop = 1; loop <= 256; ++loop) {
		
		printf("%-7d\t", loop);
		
		/* Binary */
		number = loop;
		
		printf("%c", number == 256 ? '1' : '0');
		
		printf("%c", number < 256 && number >= 128 ? '1' : '0');
		number %= 128;
		
		printf("%c", number < 128 && number >= 64 ? '1' : '0');
		number %= 64;
		
		printf("%c", number < 64 && number >= 32 ? '1' : '0');
		number %= 32;
		
		printf("%c", number < 32 && number >= 16 ? '1' : '0');
		number %= 16;
		
		printf("%c", number < 16 && number >= 8 ? '1' : '0');
		number %= 8;
		
		printf("%c", number < 8 && number >= 4 ? '1' : '0');
		number %= 4;
		
		printf("%c", number < 4 && number >= 2 ? '1' : '0');
		number %= 2;
		
		printf("%c\t", number == 1 ? '1' : '0');
		
		
		/* octal */
		number = loop;
		
		printf("%d", number < 512 && number >= 64 ? number / 64 : 0);
		number %= 64;
		
		printf("%d", number < 64 && number >= 8 ? number / 8 : 0);
		number %= 8;
		
		printf("%d\t", number == 0 ? 0 : number);
		
		
		/* hexadecimal */
		
		number = loop;
		temp = 16;
		
		if (number < 4096 && number >= 256) {
			printf("%d", number / 256);
			number %= 256;
		}
		
		if (number < 256 && number >= 16) {
			temp = number / 16;
			number %= 16;
		}
		else {
			printf("%s", "0");
		}
		
		
		if (temp <= 9) {
			printf("%d", temp);
		}
		else if (temp <= 15 && temp >= 10) {
			printf("%c", 'A' + (temp - 10));
		}
		
		
		if (number <= 9) {
			printf("%d", number);
		}
		else if (number <= 15 && number >= 10) {
			printf("%c", 'A' + (number - 10));
		}
		
		
		printf("%s", "\n");
	}
}
