// theBitRiddler
// 12/7/2022
// 12:15pm
/* Bubble Sort
 Sorting an array’s values into ascending order.
 */
#include <stdio.h>
#define SIZE 10
int main(void) {
	int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
	puts("Data items in Original Order:");
	for (size_t j = 0; j < SIZE; ++j) {
		printf("%4d",a[j]);
	}
	
	for (int pass = 1; pass < SIZE; ++pass) {// the pass btn two elements
		for (size_t i = 0; i < SIZE - 1; ++i) {// the swapping after comparison if first element is greater than the second element
			if (a[i] > a[i + 1]) {
				int hold = a[i];
				a[i] = a[i + 1];
				a[i + 1] = hold;
			}
		}
	}
	
	puts("\nData items in ascending order");
	for (size_t l = 0; l < SIZE; ++l) {
		printf("%4d",a[l]);
	}
}
