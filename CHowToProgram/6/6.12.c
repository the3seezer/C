// theBitRiddler
// 12/29/2022
// 12:43 PM
// 6.12
#include <stdio.h>
#define SIZE 10
#define BONUS 15
#define TEMP 12
#define BEST 5

void printArray(const int b[], size_t size);

int main(void) {
	int counts[SIZE] = {0};// 6.12(a)
	
	int bonus[BONUS] = {0};// 6.12(b)
	for (size_t i = 0; i < BONUS; ++i) {
		bonus[i] = 1;
	}
	// puts("hesr");
//	float monthlyTemperature[TEMP] = {0}; // 6.12(c)
//	for (size_t i = 0; i < TEMP; ++i) {
//		scanf("%f", &monthlyTemperature[i]);
//	}
	
	int bestScores[BEST] = {1, 2, 3, 4, 5}; // 6.12(d)
	printArray(bestScores, BEST);
}



void printArray(const int b[], size_t size) {
	for (size_t i = 0; i < size; ++i) {
		printf("%d\n", b[i]);
	}
	puts("");
}
