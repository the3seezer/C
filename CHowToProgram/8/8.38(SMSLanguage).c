/*
    theBitRiddler
    3/6/2024
    9:41 PM
    SMS Language
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 160
#define LONG 3200
#define WORDS 190

enum Status {
    FOUND, UNFOUND, MANY, ANTIPUNCT, PUNCT, UNCHOSEN, SPACE, NOSPACE, MOSPACE,
    FULLSTOP, NORMAL
};

void sToL( char *, const char * [], const char *[][3], char * ); // short to long converter
void lToS( char *, const char * [], const char *[][3], char * ); // long to short converter
void (* method[2] )( char *, const char * [], const char *[][3], char * ) = { sToL, lToS }; // The pointer to our functions

int main(void) {
    const char * SMSWords[WORDS] = {
        "&", "=", ">", "<", "#", "x", "/", "@",
        "404", "401k",
        "Acct", "Ad", "AFAIK", "Approx", "APR", "ASAP", 
        "b/c", "B2B", "B4", "B4N", 
        "BA", "BBL", "BBS", "bkgd",
        "BRB", "BS", "BTW", "btwn", 
        "C","C&B", "C&S",
        "CEO", "CC", "cf", "CFO", "Co.", "COO", "COOP", "Corp.",
        "cp",
        "CRM", "CSR", "ct", "CTO",
        "CU", "CUL8R", "CYT", 
        "Dept.", "DIV", 
        "e.g.", "EST", "ESP",
        "EOD", "ea", "Ea.", "EOM", "EOT", "EOY", "ERP",
        "f", "FAQ", "F2F", 
        "FWD", "FWIW", "FYI", 
        "G2G", "GDP", "govt", "Govt.",
        "hv", "HAND", 
        "HR", "HQ", "i.e.",
        "IAM", "IC", "IDC", "IDK", "IM",
        "IMO", "IMHO", "Inc.", "IRL", "ISO", "IT", "J/K", 
        "JK", "Jr.", "KISS", "KPI", "KRA", "L&D",  
        "L8", "L8R", "Lb.", "LLC", "LMAO", "LMK", 
        "LOL", "NP", "NRN", "OIC", 
        "OJT", "OLT", "OMG", "OMW",
        "OTP", "MTD",
        "Max", "MBA", "MBO", "Memo", "Mfg", "min", "Min.", "Mo", "mpt",
        "N.B.", "No", "NSFW", "NWR",
        "p",
        "P&L", "PDF", "Pkg", "PLS", "PLZ", 
        "PM", "PMO", "PO", "POS", "PR",
        "prob", "probs", "PTO",
        "q", "R&D",
        "Q1", "Q2", "Q3", "Q4", 
        "QA", "QoS", "QTY", 
        "RACI", "re:", "Re", "Recd.", "RFP", 
        "ROFL", "ROI", "ROTFL", "ROWE",
        "s/o", "s/t", "SMART", "SNS", "SOHO", "SOOB",
        "STAT", "SWOT",
        "Temp", "tho", "thro",
        "THX", "TMI", "TTYL", "TTYS", 
        "U", "vs",
        "VC", "VLE", "VP", "VPN", "VW", "VWVW",
        "WAH", "WBT", "WIIFM",
        "WFH", "W/", "w/i", "W/O",
        "WB", "WBU", "wrt",
        "YW", "Yr.", "yrs", "YTD" 
    };
    const char * SMSTranslations[WORDS][3] = {
        {"and", "", ""}, {"is", "are", ""}, {"more than", "", ""}, {"less than", "", ""}, {"number", "", ""}, {"times", "", ""}, {"/", "", ""}, {"at", "", ""},
        {"error 404 - not found", "lost", "confused"}, {"US retirement savings plan", "", ""},
        {"account", "", ""}, {"advertisement", "", ""}, {"as far as I know", "", ""}, {"approximately", "", ""}, {"annual percentage rate", "", ""}, {"as soon as possible", "", ""}, 
        {"because", "", ""}, {"business to business", "", ""}, {"before", "", ""}, {"bye for now", "", ""}, 
        {"Bachelor of Business Administration Degree", "", ""}, {"be back later", "", ""}, {"be back soon", "", ""}, {"background", "", ""}, 
        {"be right back", "", ""}, {"Bachelor of Science Degree", "", ""}, {"by the way", "", ""}, {"between", "", ""},
        {"see", "", ""},{"compensation and benefit", "", ""}, {"client and server", "", ""},
        {"Chief Executive Officer", "", ""}, {"Carbon Copy", "", ""}, {"compare", "", ""}, {"Chief Financial Officer", "", ""}, {"company", "", ""}, {"Chief Operating Officer", "", ""}, {"continuity of operations planning", "", ""}, {"corporation", "", ""}, 
        {"compare", "", ""},
        {"customer relationship management", "", ""}, {"customer sales representative", "", ""}, {"contrast", "", ""}, {"Chief Technical Officer", "", ""},
        {"see you", "", ""}, {"see you later", "", ""}, {"see you tomorrow", "", ""}, 
        {"department", "", ""}, {"division", "", ""},
        {"for example", "", ""}, {"Eastern Standard Time", "", ""}, {"email service provider", "", ""},
        {"end of day", "", ""}, {"each", "", ""}, {"each", "", ""}, {"end of month", "end of message", ""}, {"end of thread", "", ""}, {"end of year", "", ""}, {"enterprise resource planning", "", ""},
        {"frequently", "often", ""}, {"frequently asked question", "", ""}, {"face to face", "", ""}, 
        {"forward", "", ""}, {"for what it's worth", "", ""}, {"for your information", "", ""}, 
        {"got to go", "", ""}, {"gross domestic product", "", ""}, {"government", "", ""}, {"government", "", ""},
        {"have", "", ""}, {"have a nice day", "", ""}, 
        {"human resources", "", ""}, {"headquarters", "", ""}, {"that is", "", ""},
        {"in a meeting", "", ""}, {"I see", "", ""}, {"I don't care", "", ""}, {"i don't know", "", ""}, {"instant message", "", ""},
        {"in my opinion", "in memory of", "international maritime organization" }, {"in my humble opinion", "", ""}, {"incorporated", "", ""}, {"in real life", "", ""}, {"International Organization for Standardization", "", ""}, {"Information Technology", "", ""}, {"just kidding", "", ""}, 
        {"just kidding", "", ""}, {"junior", "", ""}, {"keep it simple stupid", "", ""}, {"key performance indicator", "", ""}, {"key result area", "", ""}, {"learning and development", "", ""}, 
        {"late", "", ""}, {"later", "", ""}, {"pound", "", ""}, {"limited liability company", "", ""}, {"laughing my ass Off", "", ""}, {"let me know", "", ""}, 
        {"laugh out loud", "", ""}, {"no problem", "", ""}, {"no reply necessary", "", ""}, {"Oh, I see", "", ""}, 
        {"on-the-job training", "", ""}, {"online training", "", ""}, {"oh my god", "", ""}, {"on my way", "", ""},
        {"on the phone", "", ""}, {"month-to-date", "", ""},
        {"maximum", "most", ""}, {"Master of Business Administration Degree", "", ""}, {"management by objectives", "", ""}, {"memorandum", "", ""}, {"manufacturing", "", ""}, {"minimum", "least", ""}, {"minimum", "least", ""}, {"month", "", ""}, {"important", "", ""},
        {"note well", "", ""}, {"number", "", ""}, {"not safe for work", "", ""}, {"not work related", "", ""},
        {"after", "", ""},
        {"profit and loss", "", ""}, {"portable document format", "", ""}, {"package", "", ""}, {"please", "", ""}, {"please", "", ""}, 
        {"private message", "project manager", "" }, {"project management office", "", ""}, {"purchase order", "", ""}, {"parent over shoulder", "", ""}, {"public relation", "", ""},
        {"problem", "", ""}, {"problems", "", ""}, {"paid time off", "", ""}, 
        {"every", "", ""}, {"research and development", "", ""},
        {"first quarter", "", ""}, {"second quarter", "", ""}, {"third quarter", "", ""}, {"fourth quarter", "", ""},
        {"quality assurance", "", ""}, {"quality of service", "", ""}, {"quantity", "", ""}, 
        {"responsible, accountable, consulted, informed", "", ""}, {"regarding", "", ""}, {"in regards to", "regarding", ""}, {"received", "", ""}, {"request for proposal", "", ""}, 
        {"rolling On the floor Laughing", "", ""}, {"return on investment", "", ""}, {"rolling on the floor laughing", "", ""}, {"results only work environment", "", ""},
        {"someone", "", ""}, {"something", "", ""}, {"specific, measureable, attainable, realistic, and time-bound", "specific, measureable, achievable, realistic, and time-bound", ""}, {"social network site", "", ""}, {"Small Office", "Home Office", ""}, {"straight out of the box", "", ""}, 
        {"immediately", "", ""}, {"strengths, weaknesses, opportunities, threats", "", ""},
        {"temporary secretary", "", ""}, {"though", "", ""}, {"through", "", ""},
        {"thanks", "", ""}, {"too much information", "", ""}, {"talk to you later", "", ""}, {"talk to you soon", "", ""}, 
        {"you", "", ""}, {"versus", "against", ""},
        {"Virtual Class", "", ""}, {"Virtual learning environment", "", ""}, {"Vice President", "", ""}, {"Virtual private network", "", ""}, {"virtual worker", "", ""}, {"virtual worker at virtual workplace", "", ""},
        {"Work At Home", "", ""}, {"Web-based training", "", ""}, {"What's in it for me", "", ""},
        {"Work From Home", "", ""}, {"with", "", ""}, {"within", "", ""}, {"without", "", ""}, 
        {"welcome back", "", ""}, {"what about you", "", ""}, {"with respect to", "", ""},
        {"you're welcome", "", ""}, {"year", "", ""}, {"years", "", ""}, {"year-to-date", "", ""}  
    };
    char mi[SIZE] = ""; // message input by user
    char show[LONG] = ""; // Translated output by the program
    int m = 0;          // the method of conversion
    enum Status MessageStatus = FULLSTOP;

    // Enter your message
    printf( "%s \n", "Enter your message: (Not greater than 160 letters ). " );
    gets(mi);

    // Choose a method of conversion
    do {
        printf( "%s", "\nChoose a method: \n 1 - Short message to long\n 2 - long message to short\n? " );
        scanf( "%d", &m );
    } while ( m < 1 || m > 2 );

    // Call the function pointer to the function menu
    (*method[m - 1]) (mi, SMSWords, SMSTranslations, show );

    // Format the results
    for( size_t i = 0; show[i] != '\0'; i++ ) {
        // Convert a first letter in the sentence to uppercase
        if ( isalpha( show[i] ) && MessageStatus == FULLSTOP ) {
            show[i] = toupper( show[i] );
            MessageStatus = NORMAL;
        } // end if
        // look for a full stop
        if ( show[i] == 46 ) {
            MessageStatus = FULLSTOP;
        } // end if
    } // end for
    
    // Display the results
    printf( "%s", show );

    return 0; // indicate successful termination
} /* end main */

