/*
theBitRiddler
10/18/2023
11:53 AM 
A computer Simulator 
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
#define BRANCH 40 // Branch to a specific location in a memory.
#define BRANCHNEG 41 // Branch to a specific location in memory if the accumulator is negative.
#define BRANCHZERO 42 // Branch to a specific location in memory if the accumulator is zero.
#define HALT 43 // Halt---i.e., the program has completed its task.
void load( int[], int );
void execute( int [] );
void dump( int[] );
int main() {
    int memory[ SIZE ];
    int accumulator = +0000;
    int instructionCounter = 00;
    int instructionRegister = +0000;
    int operationCode = 00;
    int operand = 00;

} /* end main */

void load( int memory[], int instructionCounter ) {

} /* end function load */

void execute( int memory[] ) {

} /* end function execute */

void dump( int memory[] ) {

} /* end function dump */