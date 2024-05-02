/*
    theBitRiddler
    3/23/2024
    5:08 PM
    8.39 (Gender Neutrality) 
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define WORDS 61
#define COMPOUND 10
#define SIZE 200
#define OUT 300

enum Status {
    FOUND, UNFOUND
};

char * tokenNeutralize( char *, const char * [][3], const char * [], char * );
char * compNeutralize( char *, const char * [], const char * [], char * );
int compare( char *, const char *, char[] );
void toLowercase( char * );
void format( char * );

int	main(void) {
    const char * gender[WORDS][3] = {
        {"Actor", "Actress", ""},
        {"Boys", "girls", ""}, {"boy", "girl", ""}, {"boy", "girl", ""}, {"Boyfriend", "girlfriend", ""}, {"Boyfriend", "girlfriend", ""},
        {"Businessman", "", ""}, {"Businessman", "", ""}, {"Businessmen", "", ""},
        {"Chairman", "chairwoman", ""}, {"Chairman", "chairwoman", ""}, {"Chairmen", "chairwomen", ""},
        {"Congressman", "", ""}, {"congressmen", "", ""},
        {"councilman", "councilwoman", ""}, {"councilmen", "councilwomen", ""},
        {"Sir", "", ""},
        {"Dude", "", ""}, {"Dude", "", ""},
        {"Fireman", "", ""}, {"Firemen", "", ""}, {"Foreman", "", ""}, {"Foremen", "", ""},
        {"Freshman", "", ""}, {"Freshmen", "", ""},
        {"Granddaughter", "Grandson", ""},
        {"Grandma", "grandpa", ""},
        {"Husband", "wife", ""},
        {"Kinsmen", "", ""}, 
        {"Ladies", "Gentlemen", ""}, {"everybody", "guys", ""},   
        {"Maid", "", ""}, {"Mailman", "", ""}, {"Mailman", "", ""}, {"Mailmen", "", ""},
        {"men", "women", ""},
        {"Man", "woman", "" }, {"Man", "woman", "" }, 
        {"Mankind", "", ""},
        {"Man-made", "", ""}, {"Man-made", "", ""}, {"Man-made", "", ""}, 
        {"Manned", "", ""}, {"Manpower", "", ""}, {"Manpower", "", ""},
        {"Mother", "father", ""}, {"mother", "father", ""},
        {"niece", "nephew", ""},
        {"Policeman", "", ""}, {"policemen", "", ""},
        {"Salesman", "", ""}, {"salesman", "saleswoman", ""}, {"salesmen", "saleswomen", ""},
        {"Sister", "brother", ""}, {"sons", "daughters", ""}, {"son", "daughter", ""},
        {"Stewardess", "steward", ""}, 
        {"Upperclassman", "", ""}, {"Upperclassmen", "", ""},
        {"Waiter", "waitress", ""}, {"wives", "", ""}    
    };
    const char * compGender[COMPOUND] = {
        "boys and girls", "common man", "common men",
        "Dear Sir", "Ladies and Gentlemen", "Maiden name", "Man up",
        "man and woman", "men and women", "sons and daughters"
    };
    const char * neutral[WORDS] = {
        "Performer",
        "Children", "Kiddo", "child", "Partner", "significant other",
        "Businessperson", "business representative", "Businesspeople",
        "Chairperson", "chair", "chairpeople",
        "Legislator", "Members of Congress",
        "Councilperson", "councilpeople",
        "Dear",
        "Friend", "person",
        "Firefighter", "firefighters", "Foreperson", "forepeople",
        "First-year student", "first-year students",
        "Grandchild",
        "Grandparent",
        "Spouse",
        "Relatives", 
        "Folks", "folx",  
        "Housekeeper", "Letter carrier" , "postal worker", "letter carriers",
        "People",
        "Person", "adult", 
        "Humankind", 
        "Synthetic", "Machine-made", "artificial",
        "Crewed", "Workforce", "workers",
        "Parent", "pibling",
        "Nibling",
        "Police officer", "police officers",
        "Salesperson", "sales representative", "salespeople",
        "Sibling", "Children", "child",
        "Flight attendant",
        "Third-year or above", "Third-years or above",
        "Server", "spouses" 
    };
    const char * compNeutral[COMPOUND] = {
        "children", "average person", "average people",
        "Dear", "everyone", "Family name", "Toughen up",
        "person", "people", "children" 
    };
    char state[SIZE] = "";  // statement input by user
    char statement[OUT] = "";
    char message[OUT] = ""; // statement output by program
    char * tokenPtr = "";   // token pointer

    // enter your statement
    printf( "%s", "Enter your statement: " );
    gets(state);

    // Replacement neutralizing way for compound gender specific words
    compNeutralize( state, compGender, compNeutral, statement );

    // token neutralizing way for non-compound gender specific words
    tokenPtr = strtok( statement, " " );

    while( tokenPtr != NULL ) {
        // neutralize the token if possible
        tokenNeutralize( tokenPtr, gender, neutral, message );

        tokenPtr = strtok( NULL, " ");
    } // end while

    // format your content
    format( message );

    // display the results
    printf( "%s", message );

    return 0; // indicate successful termination
} /* end main */

