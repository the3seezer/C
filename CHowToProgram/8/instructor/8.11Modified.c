/*The article array should contain the articles "the", "a", "one", "some" and
"any"; the noun array should contain the nouns "boy", "girl", "dog", "town" and "car"; the verb array should contain the
verbs "drove", "jumped", "ran", "walked" and "skipped"; the preposition array should contain the prepositions "to",
"from", "over", "under" and "on". */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<time.h>
#include <stdlib.h>

void line( char **, char **, char **, char **, char *);
int main ( void ) {
    srand( time(NULL));
    char *articles[] = { "the", "a", "one", "some", "any" };
    char *nouns[] = { "boy", "girl", "dog", "town", "car" };
    char *verbs[] = { "drove", "jumped", "ran", "walked", "skipped" };
    char *prepositions[] = { "to", "from", "over", "under", "on" };
    char sentence[100] = "";

    // create 20 sentences
    for (int i = 0; i < 100; i++ ) {
        printf( "%s", i % 20 == 0 ? i ? "\n\t" : "\t" : " "  );
        line( articles, nouns, verbs, prepositions, sentence );
    } // end for

    return 0; // indicate termination successful
} /* end main */

void line( char ** a, char ** n, char **v, char **p, char * s ) {
    
        // randomly choose pieces of sentence
        strcat( s, a[ rand() % 5 ] );
        strcat( s, " " );

        strcat( s, n[ rand() % 5 ] );
        strcat( s, " ");

        strcat( s, v[ rand() % 5 ] );
        strcat( s, " ");

        strcat( s, p[ rand() % 5 ] );
        strcat( s, " " );

        strcat( s, a[ rand() % 5 ] );
        strcat( s, " " );

        strcat( s, n[ rand() % 5 ] );

        // Capitalize the first letter and print sentence
        putchar( toupper( s[ 0 ] ) );
        printf( "%s.", &s[ 1 ] );
        s[ 0 ] = '\0';

        return;
} /* end function sentence */