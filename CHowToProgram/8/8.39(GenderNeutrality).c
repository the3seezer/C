/*
    theBitRiddler
    3/23/2024
    5:08 PM
    8.39 (Gender Neutrality) 
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define WORDS 53
#define SIZE 200
#define OUT 300

enum Status {
    FOUND, UNFOUND
};

int	main(void) {
    const char * gender[WORDS][3] = {
        {"Actor", "Actress", ""},
        {"Boy", "girl", ""}, {"boy", "girl", ""}, {"Boyfriend", "girlfriend", ""}, {"Boyfriend", "girlfriend", ""},
        {"Businessman", "", ""}, {"Businessman", "", ""},
        {"Chairman", "chairwoman", ""}, {"Chairman", "chairwoman", ""},
        {"Congressman", "", ""}, {"congressmen", "", ""},
        {"councilman", "councilwoman", ""},
        {"Dear Sir", "", ""},
        {"Dude", "", ""}, {"Dude", "", ""},
        {"Fireman", "", ""}, {"Foreman", "", ""},
        {"Freshman", "", ""},
        {"Granddaughter", "Grandson", ""},
        {"Grandma", "grandpa", ""},
        {"Husband", "wife", ""},
        {"Kinsmen", "", ""}, 
        {"Ladies and gentlemen", "ladies", "gentlemen"}, {"everybody", "guys", "ladies"}, {"Ladies and gentlemen", "", ""}, 
        {"Maiden name", "", ""}, 
        {"Maid", "", ""}, {"Mailman", "", ""}, {"Mailman", "", ""},
        {"men", "women", ""},
        {"Man", "woman", "" }, {"Man", "woman", "" }, {"Man up", "", ""},
        {"Mankind", "", ""},
        {"Man-made", "", ""}, {"Man-made", "", ""}, {"Man-made", "", ""}, 
        {"Manned", "", ""}, {"Manpower", "", ""}, {"Manpower", "", ""},
        {"Mother", "father", ""}, {"mother", "father", ""},
        {"niece", "nephew", ""},
        {"Policeman", "", ""},
        {"Salesman", "", ""}, {"salesman", "saleswoman", ""},
        {"Sister", "brother", ""}, {"son", "daughter", ""},
        {"Stewardess", "steward", ""},
        {"The common man", "", ""},
        {"Upperclassman", "", ""},
        {"Waiter", "waitress", ""}, {"wife", "husband", ""}    
    };
    const char * neutral[WORDS] = {
        "Performer",
        "Child", "Kiddo", "Partner", "significant other",
        "Businessperson", "business representative",
        "Chairperson", "chair",
        "Legislator", "Members of Congress",
        "Councilperson",
        "Dear",
        "Friend", "person",
        "Firefighter", "Foreperson",
        "First-year student",
        "Grandchild",
        "Grandparent",
        "Spouse",
        "Relatives", 
        "Folks", "folx", "everyone", 
        "Family name",
        "Housekeeper", "Letter carrier" , "postal worker",
        "People",
        "Person", "adult", "Toughen up",
        "Humankind", 
        "Synthetic", "Machine-made", "artificial",
        "Crewed", "Workforce", "workers",
        "Parent", "pibling",
        "Nibling",
        "Police officer",
        "Salesperson", "sales representative",
        "Sibling", "Child",
        "Flight attendant",
        "The average person",
        "Third-year or above",
        "Server", "spouse" 
    };
    char state[SIZE] = "";  // statement input by user
    char subMessage[50] = "";
    char message[OUT] = "";
    char subUnfound[50] = "";
    char unfound[150] = "";
    char unfoundCpy[150] = "";
    char wordTemp[50] = "";
    char wordTemp2[50] = "";
    char * tokenPtr = "";
    enum Status WordStatus = UNFOUND;
    enum Status UnknownWordStatus = UNFOUND;

    // enter your statement
    printf( "%s", "Enter your statement: " );
    gets(state);

    // Convert the statement to small letters
    for ( size_t i = 0; state[i] != '\0'; i++ ) {
        state[i] = tolower( state[i]);
    } // end for

    tokenPtr = strtok( state, " " );

    while( tokenPtr != NULL ) {
        WordStatus = UNFOUND;

        // Search for gender specific words
        for ( size_t i = 0; i < WORDS; i++ ) {
            for ( size_t j = 0; j < 3; j++ ) {
                // get the gender specific word
                strcpy( wordTemp, gender[i][j] );
                // convert to lowercase
                for ( size_t i = 0; wordTemp[i] != '\0'; i++ ) {
                    wordTemp[i] = tolower( wordTemp[i]);
                } // end for

                // look for the compound word joined with the token.
                // copy the unfound string
                strcpy( unfoundCpy, unfound );
                // concatenate it with the token
                strcat( unfoundCpy, tokenPtr );

                if (  (strcmp( unfoundCpy, wordTemp ) == 0 && WordStatus == UNFOUND) || ( strstr( unfoundCpy, wordTemp ) != NULL && ispunct( unfoundCpy[strlen(wordTemp)] ) && WordStatus == UNFOUND ) ) {
                    // add a gender neutral word to subMessage
                    sprintf( subMessage, "%s%c", neutral[i], ispunct( unfoundCpy[strlen(wordTemp)] ) ? unfoundCpy[strlen(wordTemp)] : ' ' );
                    // concatenate the subMessage to the Output message
                    strcat( message, subMessage );
                    memset( subMessage, '\0', strlen( subMessage ) ); // clean the subMessage
                    WordStatus = FOUND;
                    // clear the unfound string and prepare for the next unfound string
                    memset( unfound, '\0', 150 );
                    UnknownWordStatus = UNFOUND;
                } // end if
                if ( (strcmp( tokenPtr, wordTemp ) == 0 && WordStatus == UNFOUND) || ( strstr(tokenPtr, wordTemp ) != NULL && ispunct( tokenPtr[strlen(wordTemp)] ) && WordStatus == UNFOUND ) ) { // if they are found

                    if ( UnknownWordStatus == FOUND ) {
                        // start identifying the unfound string in the gender specific words
                        for ( size_t i = 0; i < WORDS; i++ ) {
                            for ( size_t j = 0; j < 3; j++ ) {
                                // get the gender specific word
                                strcpy( wordTemp2, gender[i][j] );
                                // convert to lowercase
                                for ( size_t i = 0; wordTemp2[i] != '\0'; i++ ) {
                                    wordTemp2[i] = tolower( wordTemp2[i]);
                                } // end for
                                // Find the compound words in the gender specific list
                                if ( strstr( unfound, wordTemp2 ) != NULL && ( ispunct( unfound[strlen(wordTemp2)]) || isblank( strlen(wordTemp2) ) ) ) { // if the compound words are found
                                    // add a gender neutral word to subMessage
                                    sprintf( subMessage, "%s%c", neutral[i], tokenPtr[strlen(wordTemp2)] );
                                    // concatenate the subMessage to the Output message
                                    strcat( message, subMessage );
                                    memset( subMessage, '\0', strlen( subMessage ) ); // clean the subMessage
                                    WordStatus = FOUND;
                                } // end if
                            } // end for
                        } // end for

                        if ( WordStatus == UNFOUND ) { // if they are unfound
                            // concatenate the unfound string to the message
                            strcat( message, unfound );
                        } // end if
                        
                        // clear the unfound string and prepare for the next unfound string
                        memset( unfound, '\0', 150 );
                        UnknownWordStatus = UNFOUND;
                    } // end if 
                    
                    // add a gender neutral word to subMessage
                    sprintf( subMessage, "%s%c", neutral[i], ispunct( tokenPtr[strlen(wordTemp)] ) ? tokenPtr[strlen(wordTemp)] : ' ' );
                    // concatenate the subMessage to the Output message
                    strcat( message, subMessage );
                    memset( subMessage, '\0', strlen( subMessage ) ); // clean the subMessage
                    WordStatus = FOUND;
                } // end if
            } // end for
        } // end for

        // if a token is unfound get it into the subUnfound string
        if ( WordStatus == UNFOUND ) {
            sprintf( subUnfound, "%s ", tokenPtr );
            // concatenate it to unfound string
            strcat( unfound, subUnfound );
            memset( subUnfound, '\0', strlen( subUnfound ) ); // clean the subUnfound
            UnknownWordStatus = FOUND;
        } // end if

        tokenPtr = strtok( NULL, " ");
    } // end while

    // if unfound is still having values
    if ( *unfound != '\0' ) {
        strcat( message, unfound );
    } // end if

    // display the results
    printf( "%s", message );

    return 0; // indicate successful termination
} /* end main */