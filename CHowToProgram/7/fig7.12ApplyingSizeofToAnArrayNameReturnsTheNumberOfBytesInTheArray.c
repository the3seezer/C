/*
theBitRiddler
7/3/2023
11:53 AM
Applying sizeof to an array name returns the number of bytes in the array.
*/
#include <stdio.h>

#define SIZE 20

size_t getSize(const float *ptr);

int main(void) {
  float array[SIZE] = {0};

  printf_s("%zu\n", sizeof(array));
  printf_s("%zu\n", getSize(array));

  return 0;
} /* end main */

size_t getSize(const float *ptr) {
  return sizeof(ptr);
} /* end function getSize */