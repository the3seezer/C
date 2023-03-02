// theBitRiddler
// 12/9/2022
// 10:21 AM
// Checking the Github response
#include <stdio.h>

#define SIZE 10

int main(void){
	char string[SIZE] = "";
	gets(string);
	
	for (size_t i = 0; i < SIZE; ++i) {
		if (string[i] != 0) { // print assigned element and ignore unassigned element in the Array
			putchar(string[i]);
		}
	}
	puts("End");
	// printf("%d", sizeof(string));
}
