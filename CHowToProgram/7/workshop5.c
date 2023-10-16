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
    memory[ 0  ] = +1061; // Read a number ... ; TOTAL to be, and read six more numbers...
    memory[ 1  ] = +1062;
    memory[ 2  ] = +1063;
    memory[ 3  ] = +1064;
    memory[ 4  ] = +1065;
    memory[ 5  ] = +1066;
    memory[ 6  ] = +1067;
    memory[ 7  ] = +2061; // load the number
    memory[ 8  ] = +3261; // divide by it to get 1
    memory[ 9  ] = +2168; // store 1 
    memory[ 10 ] = +2068; // load 1
    memory[ 11 ] = +3068; // add by it to get 2
    memory[ 12 ] = +3068; // ... 3
    memory[ 13 ] = +3068; // ... 4
    memory[ 14 ] = +3068; // ... 5
    memory[ 15 ] = +3068; // ... 6
    memory[ 16 ] = +3068; // ... 7
    memory[ 17 ] = +2169; // store 7 for division to get average
    memory[ 18 ] = +2061; // load the first number
    memory[ 19 ] = +3062; // add the rest of the numbers ...
    memory[ 20 ] = +3063;
    memory[ 21 ] = +3064;
    memory[ 22 ] = +3065;
    memory[ 23 ] = +3066;
    memory[ 24 ] = +3067;
    memory[ 25 ] = +2170; // store total
    memory[ 26 ] = +2070; // load total
    memory[ 27 ] = +3269; // divide by 7
    memory[ 28 ] = +2171; // store average
    memory[ 29 ] = +1171; // Write average

    for ( i = 0; i < 30; i++ ) {
        inst = memory[  i  ];
            
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