//theBitRiddler
//11/30/2022
//9:04am
//workshop
#include <stdio.h>

#define RESPONSES_SIZE 20
#define FREQUENCES_SIZE 6

int main(void){
	int responses[RESPONSES_SIZE] = {1, 2, 3, 4, 5, 4, 3, 2, 5, 5, 3, 2, 5, 1, 2, 5, 3, 4, 5, 2};
	int frequences[FREQUENCES_SIZE] = {0};
	for (size_t answer = 0; answer < RESPONSES_SIZE; ++answer) { //assigning the subscripts so they start from zero to 19
		++frequences[responses[answer]];
	}
	printf("%s%8s\n","Rating","Frenquency");
	for (size_t rating = 1; rating < FREQUENCES_SIZE; ++rating) {
		printf("%6zu%8d\n", rating, frequences[rating]);
	}	
}
