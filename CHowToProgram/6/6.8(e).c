// theBitRiddler
// 12/22/2022
// 10:25 PM
// Exercise 6.8(e) 
#include <stdio.h>
#define SIZE 11
#define BIG 34

int main(void) {
	int a[SIZE] = {0};
	for (size_t i = 0; i < SIZE; ++i) {
		a[i] = i;
		//printf("%2d", a[i]);
	}
	puts("");
	
	int b[BIG] = {a};
	for (size_t i = 0; i < BIG; ++i) {
		printf("%3d", b[i]);
	}
}
