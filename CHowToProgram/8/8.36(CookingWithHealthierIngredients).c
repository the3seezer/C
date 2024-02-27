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
    const double ing_sv[SIZE] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1/4, 1 };    // ingredient standard values
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
        { 1, 0, 0}, { 1/2, 1/2, 0 }, { 1/2, 0, 0 }, { 1/2, 1, 1/4 }, { 1, 0, 0 }, { 1, 0, 0 }, 
        { 1, 1/8, 7/8 }, { 2, 2, 1/2 }, { 1, 0, 0 }, { 1/4, 0, 0 }, { 1, 0, 0 } 
    };  // substitutions standard values
    char recipe[320] = "1 cup sour cream, 1 cup milk,  1 teaspoon lemon juice, 1 cup sugar, 1 cup butter, 1 cup flour, 1 cup mayonnaise, 1 egg, 1 cup milk, 1/4 cup oil, white bread ";
    char recTemp[320] = "";  // recipe template
    char * token = "";
    char * tokenRem = "";
    char * cFlag = "";       // comma flag
    char * firstName = "";      // first name of the ingredient
    char * secondName = "";     // second name of the ingredient 
    char wordM[15] = "";     // measurents in words: cup, teaspoon ...
    double ing_value = 0;   // ingredient value
    double ingIV = 0;   // ingredient ideal value
    size_t i = 0;   // controller 
    int mflag = 0;  // measurement flag 
    int subType[6] = {0};    // 0 == all, 
    
    // printf( "%s\n", "Enter your recipe" );
    // gets( recipe );
    // printf( "%s: ", "Enter your substitution type" );
    // gets( subType );

    strcpy( recTemp, recipe );   // use a template
    token = strtok( recTemp, " .;:" ); 
    while( token != NULL ) { 
        // search for a comma
        if ( strtod( token, &tokenRem ) > 0 ) {
            ing_value = strtod( token, &tokenRem );  // take the value if found
            mflag++;
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
                firstName = ingredients[i][0];
                break;
            }   // end if
            if ( strstr( token, ingredients[i][1] ) != NULL && *secondName == '\0' && *firstName != '\0' ) {
                secondName = ingredients[i][1];
                break;
            } // end if
        }   // end for
        
        // check the ingredients and find their substitution
        if ( ( cFlag = strstr( token, "," ) ) != NULL ) {  // look for a comma, process the current ingredient
            // process the current ingredient for substitution
            ingIV = ing_value / ing_sv[i];  // get the ingredient's ideal value
            // display the substitution
            substituteDisplay( sub_sv, substitutions, ingIV, i );

            // clear the names for another ingredient
            if ( *firstName != '\0' || *secondName != '\0' )
                i = 0;  // prepare the controller for another search

            // prepare for the next ingredient
            firstName = "", secondName = "";
            *cFlag = '\0';
        }   // end if

        // clear the measurement flag
        mflag = 0;

        if ( i == SIZE ) { // clear the search controller if it reaches the end
            i = 0;
        } // end if

        // move to another token
        token = strtok( NULL, " .;:" );
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
            printf( " %.2lf", subIV );
        // display the word measurements
        if ( strcmp( substitutions[i][j], "cup" ) == 0 || strcmp( substitutions[i][j], "teaspoon" ) == 0 || strcmp( substitutions[i][j], "tablespoon" ) == 0 )
            printf( " %s%s", substitutions[i][j++], (ingIV * sub_sv[i][k]) > 1 ? "s" : "" );      
        // display the substitution's names
        printf( " %s", substitutions[i][j++]);  // look for what's next after the substitution ( j++ )
        // move to another substitution standard values
        if ( strcmp( substitutions[i][j], "and" ) == 0 || strcmp( substitutions[i][j], "or" ) == 0 || strcmp( substitutions[i][j], "," ) == 0 ) {
            k++;
            printf( " %s", substitutions[i][j] );
        }   // end if
    } // end for
        
} /* end function substitute */