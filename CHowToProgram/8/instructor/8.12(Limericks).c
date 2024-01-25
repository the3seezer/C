/*The article array should contain the articles "the", "a", "one", "some" and
"any"; the noun array should contain the nouns "boy", "girl", "dog", "town" and "car"; the verb array should contain the
verbs "drove", "jumped", "ran", "walked" and "skipped"; the preposition array should contain the prepositions "to",
"from", "over", "under" and "on". */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<time.h>
#include <stdlib.h>

void line( char **, char **, char **, char **, char *, size_t *, size_t *, int );
void choose( size_t *, size_t * );
int main ( void ) {
    srand( time(NULL));
    char *articles[] = { "the", "a", "one", "some", "any" };
    char *nouns[] = { "boy", "girl", "dog", "town", "car" };
    char *verbs[] = { "drove", "jumped", "ran", "walked", "skipped" };
    char *prepositions[] = { "to", "from", "over", "under", "on" };
    char sentence[100] = "";
    size_t first = 0; // first verse
    size_t third = 0; // third verse

    // create 100 sentences
    for (int i = 0; i < 100; i++ ) {
        printf( "%s",i && i % 5 == 0 ? "\n\n" : i ? "\n" : ""  );
        line( articles, nouns, verbs, prepositions, sentence, &first, &third, i % 5 );
    } // end for

    return 0; // indicate termination successful
} /* end main */

void choose( size_t *f, size_t *t ) {

    if ( *f != *t ) // terminate the recursion
        return;

    *f = rand() % 5;
    *t = rand() % 5;

    choose( f, t );

} /* end function choose */

void line( char ** a, char ** n, char **v, char **p, char * s, size_t *f, size_t *t, int lime ) {

        // Choose the limes and arrange them
        if ( lime == 0 ) {
            *f = 0; *t = 0;
            choose( f, t );
        } // end if

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

        strcat( s, n[ lime == 2 || lime == 3 ? *t : *f  ] ); // set the limes 

        // Capitalize the first letter and print sentence
        putchar( toupper( s[ 0 ] ) );
        printf( "%s.", &s[ 1 ] );
        s[ 0 ] = '\0';

        return;
} /* end function sentence */