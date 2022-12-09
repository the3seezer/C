// theBitRiddler
// 12/7/2022
// 9:42am
/*
Trying to modify an array with a const qualifier
*/
#include <stdio.h>
#define SIZE 3

void tryToModifyArray(const int b[], size_t size);

int main(void) {
	int a[SIZE] = {2, 3, 4};
	tryToModifyArray(a, SIZE);
}

void tryToModifyArray(const int b[], size_t size) {//Trying to modify an array with const qualifier will result to compilation error
	b[0]; // /= 2;
	b[1]; // /= 2;
	b[2]; // /= 2;
}
