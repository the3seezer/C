// theBitRiddler
// 12/9/2022
// 10:21 AM
// Checking the Github response
#include <stdio.h>

#define SIZE 50

int main(void){
	char string[SIZE] = "1234 5690 ,";   // gets(string);
	long long int s_n = 0;
	for (size_t i = 0; i < 50; ++i) {
		if (string[i] != 0) { // ignore an unassigned element in the Array
			putchar(string[i]);
		}
	}
	puts("End");
	
	for (size_t i = 0; i < 50; ++i) {
		if (string[i] != 0) {
			if (string[i] == ' ') {
				continue;
			}
			int num = 5;
			s_n = num + 10 * s_n;
		}
	}
	
	printf("%d\n", s_n);
	// printf("%d", sizeof(string));
}
