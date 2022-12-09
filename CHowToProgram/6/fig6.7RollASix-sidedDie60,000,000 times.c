// theBitRiddler
// 11/30/2022
// 10:19am
/* Rolling a die 60,000,000 times and summarizing the results in an array
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 7

int main(void){
	srand(time(NULL));
	
	int frequency[SIZE] = {0};
	
	for (int roll = 1; roll <= 60000000; ++roll) {
		size_t face = 1 + rand() % 6;
		++frequency[face];
	}
	
	printf("%s%17s\n", "Face", "Frequency");
	for (size_t face = 1; face < SIZE; ++face) {
		printf("%4zu%17d\n", face, frequency[face]);
	}
}
