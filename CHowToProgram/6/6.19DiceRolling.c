// theBitRiddler
// 1/1/2023
// 2:19 PM
// Dice Rolling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 36

void roll(int b[]);
void printRating(int b[]);

int main(void) {
	int sum[SIZE] = {0};
	roll(sum);
	printRating(sum);
}

void roll(int b[]) {
	srand(time(NULL));
	for (int i = 0; i < 36000; ++i) {
		++b[(1 + rand() % 6) + (1 + rand() % 6)];
	}
}

void printRating(int b[]) {
	puts(" ------ Rating----- \nSum              Frequency");
	for (int rating = 2; rating <= 12; ++rating) {
		printf("%2d%10s%10d\n", rating, "        ", b[rating]);
	}
	puts("");
	(b[7] >= (1 / 6) * 36000) ? puts("The totals are reasonable") : puts("The totals aren't reasonable");
}
