//theBitRiddler
//11/28/2022
//11:00am
//Defining an Array and using a loop to set a value
#include <stdio.h>
//#include <stddef.h> for size_t
int main(void){
	int n[5];
	
	for (size_t i = 0; i < 5; i++) {//initializing 0 to n array
		n[i] = 0;
	}
	
	printf("%s%8s\n", "Elements", "Value");
	for (size_t i = 0; i < 5; i++) {
		printf("%7zu%8d\n", i, n[i]);
	}
}
