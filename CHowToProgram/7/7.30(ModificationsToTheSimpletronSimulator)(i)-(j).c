/*
theBitRiddler
11/7/2023
2:28 AM
 (Modifications to the Simpletron Simulator)
*/
#include <stdio.h>
#include <math.h>

#define SIZE 1000
#define TRUE 1 
#define FALSE 0
#define SENTINEL -1048575 // -FFFFF
#define READ 10 // A
#define WRITE 11 // B
#define STRIN 12 // C  Input a string
#define STROUT 13 // D Output a string

#define LOAD 20 // 14
#define STORE 21 // 15

#define ADD 30 // 1E
#define SUBSTRACT 31 // 1F
#define DIVIDE 32 // 20
#define MULTIPLY 33 // 21
#define MOD 34 // 22 Remainder instruction
#define POW 35 // 23 Exponentiations
#define NEWL 36 // 24 New line

#define BRANCH 40 // 28
#define BRANCHNEG 41 // 29
#define BRANCHZERO 42 // 2A
#define HALT 43 // 2B

int input( int i, double memory[], int len, char * s );
int output( int i, double memory[] );
int cCount( char * s );
int validWord( double word );
void load( double * loadMemory );
void execute( double * memory, double * acPtr, int * icPtr, int * irPtr, int * opCodePtr, int * opPtr );
void dump( double * memory, double accumulator, int instructionCounter, int instructionRegister, int operationCode, int operand );
int main( void ) {
    double memory[ SIZE ] = { 0 };
    double ac = 0; // accumulator
    int ic = 0; // instruction counter
    int ir = 0; // instruction register
    int opCode = 0; // operation Code
    int operand = 0; // operand

    load( memory );
    execute( memory, &ac, &ic, &ir, &opCode, &operand );
    dump( memory, ac, ic, ir, opCode, operand);

    return 0;
} /* end main */ 

void execute( double * memory, double * acPtr, int * icPtr, int * irPtr, int * opCodePtr, int * opPtr ) {
    printf_s( "%s", "Program execution begins \n");
    int fatal = FALSE; // fatal error flag
    double temp = 0;
    int tempInt = 0;
    char string[ 100 ]; // string to be put in
    int len = 0; // to find the string length 

    *irPtr = memory[ *icPtr ];
    *opCodePtr = *irPtr / 256;
    *opPtr = *irPtr % 256;

    while ( *opCodePtr != HALT && fatal != TRUE ) {

        switch ( *opCodePtr ) {
            case READ:
                printf_s( "%s", "Enter an integer ");
                scanf( "%lf", &temp );

                while ( !validWord( temp ) ) {
                    printf_s( "%s", "Number out of range please enter again ");
                    scanf( "%lf", &temp );
                } // end while
                
                memory[ *opPtr ] = temp;
                ++( *icPtr );
                break;
            case WRITE:
                printf_s( "Content is %10.3lf\n", memory[ *opPtr ] );
                ++( *icPtr );
                break;
            case STRIN:
                puts( "Enter a string ");
                gets( string );
                len = cCount( string );
                input( *opPtr, memory, len, string );
                *icPtr = 1.5 + ( len - 1 ) / 2;
                break;
            case STROUT:
                len = output( *opPtr, memory );
                *icPtr = 1.5 + ( len - 1 ) / 2;
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
                    *acPtr = temp;
                    ++( *icPtr );
                } // end else
                break;
            case MOD:
                tempInt = ( int ) *acPtr;
                tempInt %= ( int ) memory[ *opPtr ];
                *acPtr = ( double ) tempInt;
                ++( *icPtr );
                break;
            case POW:
                temp = pow( *acPtr, memory[ *opPtr ] );
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
            case NEWL:
                printf_s( "%s", "\n" );
                ++( *icPtr );
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
        *opCodePtr = *irPtr / 256;
        *opPtr = *irPtr % 256;   
    } // end while
    printf_s( "%s", "Simpletron execution terminated\n");
} /* end function execute */

int output( int i, double memory[] ) {
    int len = 0;
    int lenth = 0; // To return 
    int temp = 0;

    len = memory[ i ] / 1000;
    lenth = len;

    temp = ( int ) memory[ i ] % 1000;
    putchar( ( char ) temp );

    i++; len--; // move to the other location and reduce the string length

    // Output the characters
    while( len ) {
        temp = ( int ) memory[ i ] / 1000;
        if ( ( char ) temp != '\0' ) {
            putchar( ( char ) temp );
            len--;
        } // end if
        temp = ( int ) memory[ i ] % 1000; 
        if ( ( char ) temp != '\0' ) {
            putchar( ( char ) temp );
            len--;
        } // end if
        i++;
    } // end len
    return lenth;
} /* end function output */

int cCount( char * s ) {
    int x = 0;
    for ( x = 0; *s != '\0'; s++ ) {
        ++x;
    } // end for
    return x;
} /* end function cCount */

int input( int i, double memory[], int len, char * s ) {

    memory[ i ] = len * 1000; // introduce the size of the string
    memory[ i ] += ( int ) * s;
    s++; len--; i++; // move to the other location of pointer, reduce the string length and move to the other location

    for ( ; len ; i++ ) {
        if ( *s != '\0' ) {
            memory[ i ] = 1000 * ( int ) * s;
            s++; len--;
        } // end if
        if ( *s != '\0' ) {
            memory[ i ] += ( int ) * s;
            s++; len--;
        } // end if  
    } // end while
    return 0;
} /* end function input */

void load( double * loadMemory ) {
    printf_s( "%s", "***         Welcome to Simpletron             ***\n"
                    "***                                           ***\n"
                    "*** Please enter your program one instruction ***\n"
                    "*** (or data word) at a time. I will type the ***\n"
                    "*** location number and a question mark (?).  ***\n"
                    "*** You then type the word for that location. ***\n"
                    "*** Type the sentinel -FFFFF to stop entering ***\n"
                    "*** your program.                             ***\n" );
    long instruction = 0;
    int i = 0;// indexing variable

    printf_s( "%s", "00 ? ");

    scanf( "%lx", &instruction );

    while ( instruction != SENTINEL ) {

        if ( !validWord( instruction ) ) {
            printf_s( "%s", "Number out of range please enter again \n");
        } // end if
        else {
            loadMemory[ i++ ] = instruction;
        } // end else

        printf_s( "%02d ? ", i );
        scanf( "%lx", &instruction );
        
    } // end while

    printf_s( "%s", "Program loading completed\n" );

} /* end function load */

void dump( double * memory, double accumulator, int instructionCounter, int instructionRegister, int operationCode, int operand ) {
    printf_s( "%s\n%-23s%+010.3lf\n%-23s%10.3d\n%-23s%+010d\n%-23s%10.2d\n%-23s%10.2d\n",
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

        printf_s( "%+010.3lf ", memory[ i ] );

    } // end for

    printf_s( "%s", "\n" );
} /* end function dump */

int validWord( double word ) {

    return ( word >= -65535 && word <= 65535 );

} /* end function validWord */