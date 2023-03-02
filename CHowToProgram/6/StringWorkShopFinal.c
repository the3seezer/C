// theBitRiddler
// 12/9/2022
// 10:21 AM
// Checking the Github response
#include <stdio.h>

#define SIZE 50

int main(void){
	char string[SIZE] = "12 345690 ,";   // gets(string);

	for (size_t i = 0; i < 50; ++i) {
		if (string[i] != 0) { // ignore an unassigned element in the Array
			putchar(string[i]);
			switch(string[i]) {
				case '1':
					printf("%d", 1);
					break;
				case '2':
					printf("%d", 2);
					break;
				case '3':
					printf("%d", 3);
					break;
				case '4':
					printf("%d", 4);
					break;
				case '5':
					printf("%d", 5);
					break;
				case '6':
					printf("%d", 6);
					break;
				case '9':
					printf("%d", 9);
				default:
					break;	
			}
		}
	}
	puts("End");
	// printf("%d", sizeof(string));
}
