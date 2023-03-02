//theBitRiddler
//11/28/2022
//5:57pm
// Computing the sum of the elements of an array.
#include <stdio.h>

#define SIZE 5

int main(void){
	int a[SIZE] = {1, 2, 3, 4, 5};
	int total = 0;
	
	for (size_t i = 0; i < SIZE; ++i) { //Summing up the elements
		total += a[i];
	}
	
	printf("The total of a's value is: %d\n",total);
}
