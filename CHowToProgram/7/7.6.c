/*
theBitRiddler
7/10/2023
11:48 AM
7.6
*/
#include <stdio.h>

int main( void ) {
    int *zPtr; // will reference array z 
    int *aPtr = NULL;
    void *sPtr = NULL;
    int number;
    int z[5] = { 1, 2, 3, 4, 5 };
    sPtr = z;

    /*(a) 
    ++zptr 
    (undefined or unassigned pointer); 

    Error: z has not been initialized
    Correction: Initialize zPtr with zPtr = z; before doing pointer arithmetic.
    */

    /*(b)
    number = zPtr;
    (variable can't be signed an address of pointer/pointer);

    Error: The pointer is not dereferenced.
    Correction: Change the statement to number = *zPtr;
    */

    /*(c)
    zPtr = z;
    number = *zPtr[2];
    That is array element three

    Error: zPtr[2] is not a pointer and should not be dereferenced.
    Correction: Change *zPtr[2] to zPtr[2]. 
    */

    /*(d)
    for (size_t i = 0; i <= 5; ++i) {
        printf("%d ", zPtr[i]);
    }
    i subscript will go beyong the array elements

    Error: Referring to an array element outside the array bounds with pointer
    subscripting.
    Correction: Change the operator <= in the for condition to <.
    */

    /*(e)
    number = *sPtr;
    You can't deference a void pointer

    Error: Dereferencing a void pointer.
    Correction: To dereference the pointer, it must first be cast to an integer
    pointer. Change the statement to number = *((int *) sPtr);
    */

    /*(f)
    ++z
    z is a constant pointer

    Error: Trying to modify an array name with pointer arithmetic.
    Correction: Use a pointer variable instead of the array name to accomplish
    pointer arithmetic, or subscript the array name to refer to a specific element. 
    */

}