 /* Exercise 7.19 Solution */
 #include <stdio.h>

 /* define commands */
 #define SIZE 100
 #define SENTINEL -99999
 #define TRUE 1
 #define FALSE 0
 #define READ 10
 #define WRITE 11
 #define LOAD 20
 #define STORE 21
 #define ADD 30
 #define SUBTRACT 31
 #define DIVIDE 32
 #define MULTIPLY 33
 #define BRANCH 40
 #define BRANCHNEG 41
 #define BRANCHZERO 42
 #define HALT 43

 /* function prototypes */
 void load( int *loadMemory );
 void execute( int *memory, int *acPtr, int *icPtr, int *irPtr,
 int *opCodePtr, int *opPtr );
 void dump( int *memory, int accumulator, int instructionCounter,
 int instructionRegister, int operationCode,
 int operand );
 int validWord( int word );

 int main()
 { 
 int memory[ SIZE ]; /* define memory array */
 int ac = 0; /* accumulator */
 int ic = 0; /* instruction counter */
 int opCode = 0; /* operation code */
 int op = 0; /* operand */
 int ir = 0; /* instruction register */
 int i; 
  /* clear memory */
 for ( i = 0; i < SIZE; i++ ) {
 memory[ i ] = 0;
 } /* end for */
 
 load( memory ); 
 execute( memory, &ac, &ic, &ir, &opCode, &op ); 
 dump( memory, ac, ic, ir, opCode, op );

 return 0; /* indicate successful termination */

 } /* end main */

 /* function loads instructions */
 void load( int *loadMemory )
 { 
 long int instruction; /* current instruction */
 int i = 0; /* indexing variable */

 printf( "%s\n\n%s\n%s\n%s\n%s\n%s\n%s\n\n", 
 "*** Welcome to Simpletron ***",
 "*** Please enter your program one instruction ***",
 "*** ( or data word ) at a time. I will type the ***",
 "*** location number and a question mark ( ? ). ***",
 "*** You then type the word for that location. ***",
 "*** Type the sentinel -99999 to stop entering ***",
 "*** your program. ***" );
 
 printf( "00 ? " );
 scanf( "%ld", &instruction ); /* read instruction */
 
 /* while sentinel is not read from user */
 while ( instruction != SENTINEL ) { 

 /* test instruction for validity */
 if ( !validWord( instruction ) ) {
 printf( "Number out of range. Please enter again.\n" );
 } /* end if */
 else { /* load instruction */
 loadMemory[ i++ ] = instruction;
 } /* end else */

 printf( "%02d ? ", i );
 scanf( "%ld", &instruction );
 } /* end while */

 } /* end function load */

 /* carry out the commands */
 void execute( int *memory, int *acPtr, int *icPtr, int *irPtr,
 int *opCodePtr, int *opPtr )
 { 
 int fatal = FALSE; /* fatal error flag */
 int temp; /* temporary holding space */

 printf( "\n************START SIMPLETRON EXECUTION************\n\n" );

 /* separate operation code and operand */
 *irPtr = memory[ *icPtr ];
 *opCodePtr = *irPtr / 100;
 *opPtr = *irPtr % 100;
 /* loop while command is not HALT or fatal */
 while ( *opCodePtr != HALT && !fatal ) { 
 
 /* determine appropriate action */
 switch ( *opCodePtr ) { 

 /* read data into location in memory */
 case READ:
 printf( "Enter an integer: " );
 scanf( "%d", &temp );
 
 /* check for validity */
 while ( !validWord( temp ) ) { 
 printf( "Number out of range. Please enter again: " );
 scanf( "%d", &temp );
 } /* end while */
 
 memory[ *opPtr ] = temp; /* write to memory */
 ++( *icPtr );
 break; /* exit switch */

 /* write data from memory to screen */
 case WRITE:
 printf( "Contents of %02d: %d\n", *opPtr, memory[ *opPtr ] );
 ++( *icPtr );
 break; /* exit switch */

 /* load data from memory into accumulator */
 case LOAD:
 *acPtr = memory[ *opPtr ];
 ++( *icPtr );
 break; /* exit switch */

 /* store data from accumulator into memory */
 case STORE:
 memory[ *opPtr ] = *acPtr;
 ++( *icPtr );
 break; /* exit switch */

 /* add data from memory to data in accumulator */
 case ADD:
 temp = *acPtr + memory[ *opPtr ];
 
 /* check validity */
 if ( !validWord( temp ) ) { 
 printf( "*** FATAL ERROR: Accumulator overflow ***\n" );
 printf( "*** Simpletron execution abnormally terminated ***\n" );
 fatal = TRUE;
 } /* end if */
 else { 
 *acPtr = temp;
 ++( *icPtr );
 } /* end else */
 
 break; /* exit switch */

 /* subtract data in memory from data in accumulator */
 case SUBTRACT:
 temp = *acPtr - memory[ *opPtr ];
 /* check validity */
 if ( !validWord( temp ) ) { 
 printf( "*** FATAL ERROR: Accumulator overflow ***\n" );
 printf( "*** Simpletron execution abnormally terminated ***\n" );
 fatal = TRUE;
 } /* end if */
 else { 
 *acPtr = temp;
 ++( *icPtr );
 } /* end else */
 
 break; /* exit switch */

 /* divide data in memory into data in accumulator */
 case DIVIDE:

 /* check for divide by zero error */
 if ( memory[ *opPtr ] == 0 ) { 
 printf( "*** FATAL ERROR: Attempt to divide by zero ***\n" );
 printf( "*** Simpletron execution abnormally terminated ***\n" );
 fatal = TRUE;
 } /* end if */
 else { 
 *acPtr /= memory[ *opPtr ];
 ++( *icPtr );
 } /* end else */
 
 break; /* exit switch */

 /* multiple data in memory by data in accumulator */
 case MULTIPLY:
 temp = *acPtr * memory[ *opPtr ];
 
 /* check validity */
 if ( !validWord( temp ) ) { 
 printf( "*** FATAL ERROR: Accumulator overflow ***\n" );
 printf( "*** Simpletron execution abnormally terminated ***\n" );
 fatal = TRUE;
 } /* end if */
 else { 
 *acPtr = temp;
 ++( *icPtr );
 } /* end else */

 break; /* exit switch */

 /* branch to specific location in memory */
 case BRANCH:
 *icPtr = *opPtr;
 break; /* exit switch */

 /* branch to location in memory if accumulator is negative */
 case BRANCHNEG:

 /* if accumulator is negative */
 if ( *acPtr < 0 ) {
 *icPtr = *opPtr;
 } /* end if */
 else {
 ++( *icPtr );
 } /* end else */
 break; /* exit switch */

 /* branch to location in memory if accumulator is zero */
 case BRANCHZERO:

 /* if accumulator is zero */
 if ( *acPtr == 0 ) {
 *icPtr = *opPtr;
 } /* end if */
 else {
 ++( *icPtr );
 } /* end else */

 break; /* exit switch */

 default:
 printf( "*** FATAL ERROR: Invalid opcode detected ***\n" );
 printf( "*** Simpletron execution abnormally terminated ***\n" );
 fatal = TRUE; 
 break; /* exit switch */ 
 } /* end switch */
 
 /* separate next operation code and operand */
 *irPtr = memory[ *icPtr ];
 *opCodePtr = *irPtr / 100;
 *opPtr = *irPtr % 100;
 } /* end while */

 printf( "\n*************END SIMPLETRON EXECUTION*************\n" );
 } /* end function execute */

 /* print out name and content of each register and memory */
 void dump( int *memory, int accumulator, int instructionCounter,
 int instructionRegister, int operationCode,
 int operand )
 { 
 int i; /* counter */
 
 printf( "\n%s\n%-23s%+05d\n%-23s%5.2d\n%-23s%+05d\n%-23s%5.2d\n%-23s%5.2d",
 "REGISTERS:", "accumulator", accumulator, "instructioncounter",
 instructionCounter, "instructionregister", instructionRegister,
 "operationcode", operationCode, "operand", operand );

 printf( "\n\nMEMORY:\n " );
 
 /* print column headers */
 for ( i = 0; i <= 9; i++ ) {
 printf( "%5d ", i );
 } /* end for */
 
 /* print row headers and memory contents */
 for ( i = 0; i < SIZE; i++ ) { 

 /* print in increments of 10 */
 if ( i % 10 == 0 ) {
 printf( "\n%2d ", i );
 } /* end if */
 
 printf( "%+05d ", memory[ i ] );
 } /* end for */
 
 printf( "\n" );
 } /* end function dump */

 /* function tests validity of word */
 int validWord( int word )
 { 
 return word >= -9999 && word <= 9999;

 } /* end function validWord */