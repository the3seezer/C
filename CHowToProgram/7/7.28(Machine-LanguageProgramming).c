/*
theBitRiddler
10/6/2023
10:50 AM
 (Machine-Language Programming) 
*/
#include <stdio.h>
#define SIZE 100
// Input/Output operations:
#define READ 10 // Read a word from the keyboard into a specific location in memory.
#define WRITE 11 // Write a word from a specific location in memory to the screen.
// Load/store operations:
#define LOAD 20 // Load a word from a specific location in memory into the accumulator.
#define STORE 21 // Store a word from the accumulator into a specific location in memory.
// Arithmetic operations:
#define ADD 30 // Add a word from a specific location in memory to the word in the accumulator ( leave the result in the accumulator).
#define SUBTRACT 31 // Substract a word from a specific location in memory into the word in the accumulator ( leave the result in the accumulator).
#define DIVIDE 32 // Divide a word from a specific location in memory into the word in the accumulator (leave the result in the accumulator).
#define MULTIPLY 33 // Multiply a word from a specific location in memory by the word in the accumulator (leave the result in the accumulator).
// transfer-of-control operations:
#define BRANCH 33 // Branch to a specific location in a memory.
#define BRANCHNEG 41 // Branch to a specific location in memory if the accumulator is negative.
#define BRANCHZERO 42 // Branch to a specific location in memory if the accumulator is zero.
#define HALT 43 // Halt---i.e., the program has completed its task.

void accumulator( int );
void validAssign( int* i, int*const mem, int );
int splt( int * ); // split the instruction; the command and the location
int main( void ) {
    int memory[ SIZE ] = { 0 };
    int i = 0; // instruction count
    while( i < SIZE ) {
        int cmd = 0;
        scanf( "%d", &cmd );
        validAssign( &i, memory, cmd );
        // split command


    } // end while
    return 0;

} /* end main */

void accumulator( int instr ) {

} /* end function accumulator */

void validAssign( int* i, int*const mem, int cmd ) {
    while( mem[ *i ] != 0 && *i < SIZE ) {
        *i++;
    } // end while 
    mem[ *i++ ] = cmd;
    return;
} /* end function validLocation*/

int splt( int* cmd ) {

} /* end function splt */