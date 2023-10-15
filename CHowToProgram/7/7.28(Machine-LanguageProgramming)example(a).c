/*
theBitRiddler
10/14/2023
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
#define BRANCH 40 // Branch to a specific location in a memory.
#define BRANCHNEG 41 // Branch to a specific location in memory if the accumulator is negative.
#define BRANCHZERO 42 // Branch to a specific location in memory if the accumulator is zero.
#define HALT 43 // Halt---i.e., the program has completed its task.

int splt( int * const, int * const, int * const ); // split the instruction; the command and the location
int main( void ) {
    int memory[ SIZE ] = { 0 };
    int i = 0; // instruction count
    int inst = 0; // a full instruction
    int cmd = 0; // a command of the instruction
    int locatn = 0; // a location of the instruction
    int accumulator = 0;
    memory[ 0 ] = +1007;
    memory[ 1 ] = +1008;
    memory[ 2 ] = +2007;
    memory[ 3 ] = +3008;
    memory[ 4 ] = +2109;
    memory[ 5 ] = +1109;
    memory[ 6 ] = +4300;
    memory[ 7 ] = +0000;
    memory[ 8 ] = +0000;
    memory[ 9 ] = +0000;

    while( i < SIZE && cmd != HALT ) {
        inst = memory[  i++  ];
            
        // split command
        splt( &inst, &locatn, &cmd ); 
        switch ( cmd ) {
            case READ:
                printf_s( "\t%s", "Enter an integer "); 
                scanf( "%d", &memory[ locatn ] );
                break;
            case WRITE: 
                printf_s( "\tlocation %d is %d\n", locatn, memory[ locatn ] );
                break; 
            case LOAD: 
                accumulator = memory[ locatn ];
                break; 
            case STORE: 
                memory[ locatn ] = accumulator;
                break;
            case ADD:
                accumulator += memory[ locatn ];
                break;
            case SUBTRACT:
                accumulator -= memory[ locatn ];
                break;
            case DIVIDE:
                accumulator /= memory[ locatn ];
                break;
            case MULTIPLY:
                accumulator *= memory[ locatn ];
                break;
            case BRANCH:
                inst = memory[ i = locatn ];
                break;
            case BRANCHNEG:
                if ( accumulator < 0 ) {
                    inst = memory[ i = locatn ]; 
                } // end if
                break;
            case BRANCHZERO:
                if ( accumulator == 0 ) {
                    inst = memory[ i = locatn ];
                } // end if
                break;
            case HALT:
                break;
        } // end switch   
    } // end while
    return 0;

} /* end main */

int splt( int* const inst, int * const location, int * const cmd ) {
    *location = *inst % 100; // get a location
    *cmd  = * inst / 100; // get a command
} /* end function splt */