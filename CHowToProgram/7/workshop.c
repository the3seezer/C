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

void load( int [] );
void execute( int []);
int dump( int memory[], int accumulator, int instructionCounter, int instructionRegistor, int OperationCode, int operand );
int main( void ) {
    int memory[ SIZE ] = { 0 };
    int instructionCounter = 0; // instruction counter
    int instructionRegister = 0; // instruction register
    int operationCode = 0; // a command of the instruction
    int operand = 0; // a location of the instruction
    int accumulator = 0;

    printf_s( "%s", "***            Welcome to Simpletron            ***\n"
                    "***                                             ***\n"
                    "***  Please enter your program one instruction  ***\n"
                    "***  (or data word) at a time. I will type the  ***\n"
                    "***  location number and a question mark (?).   ***\n"
                    "***  You then type the word for that location.  ***\n"
                    "***  Type the sentinel -99999 to stop entering  ***\n"
                    "***  your program.                              ***\n");

    load( memory );

    execute( memory );

    dump( memory, accumulator, instructionCounter,instructionRegister, operationCode, operand );

    return 0;
} /* end main */

void load( int memory[]) {
    memory[ 0  ] = +1009; // Read a number ... ; TOTAL to be
    memory[ 1  ] = +1010; // load the number
    memory[ 2  ] = +2009; // divide by it to get 1
    memory[ 3  ] = +3110; // store 1 
    memory[ 4  ] = +4107; // load 1
    memory[ 5  ] = +1109; // add by it to get 2
    memory[ 6  ] = +4300; // ... 3
    memory[ 7  ] = +1110; // ... 4
    memory[ 8  ] = +4300; // ... 5
    memory[ 9  ] = +0000; // ... 6
    memory[ 10 ] = +0000; // ... 7
    
    printf_s( "%s", "\n***    Program loading completed    ***\n\n\n\n");
} /* end function load */

void execute( int memory[] ) {
    printf_s( "%s", "***    Program execution begins     ***\n");

    int accumulator = 0;
    int operationCode = 0;
    int instructionCounter = 0;
    int instructionRegister = 0;
    int operand = 0;

    while ( operationCode != HALT ) {

        instructionRegister = memory[ instructionCounter++ ];
            
        operationCode = instructionRegister / 100;
        operand = instructionRegister % 100;

        switch ( operationCode ) {
            case READ:
                printf_s( "\t%s", "Enter an integer "); 
                scanf( "%d", &memory[ operand ] );
                break;
            case WRITE: 
                printf_s( "\tNumber is %d\n", memory[ operand ] );
                break; 
            case LOAD: 
                accumulator = memory[ operand ];
                break; 
            case STORE: 
                memory[ operand ] = accumulator;
                break;
            case ADD:
                accumulator += memory[ operand ];
                break;
            case SUBTRACT:
                accumulator -= memory[ operand ];
                break;
            case DIVIDE:
                accumulator /= memory[ operand ];
                break;
            case MULTIPLY:
                accumulator *= memory[ operand ];
                break;
            case BRANCH:
                instructionCounter = operand;
                break;
            case BRANCHNEG:
                if ( accumulator < 0 ) {
                    instructionCounter = operand; 
                } // end if
                break;
            case BRANCHZERO:
                if ( accumulator == 0 ) {
                    instructionCounter = operand;
                } // end if
                break;
            case HALT:
                printf_s( "%s", "*** Simpletron execution terminated ***\n\n\n");
                break;
        } // end switch   
    } // end while
} /* end function execute */

int dump( int memory[], int accumulator, int i, int instReg, int code, int operand ) {
    printf_s( "%s%+05d%s%02d%s%+05d%s%02d%s%02d", "REGISTERS: \n"
            "Accumulator              ", accumulator,
            "\ninstructionCounter       ", i,
            "\ninstructionRegister      ", instReg,
            "\noperationCode            ", code,
            "\noperand                  ", operand );

    printf_s( "%s", "\n\nMEMORY:\n\t  [ 0 ]  [ 1 ]  [ 2 ]  [ 3 ]  [ 4 ]  [ 5 ]  [ 6 ]  [ 7 ]  [ 8 ]  [ 9 ]\n" );
    int row = 0;
    for ( size_t i = 0; i < SIZE; i++ ) {
        if (i % 10 == 0 ) {
            printf_s( "\n[ %d%s ]    ", row, (i == 0) ? " " : "" );
            row += 10;
        } // end if
        printf_s( "%+05d  ", memory[ i ] );
    } // end for

    puts("");
} /* end function showMemory */
