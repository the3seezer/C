//theBitRiddler
//11/28/2022
//11:46am
/*Specifiying array's size with a symbolic constant and initializing array elements with calculations
initializing elements of an array to even integers from 2 to 10
*/
#include <stdio.h>
#define SIZE 5 //constant specification of an array

int main(void){
	int s[SIZE] = {0}; //initializing all elements to zero
	
	for (size_t j = 0; j < SIZE; ++j) { //initializing elements by calculations
		s[j] = 2 + 2 * j;
	}
	
	printf("%s%8s\n","Elements","Value");
	for (size_t j = 0; j < SIZE; ++j) {
		printf("%7zu%8d\n", j, s[j]);
	}
}
