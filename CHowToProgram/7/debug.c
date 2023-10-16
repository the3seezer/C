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

    memory[ 0  ] = +1061; // Read a number ... ; TOTAL to be
    memory[ 1  ] = +2061; // load the number
    memory[ 2  ] = +3261; // divide by it to get 1
    memory[ 3  ] = +2163; // store 1 
    memory[ 4  ] = +2063; // load 1
    memory[ 5  ] = +3063; // add by it to get 2
    memory[ 6  ] = +3063; // ... 3
    memory[ 7  ] = +3063; // ... 4
    memory[ 8  ] = +3063; // ... 5
    memory[ 9  ] = +3063; // ... 6
    memory[ 10 ] = +3063; // ... 7
    memory[ 11 ] = +2164; // store 7 for termination
    memory[ 12 ] = +2165; // store 7 for division to get average
    memory[ 13 ] = +1062; // Read a second number < Loop begins here >
    memory[ 14 ] = +2061; // load the first number
    memory[ 15 ] = +3062; // add the second number
    memory[ 16 ] = +2161; // store the resulting total to the first number to overwrite it
    memory[ 17 ] = +2064; // load 7
    memory[ 18 ] = +3163; // Substract 1 
    memory[ 19 ] = +2164; // store the results to 7 to overwrite it
    memory[ 20 ] = +4122; // Branchneg to 22
    memory[ 21 ] = +4013; // Branch to 13
    memory[ 22 ] = +2061; // load the total
    memory[ 23 ] = +3265; // divide by 7
    memory[ 24 ] = +2166; // store average
    memory[ 25 ] = +1166; // Write the average
    memory[ 26 ] = +4300; // HALT

    memory[ 61 ] = +0000; // first 
    memory[ 62 ] = +0000; // second
    memory[ 63 ] = +0000; // 1
    memory[ 64 ] = +0000; // Terminator ( 7 )
    memory[ 65 ] = +0000; // 7
    memory[ 66 ] = +0000; // AVERAGE

    for ( i = 0; i <= 65; i++ ) {
        inst = memory[ i ];
            
        // split command
        splt( &inst, &locatn, &cmd ); 
        switch ( cmd ) {
            case READ:
                printf_s( "\t%s", "Enter an integer "); 
                scanf( "%d", &memory[ locatn ] );
                break;
            case WRITE: 
                printf_s( "\tAverage is %d\n", memory[ locatn ] );
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