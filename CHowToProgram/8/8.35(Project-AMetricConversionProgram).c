/*
    theBitRiddler
    2/9/2024
    9:46 PM
    8.35 (Project: A Metric Conversion Program) 
Metric System
length   // millimeter = 0.0394inch, centimeter = 0.394 inch, kilometer = 0.6214 mile 
Area    // square_meter = 0.025 acre    // hectare = 2.472 acres, square_kilometer = 0.386 square miles 
weight   // gram = 15.43 grains, kilogram = 2.205 pounds, tonne = 19.688 hundredweight        
Capacity     // centiliter = 0.018 pint / 0.021 US pint, liter = 1.76 pints / 2.1 US pints  
Imperial System
length       // inch = 25.4 millimeters, yard = 0.914 meter, mile = 1.609 kilometers  
Area     // sq_inch = 6.452 sq centimeters( cm^2), sq_mile = 259 hectares, sq_yard = 0.836 sq meter, sq_mile = 2.59 sq kilometers / 259 hectares
weight     // ounce = 28.35 grams, ton = 1016.04 kilograms
British capacity     // pint = 0.568 liter, gallon = 4.546 liters
American Capacity    // us_pint = 0.473 liter, us_gallon = 3.785 liters
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
char * recon( const char * , const char ** , int * );
double convert( const double [][10], double[][10], int, int, int, int );
int main( void ) {
    const char * standards[12][10] = {
        { "picometer", "nanometer", "micrometer", "millimeter", "centimeter", "decimeter", "meter", "decameter", "hectometer", "kilometer" },
        { "square millimeter", "square centimeter", "square meter", "square decameter", "square hectometer", "square kilometer", "", "", "" },
        { "square meter", "are", "hectare", "square kilometer", "", "", "", "", "", "" },
        { "milligram", "centigram", "decigram", "gram", "decagram", "hectogram", "kilogram", "tonne", "", "" },
        { "milliliter", "centiliter", "deciliter", "liter", "decaliter", "hectoliter", "kiloliter", "", "", "" },
        { "cubic millimeter", "cubic centimeter", "cubic decimeter", "cubic meter", "cubic decameter", "cubic hectometer", "cubic kilometer", "", "", "" },

        { "inch", "foot", "yard", "furlong", "mile", "", "", "", "", "" },
        { "square inch", "square foot", "square yard" "square furlong", "square mile", "", "", "", "", "" },
        { "square yard", "acre", "square mile", "", "", "", "", "", "", "" },
        { "grain", "ounce", "pound", "stone", "hundredweight", "ton", "", "", "", "" },
        { "fluid ounce", "pint", "quart", "gallon", "", "", "", "", "", "" },
        { "us fluid ounce", "us pint", "us quart", "us gallon", "", "", "", "", "", "" }
    };
    const double standard_values[12][10] = {
        { 1000000, 1000, 1000, 10, 10, 10, 10, 10, 10, 1 },
        { 100, 100, 100, 100, 100, 100, 1, 0, 0, 0 },
        { 100, 100, 100, 1, 0, 0, 0, 0, 0, 0 },
        { 10, 10, 10, 10, 10, 10, 1000, 1, 0, 0 },
        { 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1, 0, 0, 0 },
        { 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1, 0, 0, 0 },

        { 12, 3, 220, 8, 1, 0, 0, 0, 0, 0 },
        { 144, 9, 48400, 64, 1, 0, 0, 0, 0, 0 },
        { 4840, 640, 1, 0, 0, 0, 0, 0, 0, 0 },
        { 437, 16, 14, 8, 20, 1, 0, 0, 0, 0 },
        { 20, 2, 4, 1, 0, 0, 0, 0, 0, 0 },
        { 16, 2, 4, 1, 0, 0, 0, 0, 0, 0 }
    };
    double values[12][10] = {{0.0},{0.0},{0.0},{0.0},{0.0},{0.0},{0.0},{0.0},{0.0},{0.0},{0.0},{0.0}};
    char request[100] = "How many kilometers are in 8000 meters?"; // question/ request input by user
    char *unitPtr = "";
    char *unit1 = "";  // unit one
    char *unit2 = "";  // unit two
    double value = 0;     // value to be converted
    char * rem = "";     // remainder on the strtod function
    char * tokenPtr = "";     // token pointer
    char * unit1Ptr = "";   // first unit pointer
    char * unit2Ptr = "";     // second unit pointer
    int i = 0, j = 0, k = 0; // counter of standards
    int a = 0;  // first unit identity recorder
    int b = 0;  // second unit identinty recorder
    int c = 0;  // first unit position recorder
    int d = 0;  // second unit position recorder
    
    // propt a user to enter a question
    // printf( "%s\n", "Enter your request (use simple grammar, use 'us' for united states and avoid abbreviations ): " );
    // fgets( request, 100, stdin );

    // change the request to lowercase
    for ( size_t i = 0; request[i] != '\0'; i++ ) {
        request[i] = tolower( request[i] );
    } // end for

    // extract the first unit and identify the unit
    while ( i < 12 ) {
        if ( ( unit1 = recon( request, standards[i], &j ) ) != NULL )
            break;
        i++;
    } // end while
    a = i; // assign a type of the a unit to the first unit
    c = j; // assign a position of a unit to the first unit
    // get the first unit pointer
    unitPtr = strstr( request, unit1 );
    if ( unit1 != NULL ) {
        if( !isalpha( *( --unitPtr ) ) ) {
            ++unitPtr;
            unit1Ptr = strstr( request, unit1 );
        } // end if
        else {
            ++unitPtr;
            while( standards[i][j][k] != '\0' ) {
                k++; unitPtr++;
            } // end while
            unit1Ptr = strstr( unitPtr, unit1 );
        } // end else   
    } // end if
    
    // extract the second unit
    j++; // get to the second position
    while ( i < 12 ) {
        if ( ( unit2 = recon( request, standards[i], &j ) ) != NULL )
            break;
        i++;
    } // end while
    b = i; // assign a type of a unit to the second unit
    d = j; // assign a position of a unit to the second unit
    // get the second unit pointer
    unit2Ptr = strstr( request, unit2 );

    // check the text semantics
    if ( ( a == b && c == d ) || !( ( a == b || a == 0 && b == 6 ) || ( (a == 1 || a == 2) && (b == 7 || b == 8) ) || ( a == 3 && b == 9 ) || ( (a == 4 || a == 5) && (b == 10 || b == 11)  ) ) )
        printf( "\n%s\n", "Your statement is meaningless");
    // get the value
    tokenPtr = strtok( request, " " );
    while( tokenPtr != NULL ) {
        if ( (value = strtod( tokenPtr, &rem )) != 0 ) {
            break;
        } // end if
        tokenPtr = strtok( NULL, " " );
    } // end while
    // find which unit the value belongs
    if ( ( rem < unit1Ptr && rem > unit2Ptr ) || ( rem < unit1Ptr && unit1Ptr < unit2Ptr ) ) { //if the remainder to strtod is less than first unit pointer; then the value is of the first unit
        values[a][c] = value; // convert to second unit
        value = convert( standard_values, values, a, c, b, d );
        printf( "\nANS: %lf %s%s", value, unit2, value > 1 ? "s": "" );
    } // end if
    else {
        values[b][d] = value; // convert to first unit
        value = convert( standard_values, values, b, d, a, c );
        printf( "\nANS: %lf %s%s", value, unit1, value > 1 ? "s": "" );
    } // end else
    return 0; // indicate termination successful
} /* end main */
// convert from unit a to unit b
double convert(const double sv[][10], double v[][10], int i, int j, int m, int n ) {
    double froUnit = v[i][j]; // unit with value
    double toUnit = v[m][n];  // unit to be convert to
    if ( i == m ) { // if units are of the same system
        toUnit = froUnit;
        if ( j > n ) { // order or positions
            while( j > n ) {
                toUnit *= sv[m][--j];
            } // end while
        } // end if
        else {
            while( j < n ) {
                toUnit /= sv[m][j++];
            } // end while
        } // end else
    } // end if

    return toUnit;
} /* end function convert */
// identify a unit
char * recon( const char * request, const char ** std, int * subscript ) {
    char * unit = "";
    char * ptr = "";
    char * ptr2 = "";
    size_t i = *subscript;
    size_t j = 0;
    
    for ( ; *std[i] != '\0'; i++ ) {
        if ( ( ptr = strstr( request, std[i] ) ) != NULL ) {
            // whatch if there is a space after a unit and there isn't any letter joined
            if ( !isalpha( *( --ptr ) ) || isblank( *ptr )  ) {
                ++ptr; // restore the pointer's location
                unit = std[i];
                *subscript = i;
                return unit;
            } // end if
            else if ( isalpha( *( ptr ) ) ) { 
                ++ptr; // restore the pointer's location
                // reallocate the position
                while( std[i][j] != '\0' ) {
                    j++; ptr++;
                } // end while
               if( ( ptr2 = strstr( ptr, std[i] ) ) != NULL ) {
                    // whatch if there is a space after a unit and there isn't any letter joined
                    if ( !isalpha( *( --ptr2 ) ) || isblank( *ptr2 )  ) {
                        ++ptr2;
                        unit = std[i];
                        *subscript = i;
                        return unit;
                    } // end if
               } // end if
            } // end else if
        } // end if
    } // end for
    return NULL; // indicate unit not found
} /* end function recon */