void format( char * message ) {
    enum Status Fullstop = FOUND;
    // convert to lowercase
    toLowercase( message );
    
    // Convert the first letter in each sentense to uppercase
    for ( size_t i = 0; message[i] != '\0'; i++ ) {
        
        if ( message[i] == 46 ) {
            Fullstop = FOUND;
        } // end if
        
        if ( isalpha( message[i] ) && Fullstop == FOUND ) {
            message[i] = toupper( message[i] );
            Fullstop = UNFOUND;
        } // end if
    } // end for

} /* end function format */
char * compNeutralize( char * comment, const char * specific[], const char * neutral[], char * message ) {
    char * specificPtr = ""; // pointer of a gender specific word at the comment 
    char specificTemp[50] = ""; // gender specific template
    char preComment[SIZE] = ""; // words before the given gender specific word
    enum Status SpecificStatus = UNFOUND;
    // convert comment to lowercase
    toLowercase( comment );

    // loop through compound gender specific words
    for ( size_t i = 0; i < COMPOUND; i++ ) {
        // copy a gender specific word to a template
        strcpy( specificTemp, specific[i] );
        // convert the template to lowercase
        toLowercase( specificTemp );

        // search and replace
        if ( ( specificPtr = strstr( comment, specificTemp ) ) != NULL ) { // if a gender specific word is found
            SpecificStatus = FOUND;
            // get a preComment
            int j = 0; // location controller
            while ( comment < specificPtr ) {
                preComment[j] = *comment;
                // increment both preComment and the comment
                j++; comment++;
            } // end while
            // concatenate the preComment to message
            strcat( message, preComment );

            // concatenate the gender neutral word
            strcat( message, neutral[i] );

            // get a postComment
            j = strlen( specificTemp ); // use the specificTemp size to get the exact location
            while ( j ) {
                comment++;
                j--;
            } // end while
            // concatenate the postComment to message
            strcat( message, comment );

        } // end if
    } // end for

    if ( SpecificStatus == FOUND )
        return message;
    else {
        strcpy( message, comment );
        return message;
    } // end else
} /* end function compNeutralize */

char * tokenNeutralize( char * token, const char * specific[][3], const char * neutral[], char * message ) {
    char punct[50] = ""; // punctuations collector

    // loop through gender specific array to compare with the words
    for ( size_t i = 0; i < WORDS; i++ ) {
        for ( size_t j = 0; j < 3 && *specific[i][j] != '\0'; j++ ) {
            // search and neutralize if possible
            if ( compare( token, specific[i][j], punct ) ) { 
                // neutralize
                strcat( message, " " );
                strcat( message, neutral[i] );
                if ( punct[0] != '\0' ) {
                    strcat( message, punct );
                } // end if
                return message;  // terminate 
            } // end if
        } // end for
    } // end for

    // unfound
    strcat( message, " " );
    strcat( message, token );
    return message;

} /* end function tokenNeutralize */

int compare( char * words, const char * specific, char punct[] ) {
    char specificTemp[50] = ""; // a template for specific since specific is constant
    enum Status ComparisonStatus = UNFOUND;
    enum Status EsStatus = UNFOUND;

    strcpy( specificTemp, specific );

    // turn words and specificTemp to lowercase
    toLowercase( words );
    toLowercase( specificTemp );

    // if it's a straight match
    if ( strcmp( words, specificTemp ) == 0 ) {
        return 1;
    } // end if
    else if ( strstr( words, specificTemp ) != NULL ) { // find punctuations and prular signs
        for ( size_t i = strlen(specificTemp); words[i] != '\0'; i++ ) {
            
            if ( ispunct( words[i]) || words[i] == 's' || ( words[i] == 'e' && words[i + 1] == 's') ) {
                if ( words[i] == 'e' && words[i + 1] == 's') {
                    strcat( punct, "s" );
                    EsStatus = FOUND;
                } // end if
                else if( words[i] == 's' && EsStatus == UNFOUND ) {
                    strncat( punct, &words[i], 1 );
                } // end if
                else if ( ispunct( words[i] ) ) {
                    strncat( punct, &words[i], 1 );
                } // end else if

                ComparisonStatus = FOUND;
            } // end if
            else {
                return 0;
            } // end else
        } // end for 
    } // end else if

    if ( ComparisonStatus == FOUND )
        return 1;

    return 0; // if word was never found
} /* end function compare */

void toLowercase( char * words ) {
    for ( size_t i = 0; words[i] != '\0'; i++ ) {
        // turn each letter to lowercase
        words[i] = tolower( words[i] );
    } // end for
} /* end function toLowercase */