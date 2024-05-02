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

char * neutralize( char *, const char * [][3], const char * [], char * );
int compare( char *, const char *, char[] );

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
        {"Ladies", "Gentlemen", ""}, {"everybody", "guys", ""}, {"Ladies and Gentlemen", "", ""}, 
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
    char message[OUT] = ""; // statement output by program
    char * tokenPtr = "";   // token pointer

    // enter your statement
    printf( "%s", "Enter your statement: " );
    gets(state);

    tokenPtr = strtok( state, " " );

    while( tokenPtr != NULL ) {
        // neutralize the token if possible
        neutralize( tokenPtr, gender, neutral, message );

        tokenPtr = strtok( NULL, " ");
    } // end while

    // display the results
    printf( "%s", message );

    return 0; // indicate successful termination
} /* end main */

char * neutralize( char * token, const char * specific[][3], const char * neutral[], char * message ) {
    char punct[50] = ""; // punctuations collector
    enum Status UnkownWord = UNFOUND;  // if unkown word isn't found

    // loop through gender specific array to compare with the words
    for ( size_t i = 0; i < WORDS; i++ ) {
        for ( size_t j = 0; j < 3 && *specific[i][j] != '\0'; j++ ) {
            // search and neutralize if possible
            if ( compare( token, specific[i][j], punct ) ) { // if it's just a token 
                // neutralize
                strcat( message, " " );
                strcat( message, neutral[i] );
                // clear the compound words
                return message;  // terminate 
            } // end if
            else {
                // collect the words unknown to compound 
                if ( UnkownWord == UNFOUND ) { 
                    UnkownWord = FOUND;
                } // end if
            } // end else
        } // end for
    } // end for

    // if unkown word is found
    if ( UnkownWord == FOUND ) {
        strcat( message, " " );
        strcat( message, token );
        return message;
    } // end if

} /* end function neutralize */

int compare( char * words, const char * specific, char punct[50] ) {
    char specificTemp[50] = "";
    strcpy( specificTemp, specific );

    for ( size_t i = 0; words[i] != '\0' || specificTemp[i] != '\0'; i++ ) {
        // turn each letter to lowercase
        words[i] = tolower( words[i]);
        specificTemp[i] = tolower( specificTemp[i] );
    } // end for

    // if it's a straight match
    if ( strcmp( words, specificTemp ) == 0 ) {
        return 1;
    } // end if

    return 0; // if word was never found
} /* end function compare */