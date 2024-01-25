#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main( void ) {
    char p[20] = "";                // complete phone number
    char phoneNumber[10] = { '\0' };      // long integer phone number
    char * tokenPtr = NULL;         // store temporary token pointer
    int areaCode = 0;               // store area code
    int phone = 0;                  // store phone number

    printf( "%s\n", "Enter a phone number in form "
                "( 555 ) 555-5555 " );
    
    gets(p);

    areaCode = atoi( strtok( p, "()" ) ); // convert and store areaCode

    // take the next token and copy it to phoneNumber
    tokenPtr = strtok( NULL, " -" );
    strcpy( phoneNumber, tokenPtr );

    // take the other token and concatenate it to phoneNumber
    tokenPtr = strtok( NULL, "" );
    strcat( phoneNumber, tokenPtr );

    // convert the phoneNumber and store it to phone
    phone = atoi( phoneNumber );

    printf( "%s%d\n", "The integer area code is: ", areaCode );
    printf( "%s%d\n", "The long integer phone number is: ", phone );

    return 0; // indicate termination successful
} /* end main */