// theBitRiddler
// 12/22/2022
// 7:28 PM
// 6.8
#include <stdio.h>
#define SIZE 100
#define G 5

int main(void) {
	char f[SIZE] = {0};
	for (size_t i = 0; i < SIZE; ++i) {
		f[i] = 'a';
	}
	printf("7th element = %c\n", f[6]); // 6.8(a)
	
	float b[SIZE] = {0.0};
	b[3] = 6.7; // 6.8(b)
	
	int g[G] = {0};
	for (size_t i = 0; i < G; ++i) { // 6.8(c)
		g[i] = 8;
	}
	
	float c[SIZE] = {0};
	float total = 0;
	for (size_t i = 0; i < SIZE; ++i) {
		c[i] = i * i;
		total += c[i];// 6.8(d)
	}
	printf("Total %.2f\n", total); 
}
