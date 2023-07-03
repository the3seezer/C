/*
theBitRiddler
7/2/2023
7:20 PM
Attempting to modify data through a non-constant pointer to constant data.
Xcode’s LLVM compiler reports the error:
error: read-only variable is not assignable
and the GNU gcc compiler reports the error:
error: assignment of read-only location ‘*xPtr’
*/
#include <stdio.h>

void f( const int *xPtr );

int main( void ) {
    int y = 5;

    f( &y );// f attempts illegal modification
    
} /* end main */

// xPtr cannot be used to modify the
// value of the variable to which it points
void f( const int *xPtr ) {
    *xPtr = 100;// error: cannot modify a const object
} /* end main */
