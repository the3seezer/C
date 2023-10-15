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

    memory[ 0  ] = +1008;
    memory[ 1  ] = +1009;
    memory[ 2  ] = +1010;
    memory[ 3  ] = +1011;
    memory[ 4  ] = +1012;
    memory[ 5  ] = +1013;
    memory[ 6  ] = +1014;
    memory[ 7  ] = +4015; // Branch to 15
    memory[ 8  ] = +0000; // Variables ...
    memory[ 9  ] = +0000;
    memory[ 10 ] = +0000;
    memory[ 11 ] = +0000;
    memory[ 12 ] = +0000;
    memory[ 13 ] = +0000;
    memory[ 14 ] = +0000;
    memory[ 15 ] = +2008; // load to accumulator
    memory[ 16 ] = +3009; // add to accumulator... Total
    memory[ 17 ] = +3010;
    memory[ 18 ] = +3011;
    memory[ 19 ] = +3012;
    memory[ 20 ] = +3013;
    memory[ 21 ] = +3014; // Total
    memory[ 22 ] = +2150; // Store total to 50 
    memory[ 23 ] = +2008; // load 
    memory[ 24 ] = +3208; // divide to get 1
    memory[ 25 ] = +2151; // store 1 to 51
    memory[ 26 ] = +2009; // load ...
    memory[ 27 ] = +3209;
    memory[ 28 ] = +2152;
    memory[ 29 ] = +2010; // load ...
    memory[ 30 ] = +3210;
    memory[ 31 ] = +2153;
    memory[ 32 ] = +2011; // load ...
    memory[ 33 ] = +3211;
    memory[ 34 ] = +2154;
    memory[ 35 ] = +2012; // load ...
    memory[ 36 ] = +3212;
    memory[ 37 ] = +2155;
    memory[ 38 ] = +2013; // load ...
    memory[ 39 ] = +3213;
    memory[ 40 ] = +2156;
    memory[ 41 ] = +2014; // load ...
    memory[ 42 ] = +3214;
    memory[ 43 ] = +2157; // last 1 stored in 57
    memory[ 44 ] = +2051; // load 1 to accumulator
    memory[ 45 ] = +3052; // add 1 to 1 ...
    memory[ 46 ] = +3053;
    memory[ 47 ] = +3054;
    memory[ 48 ] = +3055;
    memory[ 49 ] = +4058; // Branch to 58
    memory[ 50 ] = +0000; // ( TOTAL )
    memory[ 51 ] = +0000;
    memory[ 52 ] = +0000;
    memory[ 53 ] = +0000;
    memory[ 54 ] = +0000;
    memory[ 55 ] = +0000;
    memory[ 56 ] = +0000;
    memory[ 57 ] = +0000;
    memory[ 58 ] = +3056;
    memory[ 59 ] = +3057; // last 1 added to get 7
    memory[ 60 ] = +2166; // store 7 to 66
    memory[ 61 ] = +2050; // load Total
    memory[ 62 ] = +3266; // divide by 7 from 66 to get average
    memory[ 63 ] = +2167; // store average to 67
    memory[ 64 ] = +1167; // Write average
    memory[ 65 ] = +4300; // HALT
    memory[ 66 ] = +0000; // 7
    memory[ 67 ] = +0000; // average

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
                printf_s( "\tlocation %d \n\taverage is %d\n", locatn, memory[ locatn ] );
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