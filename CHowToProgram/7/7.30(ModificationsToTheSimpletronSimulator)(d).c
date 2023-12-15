/*
theBitRiddler
12/15/2023
4:53 PM
Modifications To the Simpletron Simulator
*/
#include <stdio.h>
#include <math.h>

#define SIZE 1000 // 3E8
#define TRUE 1
#define FALSE 0
#define SENTINAL -16777215  // -FFFFFF
#define READ 10 // A
#define WRITE 11 // B
#define LOAD 20 // 14
#define STORE 21 // 15
#define ADD 30 // 1E
#define SUBSTRACT 31 // 1F
#define DIVIDE 32 // 20
#define MULTIPLY  33 // 21
#define MOD 34 // 22
#define POW 35 // 23
#define BRANCH 40 // 28
#define BRANCHNEG 41 // 29
#define BRANCHZERO 42 // 2A
#define HALT 43 // 2B

void load( int *loadMemory );
void execute( int *memory, int *acPtr, int *icPtr, int *irPtr, int *opCodePtr, int *opPtr );
void dump( int *memory, int accumulator, int instructionCounter, int instructionRegister, int operationCode, int operand );
int validWord( int word );

int main( void ) {
    int memory[ SIZE ] = { 0 };
    int accumulator = 0;
    int instructionCounter = 0;
    int instructionRegister = 0;
    int operationCode = 0;
    int operand = 0;

    load( memory );
    execute( memory, &accumulator, &instructionCounter, &instructionRegister, &operationCode, &operand );
    dump( memory, accumulator, instructionCounter, instructionRegister, operationCode, operand );

    return 0;
} /* end main */

void dump( int *memory, int accumulator, int instructionCounter, int instructionRegister, int operationCode, int operand ) {
    printf_s( "%s\n%-23s%+010d\n%-23s%10.3d\n%-23s%+010d\n%-23s%10.2d\n%-23s%10.2d\n",
    "REGISTERs", "accumulator", accumulator, "instructionCounter", instructionCounter, "instructionRegister", instructionRegister, 
    "operationCode", operationCode, "operand", operand );

    printf_s( "%s\n ", "MEMORY" );

    for ( int i = 0; i <= 9; i++ ) {
        printf_s( "%5d      ", i );
    } // end for

    for ( size_t i = 0; i < SIZE; i++ ) {

        if ( i % 10 == 0 ) {
            printf_s( "\n%03d ", i );
        } // end if

        printf_s( "%+010d ", memory[ i ] );

    } // end for

    printf_s( "%s", "\n" );
} /* end function execute */

