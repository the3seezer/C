/*
theBitRiddler
11/7/2023
2:28 AM
 (Modifications to the Simpletron Simulator)
*/
#include <stdio.h>
#define SIZE 100
#define TRUE 1
#define FALSE 0
#define SENTINEL -99999
#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBSTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

int validWord( int word );
void load( int * loadMemory );
void execute( int * memory, int * acPtr, int * icPtr, int * irPtr, int * opCodePtr, int * opPtr );
void dump( int * memory, int accumulator, int instructionCounter, int instructionRegister, int operationCode, int operand );
int main( void ) {
    int memory[ SIZE ] = { 0 };
    int ac = 0; // accumulator
    int ic = 0; // instruction counter
    int ir = 0; // instruction register
    int opCode = 0; // operation Code
    int operand = 0; // operand

    load( memory );
    execute( memory, &ac, &ic, &ir, &opCode, &operand );
    dump( memory, ac, ic, ir, opCode, operand);

    return 0;
} /* end main */ 

void execute( int * memory, int * acPtr, int * icPtr, int * irPtr, int * opCodePtr, int * opPtr ) {
    printf_s( "%s", "Program execution begins \n");
    int fatal = FALSE; // fatal error flag
    int temp = 0;

    *irPtr = memory[ *icPtr ];
    *opCodePtr = *irPtr / 100;
    *opPtr = *irPtr % 100;

    while ( *opCodePtr != HALT && fatal != TRUE ) {

        switch ( *opCodePtr ) {
            case READ:
                printf_s( "%s", "Enter an integer ");
                scanf( "%d", &temp );

                while ( !validWord( temp ) ) {
                    printf_s( "%s", "Number out of range please enter again ");
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
                    printf_s( "%s", "FATAL ERROR, Accumulator overflow\n"
                                    "Simpletron execution abnormally terminated\n" );
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
                    printf_s( "%s", "FATAL ERROR, Accumulator underflow\n"
                                    "Simpletron execution abnormally terminated\n" );
                    fatal = TRUE;
                } // end if
                else {
                    *acPtr = temp;
                    ++( *icPtr );
                } // end else
                break;
            case DIVIDE:
                if ( memory[ *opPtr ] == 0 ) {
                    printf_s( "%s", "FATAL ERROR, Division by zero\n"  
                                    "Simpletron execution abnormally terminated\n" );
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
                    printf_s( "%s", "FATAL ERROR, Accumulator overflow\n"
                                    "Simpletron execution abnormally terminated\n" );
                    fatal = TRUE;
                } // end if
                else {
                    *acPtr *= memory[ *opPtr ];
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
                printf_s( "%s", "FATAL ERROR, invalid operation Code\n"
                                "Simpletron execution abnormally terminated\n" );
                break;
        } // end switch

         *irPtr = memory[ *icPtr ];
        *opCodePtr = *irPtr / 100;
        *opPtr = *irPtr % 100;   
    } // end while
    printf_s( "%s", "Simpletron execution terminated\n");
} /* end function execute */

void load( int * loadMemory ) {
    printf_s( "%s", "*** Welcome to Simpletron ***\n"
                    "***                                          ***\n"
                    "*** Please enter your program one instruction ***\n"
                    "*** (or data word) at a time. I will type the ***\n"
                    "*** location number and a question mark (?). ***\n"
                    "*** You then type the word for that location. ***\n"
                    "*** Type the sentinel -99999 to stop entering ***\n"
                    "*** your program.                             ***\n" );
    long instruction = 0;
    int i = 0;// indexing variable

    printf_s( "%s", "00 ? ");

    scanf( "%ld", &instruction );

    while ( instruction != SENTINEL ) {

        if ( !validWord( instruction ) ) {
            printf_s( "%s", "Number out of range please enter again ");
        } // end if
        else {
            loadMemory[ i++ ] = instruction;
        } // end else

        printf_s( "%02d ? ", i );
        scanf( "%ld", &instruction );
        
    } // end while

    printf_s( "%s", "Program loading completed\n" );

} /* end function load */

void dump( int * memory, int accumulator, int instructionCounter, int instructionRegister, int operationCode, int operand ) {
    printf_s( "%s\n%-23s%+05d\n%-23s%5.2d\n%-23s%+05d\n%-23s%5.2d\n%-23s%5.2d\n",
     "REGISTERs", "accumulator", accumulator, "instructionCounter", instructionCounter, "instructionRegister", instructionRegister, 
     "operationCode", operationCode, "operand", operand );

     printf_s( "%s\n", "MEMORY" );

     for ( int i = 0; i <= 9; i++ ) {
        printf_s( "%5d ", i );
     } // end for

    for ( size_t i = 0; i < SIZE; i++ ) {

        if ( i % 10 == 0 ) {
            printf_s( "\n%02d ", i );
        } // end if

        printf_s( "%+05d ", memory[ i ] );

    } // end for

    printf_s( "%s", "\n" );
} /* end function dump */

int validWord( int word ) {

    return ( word >= -9999 && word <= 9999 );

} /* end function validWord */