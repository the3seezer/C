/*
    theBitRiddler
    1/24/2024
    10:52 PM
    Telephone number tokening
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main( void ) {
    char telephone[20] = ""; // telephone input by user
    char * firstToken = ""; // first token pointer, ...
    char * secondToken = ""; // second token pointer
    char * thirdToken = ""; // third token pointer
    int code = 0; // code number
    int number = 0; // the rest of the number

    printf( "%s\n", "Enter a telephone number in form of (555) 555-5555 : " );
    gets( telephone );
    printf( "%s\n", "The phone is : " );

    // get the tokens
    firstToken = strtok( telephone, " ()-" );
    secondToken = strtok( NULL, " ()-" );
    thirdToken = strtok( NULL, " ()-" );

    strcat( secondToken, thirdToken ); // Concatenate the third to the second token

    // convert the token numbers to integers
    code = atoi( firstToken );
    number = atoi( secondToken );

    // print the numbers
    printf( "%d%d\n", code, number );
    return 0; // indicate termination successful
}