/*
theBitRiddler
6/29/2023
11:25 AM
BucketSort
*/

#include <stdio.h>

#define SIZE 12

void bucketSort(int a[]);
void distributeElements(int a[], int bucket[][ SIZE ], int digit );
void collectElements(int a[], int bucket[][ SIZE ]);
int numberOfDigits(int a[]);
void zeroBucket(int bucket[][ SIZE ]);

int main( void ) {
    int array[ SIZE ] = { 19, 13, 5, 27, 1, 26, 31, 16, 2, 9, 11, 21 };

    printf_s( "%s", "Array elements in original order\n");
    
}