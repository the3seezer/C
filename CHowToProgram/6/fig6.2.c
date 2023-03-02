//theBitRiddler
//11/28/2022
//11:22am
//Initializing an Array in a definition with an initializer list
#include <stdio.h>
int main(void){
	int n[5] = {98, 12, 33, 48, 50};
	
	printf("%s%8s\n","Elements","Value");
	for (size_t i = 0; i < 5; i++) {
		printf("%7zu%8d\n", i, n[i]);
	}
}
