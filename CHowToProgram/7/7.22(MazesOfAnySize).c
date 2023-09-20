/*
theBitRiddler
9/20/2023
12:46 PM
 (Mazes of Any Size)
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMaze( char[][ COL_SIZE ]);

int main(void) { 
    int row_size = 0;
    int col_size = 0;
    puts("Enter size of row and column");
    scanf_s( "%d%d", &row_size, &col_size );

    #define ROW_SIZE rand() % 10 + 12;
    #define COL_SIZE rand() % 10 + 12;
    #define POSSIBLE_DOTS (int) ROW_SIZE * COL_SIZE * 2 / 3 
    
    maze[ ROW_SIZE ][ COL_SIZE ] = { 0 };

    
    return 0;
} /* end main */

#define ROW_SIZE 12
#define COL_SIZE 12
#define POSSIBLE_DOTS 100
