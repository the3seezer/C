// theBitRiddler
// 12/9/2022
// 10:21 AM
// Checking the Github response
#include <stdio.h>

#define SIZE 50

int main(void){
	char string[50] = "Ba chu0 ";   // gets(string);
	printf("%c%c%c%c%c%c%c\n", string[0], string[1], string[2], string[3], string[4], string[5], string[6]);
	printf("%d %d %d %d %d %d %d\n", string[0], string[1], string[2], string[3], string[4], string[5], string[6]);
	//printf("%d\n", ' ');
	printf("%d\n", string[49] == 0);
	printf("%d\n", string[2] == ' ');
	printf("%d\n", string[2]);
	
	// printf("%s\n", string);
	for (size_t i = 0; i < 50; ++i) {
		if (string[i] != 0) {
			putchar(string[i]);
		}
		if (string[i] == ' ') {
			putchar(string[i]);
		}
	}
	puts("End");
	// printf("%d", sizeof(string));
}
