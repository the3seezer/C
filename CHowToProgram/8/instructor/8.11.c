/*The article array should contain the articles "the", "a", "one", "some" and
"any"; the noun array should contain the nouns "boy", "girl", "dog", "town" and "car"; the verb array should contain the
verbs "drove", "jumped", "ran", "walked" and "skipped"; the preposition array should contain the prepositions "to",
"from", "over", "under" and "on". */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<time.h>
#include <stdlib.h>
int main ( void ) {
    srand( time(NULL));
    char *articles[] = { "the", "a", "one", "some", "any" };
    char *nouns[] = { "boy", "girl", "dog", "town", "car" };
    char *verbs[] = { "drove", "jumped", "ran", "walked", "skipped" };
    char *prepositions[] = { "to", "from", "over", "under", "on" };
    char sentence[100] = "";

    // create 20 sentences
    for (int i = 0; i < 20; i++ ) {

        // randomly choose pieces of sentence
        strcat( sentence, articles[ rand() % 5 ] );
        strcat( sentence, " " );

        strcat( sentence, nouns[ rand() % 5 ] );
        strcat( sentence, " ");

        strcat( sentence, verbs[ rand() % 5 ] );
        strcat( sentence, " ");

        strcat( sentence, prepositions[ rand() % 5 ] );
        strcat( sentence, " " );

        strcat( sentence, articles[ rand() % 5 ] );
        strcat( sentence, " " );

        strcat( sentence, nouns[ rand() % 5 ] );

        // Capitalize the first letter and print sentence
        putchar( toupper( sentence[ 0 ] ) );
        printf( "%s.\n", &sentence[ 1 ] );
        sentence[ 0 ] = '\0';
    } // end for

    return 0; // indicate termination successful
} /* end main */