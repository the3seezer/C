#include <stdio.h>
#define SIZE 10

void assign(int array[], size_t start, size_t size);
int sum(int array[], size_t size);
void display(int array[], size_t start, size_t size);

int main(void) {
	int array[SIZE] = {0};
	assign(array, 0, SIZE);
	printf("Sum: %d\n", sum(array, SIZE));
	display(array, 0, SIZE);
}

void assign(int array[], size_t start, size_t size) {
	if (start < size) {
		array[start] = start + 1;
		assign(array, start + 1, size);	
	}
}

void display(int array[], size_t start, size_t size) {
	if (start < size) {
		printf("%d\n", array[start]);
		display(array, start + 1, size);
	}
}

int sum(int array[], size_t size) {
	if (size == 1) {
		return array[0];
	}
	else {
		return array[size - 1] + sum(array, size - 1);
	}
}
