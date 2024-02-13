#include <stdio.h>
int main( void ) {
    char *month[13] = { "", "January", "February", "March", "April", "May", "June",
                       "July", "August", "September", "October", "November", "December" };
    
    int m = 0;
    int d = 0;
    int y = 0;

    printf( "%s", "Enter a date in form mm/dd/yyyy: ");
    scanf( "%d/%d/%d", &m, &d, &y );

    printf( "The date is %s %d, %d\n", month[m], d, y );

    return 0; // indicate successful termination
} /* end main */