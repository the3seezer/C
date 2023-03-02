// theBitRiddler 
// 12/23/2022
// 2:32 PM
// 6.10 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RATE 9

int main(void) {
	srand(time(NULL));
	int counters[RATE] = {0};
	for (int i = 0; i < 10000; ++i) { // employees
		int grosses = rand() % 12000;
		int total = 200 + (grosses * .09);
		if (200 <= total && total <= 299) {
			++counters[0];
		}
		else if (300 <= total && total <= 399) {
			++counters[1];
		}
		else if (400 <= total && total <= 499) {
			++counters[2];
		}
		else if (500 <= total && total <= 599) {
			++counters[3];
		}
		else if (600 <= total && total <= 699) {
			++counters[4];
		}
		else if (700 <= total && total <= 799) {
			++counters[5];
		}
		else if (800 <= total && total <= 899) {
			++counters[6];
		}
		else if (900 <= total && total <= 999) {
			++counters[7];
		}
		else if (1000 <= total) {
			++counters[8];
		}
	}
	
	// Output the rating
	printf("%s%13s\n", "Ranges", "Ratings");
	for (size_t rating = 0; rating < RATE; ++rating) {
		if (0 <= rating && rating <= 7) {
			printf("$%zu00 - %zu99: %d\n", 2 + rating, 2 + rating, counters[rating]);
		}
		if (rating == 8) {
			printf("$1000 -   : %d\n", counters[rating]);
		}
	}
}
