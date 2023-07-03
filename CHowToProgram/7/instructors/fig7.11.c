/*
theBitRiddler
7/3/2023
10:27 AM
Putting values into an array, sorting the values into ascending order and
printing the resulting array.
*/
#include <stdio.h>

#define SIZE 10

void bubbleSort(int *const array, size_t size);

int main(void) {
  int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};

  puts("Data items in original order ");

  for (size_t i = 0; i < SIZE; i++) {
    printf_s("%4d", a[i]);
  } /* end for */

  bubbleSort(a, SIZE);

  puts("\nData items in ascending order ");
  for (size_t i = 0; i < SIZE; i++) {
    printf_s("%4d", a[i]);
  } /* end for */

  return 0;

} /* end main */

void bubbleSort(int *const array, size_t size) {
  void swap(int *element1Ptr, int *element2Ptr); // prototype

  for (int pass = 1; pass < size; pass++) {
    for (size_t j = 0; j < size - pass; j++) {
      // Compare adjacent elements
      if (array[j] > array[j + 1])
        swap(&array[j], &array[j + 1]);
    }
  } /* end for */
} /* end function bubbleSort */

void swap(int *element1Ptr, int *element2Ptr) {

  int hold = *element1Ptr;
  *element1Ptr = *element2Ptr;
  *element2Ptr = hold;

} /* end function swap */