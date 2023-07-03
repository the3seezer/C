/*
theBitRiddler
7/2/2023
7:39 PM
Attempting to modify a constant pointer to non-constant data.
*/
#include <stdio.h>

int main( void ) {
    int x = 0;
    int y = 0;

    int * const ptr = &x;

// ptr is a constant pointer to an integer that can be modified
// through ptr, but ptr always points to the same memory location

    *ptr = 7; // allowed: *ptr is not const
    ptr = &y; // error: ptr is const; cannot assign new address
} /* end main */