/*
    theBitRiddler
    2/19/2024
    1:23 PM
    8.36 (Cooking with Healthier Ingredients)
    1 cup sour cream, 1 cup milk, 1 teaspoon lemon juice, 1 cup sugar, 1 cup butter, 1 cup flour, 1 cup mayonnaise, 1 egg, 1 cup milk, 1/4 cup oil, white bread

    "1 cup sour cream",         "1 cup yogurt",
    "1 cup milk",               "1/2 cup evaporated milk and 1/2 cup water",
    "1 teaspoon lemon juice",   "1/2 teaspoon vinegar",
    "1 cup sugar",              "1/2 cup honey, 1 cup molasses or 1/4 cup agave nectar",
    "1 cup butter",             "1 cup margarine or yogurt",
    "1 cup flour",              "1 cup rye or rice flour",
    "1 cup mayonnaise",         "1 cup cottage cheese or 1/8 cup mayonnaise and 7/8 cup yogurt",
    "1 egg",                    "2 tablespoons cornstarch, arrowroot flour or potato starch or 2 egg whites or 1/2 of a large banana (mashed)",
    "1 cup milk",               "1 cup soy milk",
    "1/4 cup oil",              "1/4 cup applesauce",
    "white bread"               "whole-grain bread"         
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 11
void substituteDisplay( const double [][3], const char *[][8], double, size_t );
int main( void ) {
    const char * ingredients[SIZE][2] = {
        { "sour", "cream" }, { "milk", "" }, { "lemon", "juice" }, { "sugar", "" }, { "butter", "" },
        { "flour", "" }, { "mayonnaise", "" }, { "egg", "" }, { "milk", "" }, { "oil", "" }, { "white", "bread" }
    };
    const double ing_sv[SIZE] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.25, 1 };    // ingredient standard values
    const char * substitutions[SIZE][8] = {
        { "cup", "yogurt", "", "", "", "", "", "" },
        { "cup", "evaporated milk", "and", "cup", "water", "", "", "" },
        { "teaspoon", "vinegar", "", "", "", "", "", "" }, 
        { "cup", "honey", ",", "cup", "molasses", "or", "cup", "agave nectar" }, 
        { "cup", "margarine or yogurt", "", "", "", "", "", "" },
        { "cup", "rye or rice flour", "", "", "", "", "", "" }, 
        { "cup", "cottage cheese", "or", "cup", "mayonnaise", "and", "cup", "yogurt" },
        { "tablespoon", "cornstarch, arrowroot flour or potato starch", "or", "egg whites", "or", "of a large banana (mashed)", "", "" }, 
        { "cup", "soy milk", "", "", "", "", "", "" }, 
        { "cup", "applesauce", "", "", "", "", "", "" }, 
        { "whole-grain bread", "", "", "", "", "", "", "" }
    };
    const double sub_sv[SIZE][3] = {
        { 1, 0, 0}, { 0.5, 0.5, 0 }, { 0.5, 0, 0 }, { 0.5, 1, 0.25 }, { 1, 0, 0 }, { 1, 0, 0 }, 
        { 1, 0.125, 0.875 }, { 2, 2, 0.5 }, { 1, 0, 0 }, { 0.25, 0, 0 }, { 1, 0, 0 } 
    };  // substitutions standard values
    char recipe[320] = "";
    char recTemp[320] = "";  // recipe template
    char * token = "";
    char * tokenRem = "";
    char * cFlag = "";       // comma flag
    char firstName[11] = "";      // first name of the ingredient
    char secondName[11] = "";     // second name of the ingredient 
    char * divide = "";         // a denominator of an ingredient
    char wordM[15] = "";     // measurents in words: cup, teaspoon ...
    char uncharted[80] = "";      // contain all unkown ingredients
    int knownflag = 0;        // unknown flga
    int unknownflag = 0;    // unknown flag
    double ing_value = 0;   // ingredient value
    double ingIV = 0;   // ingredient ideal value
    size_t i = 0;   // controller
    int mflag = 0;  // measurement flag 
    int mkflag = 0; // milk flag
    int subType = 0;    // 0 == all, 
    int subUnits[SIZE] = {0};  // units of substitution to be selected
    
    printf( "%s\n", "Enter your recipe" );
    gets( recipe );
    printf( "%s ", "Enter your substitution type\n 1 High cholesterol\n 2 Loosing Weight\n 3 All :\n ?" );
    scanf( "%d", &subType );

    if ( subType == 1 ) {
        subUnits[0]++, subUnits[1]++, subUnits[4]++, subUnits[6]++, subUnits[7]++, subUnits[8]++, subUnits[9]++;
    } // end if
    if ( subType == 2 ) {
        subUnits[3]++;
    } // end if
    if ( subType == 3 ) {
        for ( size_t i = 0; i < SIZE; i++ )
            subUnits[i]++;
    }   // end if

    strcpy( recTemp, recipe );   // use a template
    token = strtok( recTemp, " ;:" ); 
    while( token != NULL ) { 
        
        if ( strtod( token, &tokenRem ) > 0 ) {
            ing_value = strtod( token, &tokenRem );  // take the value if found
            mflag++;
            // if a token is a fraction
            if ( ( divide = strstr( token, "/" ) ) != NULL ) {
                ing_value /= strtod( ++divide, &tokenRem );
            } // end if
        } // end if
        // get the word measurement; cup, teaspoon, tablespoon ...
        if ( strstr( token, "cup" ) != NULL || strstr( token, "teaspoon" ) != NULL || strstr( token, "tablespoon" ) != NULL ) {
            strcpy( wordM, token );
            mflag++;
        }   // end if     

        // get the ingredients names
        for ( ; i < SIZE && mflag == 0; i++ ) {
            // break if token is comma
            if ( strcmp( token, "," ) == 0 )
                break;
            // find the first name of the ingredient and the second name   
            if( strstr( token, ingredients[i][0] ) != NULL && *firstName == '\0' ) {
                if ( !mkflag ) { // if milk flag is zero
                    strcpy( firstName, ingredients[i][0] );  // copy firstName
                    if ( strcmp( ingredients[i][0], "milk" ) == 0 ) { // flag mkflag if first milk detected
                        mkflag++;
                    } // end if
                    break;
                } // end if
                else if ( mkflag ) { // if mild flag is positive
                    // copy firstName other than milk 
                    if ( strcmp( ingredients[i][0], "milk" ) != 0 ) {
                        strcpy( firstName, ingredients[i][0] );
                        break;
                    } // end if
                    // copy firstName if it's a second milk detected    
                    if ( strcmp( ingredients[i][0], "milk" ) == 0 ) {
                        strcpy( firstName, ingredients[i = 8][0] ); 
                        mkflag--;
                        break;
                    }   // end if
                    
                }   // end if
            }   // end if
            if ( strstr( token, ingredients[i][1] ) != NULL && *secondName == '\0' && *firstName != '\0' ) { 
                strcpy( secondName, ingredients[i][1] );
                break;
            } // end if
        }   // end for

        // look for unknown token other than the measurement standards
        for ( size_t i = 0; i < SIZE; i++ ) {
            for ( size_t j = 0; j < 2 && !mflag && *ingredients[i][j] != '\0'; j++ ) {
                if ( strstr( token, ingredients[i][j] ) != NULL ) {
                    knownflag = 1;
                    break;
                } // end if
                else if ( i == (SIZE - 1) && j == 1 && !knownflag ) {
                    unknownflag = 1;
                } // end if
            } // end for
            if (knownflag)
                break;
        } // end for

        // correct the ingredients incase it's unknown; 
        if ( strcmp( token, "," ) != 0 && strcmp( token, "." ) != 0 )
            strcat( strcat( uncharted, " " ), token );
        
        // check the ingredients and find their substitution
        if ( ( cFlag = strstr( token, "," ) ) != NULL || ( cFlag = strstr( token, "." ) ) != NULL ) {  // look for a comma, process the current ingredient
            // process the current ingredient for substitution
            if ( !unknownflag ) {
                ingIV = ing_value / ing_sv[i];  // get the ingredient's ideal value
                // display the substitution
                if ( subUnits[i] && strstr( firstName, ingredients[i][0]) != NULL && strstr( secondName, ingredients[i][1]) != NULL ) { // substitute the ingredient
                    substituteDisplay( sub_sv, substitutions, ingIV, i );
                }  // end if    
                else if ( !subUnits[i] && strstr( firstName, ingredients[i][0]) != NULL && strstr( secondName, ingredients[i][1]) != NULL ) { // don't substitute the ingredient
                    if ( ing_value > 0 )    // print if value greater than zero
                        printf( " %.3lf", ing_value );
                    // print the word measurement and the names of the ingredient    
                    printf( " %s%s %s %s", wordM, ing_value > 1 ? "s" : "", firstName, secondName );
                } // end else
            } // end if
            else {  // if knownflag is negative
                printf( " %s", uncharted );
            } // end if

            // prepare the search for the next ingredient
            if ( *firstName != '\0' || *secondName != '\0' )
                i = 0;  // prepare the controller for another search

            // clear the names and prepare for the next ingredient
            memset( firstName, '\0', 11 );
            memset( secondName, '\0', 11 );
            if (!unknownflag) {
                printf( "%s", cFlag ); // print the available comma or period before clearing
            } // end if
            ing_value = 0;
            unknownflag = 0;
            *cFlag = '\0';
            memset( wordM, '\0', 15 );
            memset( uncharted, '\0', 80 );

        }   // end if

        // clear the measurement flag
        mflag = 0;
        // clear the known flag
        knownflag = 0;

        if ( i == SIZE ) { // clear the search controller if it reaches the end
            i = 0;
        } // end if

        // move to another token
        token = strtok( NULL, " ;:" );
    }   // end while 

    return 0; // indicate successful termination
}   /* end main */

void substituteDisplay( const double sub_sv[][3], const char * substitutions[][8], double ingIV, size_t i ) {
    double subIV = 0;   // substitution ideal value

    printf( "%s", "\n" );
    for ( size_t j = 0, k = 0; j < 8 && *substitutions[i][j] != '\0'; j++ ) {
        // get the substitute ideal value
        subIV = ingIV * sub_sv[i][k];
        // display the value
        if ( subIV )
            printf( " %.3lf", subIV );
        // display the word measurements
        if ( strcmp( substitutions[i][j], "cup" ) == 0 || strcmp( substitutions[i][j], "teaspoon" ) == 0 || strcmp( substitutions[i][j], "tablespoon" ) == 0 )
            printf( " %s%s", substitutions[i][j++], subIV > 1 ? "s" : "" );      
        // display the substitution's names
        printf( " %s", substitutions[i][j++]);  // look for what's next after the substitution ( j++ )
        // move to another substitution standard values
        if ( strcmp( substitutions[i][j], "and" ) == 0 || strcmp( substitutions[i][j], "or" ) == 0 || strcmp( substitutions[i][j], "," ) == 0 ) {
            k++;
            printf( " %s", substitutions[i][j] );
        }   // end if
    } // end for
        
} /* end function substitute */