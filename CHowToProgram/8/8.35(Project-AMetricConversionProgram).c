/*
    theBitRiddler
    2/9/2024
    9:46 PM
    8.35 (Project: A Metric Conversion Program) 
Metric System
length   // millimeter = 0.0394inch, centimeter = 0.394 inch, kilometer = 0.6214 mile 
Area    // square_meter = 0.025 acre    // hectare = 2.472 acres, square_kilometer = 0.386 square miles 
weight   // gram = 15.43 grains, kilogram = 2.205 pounds, tonne = 19.688 hundredweight        
Capacity     // centiliter = 0.018 pint / 0.021 US pint, liter = 1.76 pints / 2.1 US pints, 1 liter = 1000 cubic centimeters  
Imperial System
length       // inch = 25.4 millimeters, yard = 0.914 meter, mile = 1.609 kilometers  
Area     // sq_inch = 6.452 sq centimeters( cm^2), sq_mile = 259 hectares, sq_yard = 0.836 sq meter, sq_mile = 2.59 sq kilometers / 259 hectares
weight     // ounce = 28.35 grams, ton = 1016.04 kilograms
British capacity     // pint = 0.568 liter, gallon = 4.546 liters, 1 pint = 568.2613 cubic centimeters, 1 pint = 1.20095 us pint
American Capacity    // us_pint = 0.473 liter, us_gallon = 3.785 liters, 1 us pint = 473.1765 cubic centimeters
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
char * recon( const char * , const char *[][10], int*,  int * );
double convert( const double [][10], double[][10], int, int, int, int );
void transfer( const double [][10], double[][10], int *, int *, const int );
int main( void ) {
    const char * standards[12][10] = {
        { "picometer", "nanometer", "micrometer", "millimeter", "centimeter", "decimeter", "meter", "decameter", "hectometer", "kilometer" },
        { "square millimeter", "square centimeter", "square decimeter", "square meter", "square decameter", "square hectometer", "square kilometer", "", "", "" },
        { "square meter", "ares", "hectare", "square kilometer", "", "", "", "", "", "" },
        { "milligram", "centigram", "decigram", "gram", "decagram", "hectogram", "kilogram", "tonne", "", "" },
        { "milliliter", "centiliter", "deciliter", "liter", "decaliter", "hectoliter", "kiloliter", "", "", "" },
        { "cubic millimeter", "cubic centimeter", "cubic decimeter", "cubic meter", "cubic decameter", "cubic hectometer", "cubic kilometer", "", "", "" },

        { "inch", "feet", "yard", "furlong", "mile", "", "", "", "", "" },
        { "square inch", "square feet", "square yard" "square furlong", "square mile", "", "", "", "", "" },
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
    char request[100] = "How many kilometers are in 1 miles?"; // question/ request input by user
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
    
    // proMpt a user to enter a question
    // printf( "%s\n", "Enter your request: \n (use simple grammar, use 'us' for united states,\n use meter and liter not metre or litre\n use digit for values and avoid abbreviations ): " );
    // fgets( request, 100, stdin );

    // change the request to lowercase
    for ( size_t i = 0; request[i] != '\0'; i++ ) {
        request[i] = tolower( request[i] );
    } // end for

    // change 'foot' to 'feet'
    for ( size_t i = 0; request[i] != '\0'; i++ ) {
        if ( request[i] == 'f' && request[i + 1] == 'o' && request[i + 2] == 'o' && request[i + 3] == 't' ) {
            request[i + 1] = 'e';
            request[i + 2] = 'e';
        } // end if
    } // end for

    // extract the first unit and identify the unit
    while ( i < 12 ) {
        if ( ( unit1 = recon( request, standards, &i, &j ) ) != NULL )
            break;
        i++;
    } // end while
    a = i; // assign a type of the a unit to the first unit
    c = j; // assign a position of a unit to the first unit

    // get the first unit pointer
    if ( *unit1 != '\0' )   // check if unit1 isn't empty
        unitPtr = strstr( request, unit1 );

    if ( unit1 != NULL ) {
        // distinguish meter or liter ..., from other units. i.e millimeters, kiloliter ...
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
        if ( ( unit2 = recon( request, standards, &i, &j ) ) != NULL )
            break;
        i++;
    } // end while
    b = i; // assign a type of a unit to the second unit
    d = j; // assign a position of a unit to the second unit

    // get the second unit pointer
    if ( *unit2 != '\0')    // check if unit2 is not empty
        unit2Ptr = strstr( request, unit2 );

    // get the value
    tokenPtr = strtok( request, " " );
    while( tokenPtr != NULL ) {
        if ( (value = strtod( tokenPtr, &rem )) != 0 ) {
            break;
        } // end if
        tokenPtr = strtok( NULL, " " );
    } // end while

    // check the text semantics
    if ( ( *unit1 == '\0' || *unit2 == '\0' || tokenPtr == NULL ) || ( a == b && c == d ) || !( ( a == b || a == 0 && b == 6 ) || ( (a == 1 || a == 2) && (b == 7 || b == 8 || b == 1 || b == 2) ) || ( ( a == 7 || a == 8 ) && ( b == 1 || b == 2 || b == 7 || b == 8) ) || ( a == 3 && b == 9 ) || ( (a == 4 || a == 5) && (b == 10 || b == 11 || b == 4 || b == 5 ) ) || ( ( a == 10 || a == 11 ) && ( b == 4 || b == 5 || b == 10 || b == 11 ) ) ) ) {
        printf( "\n%s\n", "Your statement is meaningless");
        return -1;
    } // end if

    // find which unit the value belongs
    if ( ( rem < unit1Ptr && rem > unit2Ptr ) || ( rem < unit1Ptr && unit1Ptr < unit2Ptr ) ) { //if the remainder to strtod is less than first unit pointer; then the value is of the first unit
        values[a][c] = value; // convert to second unit

        // Transfer the present value to the required unit
        if ( a != b )
            transfer( standard_values, values, &a, &c, b ); 
        
        // Then convert the transferred value
        value = convert( standard_values, values, a, c, b, d );
        printf( "\nANS: %lf %s%s", value, strcmp( unit2, "feet" ) == 0 ? value > 1 ? unit2 : "foot" : unit2, strcmp( unit2, "feet" ) == 0 ? "" : value > 1 ? "s": "" );
    } // end if
    else {
        values[b][d] = value; // convert to first unit

        // Transfer the present value to the required unit
        if ( a != b )
            transfer( standard_values, values, &b, &d, a ); 
        
        // Then convert the transferred value
        value = convert( standard_values, values, b, d, a, c );
        printf( "\nANS: %lf %s%s", value, strcmp( unit1, "feet" ) == 0 ? value > 1 ? unit1 : "foot" : unit1, strcmp( unit1, "feet" ) == 0 ? "" : value > 1 ? "s": "" );
    } // end else
    return 0; // indicate termination successful
} /* end main */
// Transfer the unit with a value to a unit without a value
void transfer( const double sv[][10], double v[][10], int * i, int * j, const int m ) {
    int f = 0;  // standard unit position of froUnit
    int t = 0;  // standard unit position of toUnit
    double sCFT = 0; // standard unit value for conversion btn froUnit and toUnit
    double sVF = 0; // standard unit value of froUnit

    if ( *i == 0 && m == 6 ) { // metric length to imperial length conversion
        f = 3;  // standard unit position for metric length: millimeter
        t = 0;  // standard unit position for non-metric length: inches
        sCFT = 1/25.4;  // 1 millimeter == (1/25.4) inch
    } // end if
    else if ( *i == 6 && m == 0 ) { // Imperial length to metric length conversion
        f = 0;  // standard unit imperial length: inch
        t = 3;  // standard unit position for metric: millimeter
        sCFT = 25.4;  // 1 inch == 25.4 millimeters
    } // end else if
    else if ( ( *i == 1 || *i == 2) && ( m == 7 || m == 8 || m == 1 || m == 2 ) ) { // metric area to imperial area conversion or metric to metric
        if ( *i == 1 && m == 7 ) {
            f = 1;  // standard unit position of metric area: square centimeter
            t = 0;  // standard unit position of non-metric area: square inches
            sCFT = 1/6.452;  // 1 square centimeter == 1/6.452 square inches
        } // end if
        else if ( *i == 1 && m == 8 ) {
            f = 2;  // standard unit position of metric area: square meter
            t = 0;  // ... position for square yard
            sCFT = 1/0.836;  // 1 square meter == 1/ 0.836 square yard
        } // end else if
        else if ( *i == 2 && m == 7 ) {
            f = 0; // standard unit position of metric area: square meter
            t = 2;  // position of square yard
            sCFT = 1/0.836; // 1 square meter == 1/0.836 square yard
        } // end else if
        else if ( *i == 2 && m == 8 ) { // if *i == 2 and m == 8
            f = 0; // standard unit position of metric area: square meter
            t = 0; // position of square yard
            sCFT = 1/0.836; // 1 square meter == 1 / 0.836 square yard
        } // end else
        else if ( *i == 1 && m == 2 ) {
            f = 3; // position for square meter
            t = 0;  // position for square meter
            sCFT = 1;   // the same value
        } // end else if
        else if ( *i == 2 && m == 1 ) {
            f = 0;  // position for square meter
            t = 3;  // position for square meter
            sCFT = 1;   // the same value
        } // end else if
    } // end else if
    else if ( ( *i == 7 || *i == 8 ) && ( m == 1 || m == 2 || m == 7 || m == 8 ) ) { // imperial area to metric area conversion or imperial to imperial
        if ( *i == 7 && m == 1 ) {
            f = 0;  // position for square inch
            t = 1;  // position for square centimeter
            sCFT = 6.452;   // 1 sq inch == 6.452 sq centimeters
        } // end if
        else if ( *i == 7 && m == 2 ) {
            f = 2;  // position of square yard
            t = 0; // standard unit position of metric area: square meter
            sCFT = 0.836; // 1 square yard == 0.836 square meter
        } // end else if
        else if ( *i == 8 && m == 1 ) {
            f = 0;  // ... position for square yard
            t = 2;  // standard unit position of metric area: square meter
            sCFT = 0.836;  // 1 square yard == 0.836 square meter
        } // end else if
        else if ( *i == 8 && m == 2 ) {  // if *i == 8 && m == 2
            f = 0; // position of square yard
            t = 0; // standard unit position of metric area: square meter
            sCFT = 0.836; // 1 square yard == 0.836 square meter
        } // end else if
        else if ( *i == 7 && m == 8 ) {
            f = 2;  // position of square yard
            t = 0;  // position of square yard
            sCFT = 1;   // both are equal
        } // end else if
        else if ( *i == 8 && m == 7 ) {
            f = 0;  // position of square yard
            t = 2;  // position of square yard
            sCFT = 1;   // both are equal
        } // end else if
    } // end else if
    else if ( *i == 3 && m == 9 ) { // metric weight to imperial weight conversion
        f = 3; // position of gram
        t = 1;  // position of ounce
        sCFT = 1/28.35; // 1 gram = 1/28.35 ounce
    } // end else if
    else if ( *i == 9 && m == 3 ) { // imperial weight to metric weight conversion
        f = 1;  // position of ounce
        t = 3;   // position of gram
        sCFT = 28.35;   // 1 ounce == 28.35 grams
    } // end else if
    else if ( ( *i == 4 || *i == 5 ) && ( m == 10 || m == 11 || m == 4 || m == 5 ) ) { // metric capacity to imperial capacity conversion or metric to metric capacity
        if ( *i == 4 && m == 10 ) {
            f = 3; // position of liter
            t = 1; // position for pint
            sCFT = 1/0.568; // 1 liter = 1/0.568 pint
        } // end if
        else if ( *i == 4 && m == 11 ) {
            f = 3; // position for liter
            t = 1;  // position for us pint
            sCFT = 1/0.473; // 1 liter = 1/0.473 us pint
        } // end else if
        else if ( *i == 5 && m == 10 ) {
            f = 1; // position for cubic centimeter
            t = 1;  // position for pint
            sCFT = 1/568.2613; // 1 cubic centimeter = 1/568.2613 pint
        } // end else if
        else if ( *i == 5 && m == 11 ) { 
            f = 1;  // position for cubic centimeter
            t = 1;  // position for us pint
            sCFT = 1/473.1765; // 1 cubic centimeter = 1/473.1765 us pint
        } // end else if
        else if ( *i == 4 && m == 5 ) {
            f = 3;  // position for liter
            t = 1;  // position for cubic centimeter
            sCFT = 1000; // 1 liter = 1000 cubic centimeters
        } // end else if
        else if ( *i == 5 && m == 4 ) {
            f = 1;  // position for cubic centimeter
            t = 3;  // position for liter
            sCFT = 1/1000;  // 1 cubic centimeter = 1/1000 liter
        } // end else if
    } // end else if
    else if ( (*i == 10 || *i == 11) && (m == 4 || m == 5 || m == 10 || m == 11 ) ) {  // imperial capacity to metric capacity conversion or imperial to imperial
        if ( *i == 10 && m == 4 ) {
            f = 1; // position for pint
            t = 3; // position of liter
            sCFT = 0.568; // 1 pint = 0.568 liter
        } // end if
        else if ( *i == 10 && m == 5 ) {
            f = 1;  // position for pint
            t = 1; // position for cubic centimeter
            sCFT = 568.2613; // 1 pint = 568.2613 cubic centimeters
        } // end else if
        else if ( *i == 11 && m == 4 ) {
            f = 1;  // position for us pint
            t = 3; // position for liter
            sCFT = 0.473; // 1 us pint = 0.473 liter
        } // end else if
        else if ( *i == 11 && m == 5 ) { // if 
            f = 1;  // position for us pint
            t = 1;  // position for cubic centimeter
            sCFT = 473.1765; // 1 us pint = 473.1765 cubic centimeters
        } // end else if
        else if ( *i == 10 && m == 11 ) {
            f = 1;  // position for pint
            t = 1;  // position for us pint
            sCFT = 1.20095;  // 1 pint = 1.20095 us pint
        } // end else if
        else if ( *i == 11 && m == 10 ) {
            f = 1;  // position for us pint
            t = 1;  // position for pint
            sCFT = 1/1.20095;   // 1 us pint = 1/1.20095 pint
        }   // end else if
    } // end else

    // convert to the standard unit value of froUnit
    sVF = convert( sv, v, *i, *j, *i, f );
    // transfer to the toUnit 
    v[*i = m][*j = t] = sVF * sCFT; 

    return; // indicate termination successful
} /* end function transfer */
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
char * recon( const char * request, const char * std[][10], int * sub, int * sub2 ) {
    char * unit = "";
    char * ptr = "";
    char * ptr2 = "";
    int i = 0;  // unit controller
    int j = 0;  // unit position controller
    size_t k = 0;       // pointer unit skipper
    
    i = *sub;
    for ( ; i < 12; i++ ) {
        if (j == 10) // if j == 10 assign zero
            j = 0; 
        else
            j = *sub2;

        for ( ; j < 10; j++ ) {
            if ( ( (ptr = strstr( request, std[i][j] ) ) != NULL) && *std[i][j] != '\0' ) {
                // whatch if there is a space after a unit and there isn't any letter joined
                if ( !isalpha( *( --ptr ) ) || isblank( *ptr )  ) {
                    ++ptr; // restore the pointer's location
                    unit = std[i][j];
                    *sub = i;
                    *sub2 = j;
                    return unit;
                } // end if
                else if ( isalpha( *( ptr ) ) ) { 
                    ++ptr; // restore the pointer's location
                    // reallocate the position
                    while( std[i][j][k] != '\0' ) {
                        k++; ptr++;
                    } // end while
                    if( ( ptr2 = strstr( ptr, std[i][j] ) ) != NULL ) {
                        // whatch if there is a space after a unit and there isn't any letter joined
                        if ( !isalpha( *( --ptr2 ) ) || isblank( *ptr2 )  ) {
                            ++ptr2;
                            unit = std[i][j];
                            *sub = i;
                            *sub2 = j;
                            return unit;
                        } // end if
                    } // end if
                } // end else if
            } // end if
        } // end for
    } // end for
    return NULL; // indicate unit not found
} /* end function recon */