/*
    theBitRiddler
    2/8/2024
    8:50 PM
    8.35 (Word Processing)
    The detailed treatment of string manipulation in this text is greatly attributable to the exciting growth
in word processing in recent years. One important function in word processing systems is type-justification—the alignment of words
to both the left and right margins of a page. This generates a professional-looking document that gives the appearance of being set
in type, rather than prepared on a typewriter. Type-justification can be accomplished on computer systems by inserting one or more
blank characters between each of the words in a line so that the rightmost word aligns with the right margin.
    Write a program that reads several lines of text and prints this text in type-justified format. Assume that the text is to be
printed on 8 1/2-inch-wide paper and that one-inch margins are to be allowed on both the left and right sides of the printed page.
Assume that the computer prints 10 characters to the horizontal inch. Therefore, your program should print 6 1/2 inches of text or
65 characters per line.
*/
#include <stdio.h>
#define LINES 3
int main( void ) {
    char text[LINES][65] = {""};

    return 0; // indicate successful termination
} /* end main */