// convert the long message to short message
void lToS( char * message, const char * SMSWd[], const char * TWd[][3], char * show ) {
    char * messagePtr = ""; // message pointer
    char wordTemp[200] = ""; // template to the standard long word
    enum Status SpaceStatus = NOSPACE;

    // convert the message to lowercase
    for ( size_t i = 0; message[i] != '\0'; i++ ) {
        message[i] = tolower( message[i] );
    } // end for

    // find the words
    for ( size_t i = 0; i < WORDS; i++ ) {
        for ( size_t j = 0; j < 3; j++ ) {
            // copy the standard word 
            strcpy( wordTemp, TWd[i][j] );
            // convert standart word to lowercase
            for ( size_t i = 0; wordTemp[i] != '\0'; i++ ) {
                wordTemp[i] = tolower( wordTemp[i] );
            } // end for
            // identify the words and manipulate the string
            if ( ( messagePtr = strstr( message, wordTemp ) ) != NULL && *wordTemp != '\0' && ( messagePtr[strlen(wordTemp)] == ' ' || ispunct(messagePtr[strlen(wordTemp)]) ) ) { // if the words are found
                --messagePtr;
                if ( !isgraph( *messagePtr ) ) { // if there is a space before it.
                    ++messagePtr;
                    // set that location with empty spaces
                    memset( messagePtr, ' ', strlen( wordTemp ) );
                    // Add the short message to that location
                    for ( size_t l = 0; SMSWd[i][l] != '\0'; l++ ) {
                        messagePtr[l] = SMSWd[i][l];
                    } // end for
                    i = 0;
                    break;
                } // end if
                else {
                    ++messagePtr;
                } // end else
            } // end if
        } // end for
    } // end for

    // Remove unwanted spaces
    for ( size_t i = 0, j = 0; message[i] != '\0'; i++ ) {
        // look for a space
        if ( isspace( message[i] ) ) {
            if ( SpaceStatus == SPACE ) {
                SpaceStatus = MOSPACE;
            } // end if
            else if ( SpaceStatus == NOSPACE )
                SpaceStatus = SPACE;
        } // end if
        else {
            SpaceStatus = NOSPACE;
        } // end else

        // Take the short message
        if ( SpaceStatus != MOSPACE ) {
            show[j++] = message[i];
        } // end if
    } // end while
} /* end function lToS */

