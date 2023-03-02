// theBitRiddler
// 12/9/2022
// 10:21 AM
// Checking the Github response
#include <stdio.h>

#define SIZE 50

int main(void){
	char string[SIZE] = "12 345690 ,";   // gets(string);
//	printf("%c%c%c%c%c%c%c%c%c%c%c\n", string[0], string[1], string[2], string[3], string[4], string[5], string[6], string[7], string[8], string[9], string[10]);
//	printf("%d %d %d %d %d %d %d %d %d %d %d\n", string[0], string[1], string[2], string[3], string[4], string[5], string[6], string[7], string[8], string[9], string[10]);
//	//printf("%d\n", ' ');
//	printf("SpaceToNumber 32:' ' %d\n", string[2] == 32);
//	printf("SpaceTo ' ':' ' %d\n", string[2] == ' ');
//	printf("'0'to Number 0: %d\n", string[6] == 0);
//	printf("'0'To '0': %d\n", string[6] == '0');
//	printf("end of string characterTo\'\\0':%d\n", string[50] == '\0');puts("");
//	printf("Unassingned elementTo 0: %d\n", string[25] == 0);
//	// printf("%s\n", string);
	for (size_t i = 0; i < 50; ++i) {
		if (string[i] != 0) { // ignore an unassigned element in the Array
			putchar(string[i]);
		}
		if (string[i] == ' ') { // space assigned element
			putchar(string[i]);
		}
	}
	puts("End");
	// printf("%d", sizeof(string));
}
