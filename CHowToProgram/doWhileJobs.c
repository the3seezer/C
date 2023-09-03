// theBitRiddler
// 1/24/2023
// 11:51 AM
// Undo workShop
#include <stdio.h>
int main(void) {
    int draw = 0;
	do {
        printf_s( "%s", "Print 1 to draw any card; one, two or three cards or 2 to continue\n" );
        scanf( "%d", &draw );
    }
    while ( draw < 1 || draw > 2 );
    puts("done");
}