// convert the short message to long message
void sToL( char * message, const char * SMSWd[], const char * TWd[][3], char * show ) {
    enum Status WordStatus = UNFOUND;
    enum Status PunctStatus = ANTIPUNCT;
    char * tokenPtr = "";
    char * tokenTempPtr = ""; // token pointer temp
    char subShow[30] = "";    // a part of the message
    char punct[20] = ""; // copy the punctuations
    char wordTemp[20] = "";
    int choice = 0;

    tokenPtr = strtok( message, " " );

    while( tokenPtr != NULL ) {
        WordStatus = UNFOUND;   // Restart a search for every token
        PunctStatus = ANTIPUNCT;  // look for punctions after a similary letter
        memset( punct, '\0', 20 ); // clear the punct for every punctions to come to be recorded

        // identify the word/token
        for ( size_t i = 0; i < WORDS; i++ ) {
            // convert the standard word to small case letters 
            strcpy( wordTemp, SMSWd[i] );
            // convert token to lowercase
            for ( size_t i = 0; tokenPtr[i] != '\0'; i++ ) {
                tokenPtr[i] = tolower( tokenPtr[i] );
            } // end for
            // convert standart word to lowercase
            for ( size_t i = 0; wordTemp[i] != '\0'; i++ ) {
                wordTemp[i] = tolower( wordTemp[i] );
            } // end for

            // identify the word
            if ( strcmp( tokenPtr, wordTemp ) == 0 ) { // if SMS word is identified
                // identify the number of options
                for (size_t j = 0; *TWd[i][j] != '\0'; j++ ) {
                    if ( j > 0 ) {
                        WordStatus = MANY;
                    } // end if
                    else {
                        WordStatus = FOUND;
                    } // end else
                } // end for

                // Get the long word/message
                if ( WordStatus == FOUND ) { // if only one option is found
                    sprintf( subShow, "%s%s", " ", TWd[i][0] ); 
                    strcat( show, subShow );
                } // end if
                else if ( WordStatus == MANY ) { // if more than one option is found
                    // Display the options
                    int j = 0;
                    do {
                        printf( "\n\n%s\n%s\n", tokenPtr, "Choose one option: (0 to choose nothing): ");
                        for( j = 0; *TWd[i][j] != '\0'; j++ ) {
                            printf( "%d: %s\n", j + 1, TWd[i][j] );
                        } // end for
                        scanf( "%d", &choice ); // choose one option
                    } while ( choice > j || choice < 0 );

                    if ( choice == 0 ){
                        WordStatus = UNFOUND;
                        PunctStatus = UNCHOSEN;
                    } // end if

                    // get the choice
                    if ( WordStatus != UNFOUND ) {
                        sprintf( subShow, "%s%s%s", " ", TWd[i][choice - 1], punct );
                        strcat( show, subShow );
                    } // end if
                } // end else
                break;
            } // end if
            else if ( (tokenTempPtr = strstr( tokenPtr, wordTemp )) != NULL ) { // if a standard word is found in the token
                if ( tokenPtr == tokenTempPtr ) { // if they are on the same pointer
                    int l = 0,m = 0; // controllers around the pointer 
                    for ( l = 0, m = 0; tokenPtr[l] != '\0'; ) { // loop through the token
                        if ( tokenPtr[l] == wordTemp[l]) { // go beyond the similarities
                            l++; m++;
                        } // end if
                        else if( ispunct( tokenPtr[m] ) ) { // confirm that the rest is just punctuations
                            PunctStatus = PUNCT;
                            m++;
                        } // end else if
                        else if ( !ispunct( tokenPtr[m] ) ) { // if not then they are not similary
                            break;
                        } // end else if
                    } // end for

                    // if they are similary get the punctiations AND word is found
                    if ( PunctStatus == PUNCT ) {
                        WordStatus = FOUND;
                        strcpy( punct, &tokenPtr[l] );
                    } // end if

                    // if word is found start the process done in option A
                    if ( WordStatus == FOUND ) {
                        // identify the number of options
                        for (size_t j = 0; *TWd[i][j] != '\0'; j++ ) {
                            if ( j > 0 ) {
                                WordStatus = MANY;
                            } // end if
                            else {
                                WordStatus = FOUND;
                            } // end else
                        } // end for

                        // get the long word
                        if ( WordStatus == FOUND ) { // if only one option is found
                            sprintf( subShow, "%s%s%s", " ", TWd[i][0], punct );
                            strcat( show, subShow );
                        } // end if
                        else if ( WordStatus == MANY ) { // if more than one option is found
                            // Display the options
                            int j = 0;
                            do {
                                printf( "\n\n %s\n%s\n", tokenPtr, "Choose one option:(0 to choose nothing) ");
                                for( j = 0; *TWd[i][j] != '\0'; j++ ) {
                                    printf( "%d: %s\n", j + 1, TWd[i][j] );
                                } // end for
                                scanf( "%d", &choice ); // choose one option
                            } while ( choice > j || choice < 0 );

                            if ( choice == 0 ){
                                WordStatus = UNFOUND;
                                PunctStatus = UNCHOSEN;
                            } // end if

                            // get the choice
                            if ( WordStatus != UNFOUND ) {
                                sprintf( subShow, "%s%s%s", " ", TWd[i][choice - 1], punct );
                                strcat( show, subShow );
                            } // end if
                        } // end else
                        break;
                    } // end if
                } // end if
            } // end else if
        } // end for

        // get the same word if not identified
        if ( WordStatus == UNFOUND ) {
            sprintf( subShow, "%s%s%s", " ", tokenPtr, ( *punct != '\0' && PunctStatus != UNCHOSEN )? punct : "" );
            strcat( show, subShow );
        } // end if

        tokenPtr = strtok( NULL, " " );
    } // end while
} /* end function sToL */