void execute( int *memory, int *acPtr, int *icPtr, int *irPtr, int *opCodePtr, int *opPtr ) {
    printf_s( "%s", "*** Program execution begins ***\n");
    int fatal = FALSE; // fatal error flag 
    int temp = 0; 

    *irPtr = memory[ *icPtr ];
    *opCodePtr = *irPtr / 4096;
    *opPtr = *irPtr % 4096;

    while ( *opCodePtr != HALT && fatal != TRUE ) {

        switch ( *opCodePtr ) {
            case READ:
                printf_s( "%s", "Enter an integer ");
                scanf( "%d", &temp );

                while ( !validWord( temp ) ) {
                    printf_s( "%s", "Number out of range please enter again " );
                    scanf( "%d", &temp );
                } // end while

                memory[ *opPtr ] = temp;
                ++( *icPtr );
                break;
            case WRITE:
                printf_s( "Content is %d\n", memory[ *opPtr ] );
                ++( *icPtr );
                break;
            case LOAD:
                *acPtr = memory[ *opPtr ];
                ++( *icPtr );
                break;
            case STORE: 
                memory[ *opPtr ] = *acPtr;
                ++( *icPtr );
                break;
            case ADD:
                temp = *acPtr + memory[ *opPtr ];

                if ( !validWord( temp ) ) {
                    printf_s( "%s", "*** FATAL ERROR, accumulator overflow          ***\n"
                                    "*** Simpletron execution abnormally terminated ***\n" );
                    fatal = TRUE;
                } // end if
                else {
                    *acPtr = temp;
                    ++( *icPtr );
                } // end else
                break;
            case SUBSTRACT:
                temp = *acPtr - memory[ *opPtr ];

                if ( !validWord( temp ) ) {
                    printf_s( "%s", "*** FATAL ERROR, accumulator overflow          ***\n"
                                    "*** Simpletron execution abnormally terminated ***\n" );
                    fatal = TRUE;
                } // end if
                else {
                    *acPtr = temp;
                    ++( *icPtr );
                } // end else
                break;
            case DIVIDE:
                if ( memory[ *opPtr ] == 0 ) {
                    printf_s( "%s", "*** FATAL ERROR, attempt to divide by zero     ***\n"
                                    "*** Simpletron execution abnormally terminated ***\n" );
                    fatal = TRUE;
                } // end if
                else {
                    *acPtr /= memory[ *opPtr ];
                    ++( *icPtr );
                } // end else
                break;
            case MULTIPLY:
                temp = *acPtr * memory[ *opPtr ];

                if ( !validWord( temp ) ) {
                    printf_s( "%s", "*** FATAL ERROR, accumulator overflow          ***\n"
                                    "*** Simpletron execution abnormally terminated ***\n" );
                    fatal = TRUE;
                } // end if
                else {
                    *acPtr = temp;
                    ++( *icPtr );
                } // end else
                break;
            case MOD:
                temp = ( int ) *acPtr;
                temp %= ( int ) memory[ *opPtr ];
                *acPtr = ( double ) temp;
                ++( *icPtr );
                break;
            case POW:
                temp = ( int ) pow( *acPtr, memory[ *opPtr ] );
                if ( !validWord( temp ) ) {
                    printf_s( "%s", "*** FATAL ERROR, accumulator overflow          ***\n"
                                    "*** Simpletron execution abnormally terminated ***\n" );
                    fatal = TRUE;
                } // end if
                else {
                    *acPtr = temp;
                    ++( *icPtr );
                } // end else
                break;
            case BRANCH:
                *icPtr = *opPtr;
                break;
            case BRANCHNEG:
                if ( *acPtr < 0 ) {
                    *icPtr = *opPtr;
                } // end if
                else {
                    ++( *icPtr );
                } // end else
                break;
            case BRANCHZERO:
                if ( *acPtr == 0 ) {
                    *icPtr = *opPtr;
                } // end if
                else {
                    ++( *icPtr );
                } // end else
                break;
            default:
                printf_s( "%s", "*** FATAL ERROR, invalid operation Code detected ***\n"
                                "*** simpletron execution abnormally terminated   ***\n" );
                fatal = TRUE;
                break;
        } // end switch

        *irPtr = memory[ *icPtr ];
        *opCodePtr = *irPtr / 4096;
        *opPtr = *irPtr % 4096;
    } // end while

    if ( !fatal )
        printf_s( "%s", "*** Simpletron execution terminated ***\n" );
} /* end function execute */

void load( int *loadMemory ) {
    long int instruction = 0;
    int i = 0; // indexing variable

    printf_s( "%s\n\n%s\n%s\n%s\n%s\n%s\n%s\n",
     "***           Welcome to Simpletron            ***",
     "*** Please enter your program one instruction  ***",
     "*** (or data word) at a time. I will type the  ***",
     "*** location number and a question mark (?).   ***",
     "*** You then type the word for that location.  ***",
     "*** Type the sentinel -FFFFFF to stop entering ***",
     "*** your program.                              ***" );

    printf_s( "%s", "00 ? " );
    scanf( "%lx", &instruction );

    while ( instruction != SENTINAL ) {

        if ( !validWord( instruction ) ) {
            printf_s( "%s", "Number out of range please enter again \n");
        } // end if
        else {
            loadMemory[ i++ ] = instruction;
        } // end else

        printf_s( "%02d ? ", i );
        scanf( "%lx", &instruction );
        
    } // end while

    printf_s( "%s", "*** Program loading completed ***\n" );
} /* end function load */

int validWord( int word ) {
    return word >= -1048575 && word <= 1048575; // FFFFF
} /* end function validWord */