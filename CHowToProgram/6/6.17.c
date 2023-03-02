// theBitRiddler
// 1/1/2023
// 1:24 PM
// Array Recursive Total function; What does it do
#include <stdio.h>
#define SIZE 10

int total(const int b[], size_t p);

int main(void) {
	int a[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	int result = total(a, SIZE);
	printf("Total:%d", result);
}

int total(const int b[], size_t p) {
	if (p == 1) {
		return b[0];
	}
	else {
		return b[p - 1] + total(b, p - 1);
	}
}
