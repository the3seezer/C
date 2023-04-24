/* 
 theBitRiddler
 4/25/2023
 12:47 AM
 Demorgan's laws
*/
#include <stdio.h>
int main(void) {
	int x = 10;
	int y = 9;
	int a = 8;
	int b = 7;
	int g = 6;
	int i = 5;
	int j = 4;
	
	printf("%s", "Current variable value are: \n");
	printf("x == %d, y == %d, a == %d, b == %d\n", x, y, a, b);
	printf("g == %d, i == %d and j == %d\n\n\n", g, i, j);
	
	if ( ( !(x < 5) && !(y >= 7) ) == !( (x < 5) || (y >= 7) ) ) {
		
		printf("%s", "!(x < 5) && !(y >= 7)  is equal to  !( (x < 5) || (y >= 7) )\n\n");
		
	}
	else {
		
		printf("%s", "!(x < 5) && !(y >= 7)  is not equal to  !( (x < 5) || (y >= 7) )\n\n");
		
	}
	
	if ( ( !(a == b) || !(g != 5) ) == !( (a == b) && (g != 5) ) ) {
		
		printf("%s", "!(a == b) || !(g != 5) is equal to !( (a == b) && (g != 5) )\n\n");
		
	}
	else {
		
		printf("%s", "!(a == b) || !(g != 5) is not equal to !( (a == b) && (g != 5) )\n\n");
		
	}
	
	if ( !( (x <= 8) && (y > 4) ) == ( !(x <= 8) || !(y > 4) ) ) {
		
		printf("%s", "!( (x <= 8) && (y > 4) ) is equal to !(x <= 8) || !(y > 4)\n\n");
		
	}
	else {
		
		printf("%s", "!( (x <= 8) && (y > 4) ) is not equal to !(x <= 8) || !(y > 4)\n\n");
		
	}
	
	if ( !( ( i > 4) || (j <= 6) ) == ( !(i > 4) && !(j <= 6) ) ) {
		
		printf("%s", "!( ( i > 4) || (j <= 6) ) is equal to !(i > 4) && !(j <= 6)\n\n");
		
	}
	else {
		
		printf("%s", "!( ( i > 4) || (j <= 6) ) is not equal to !(i > 4) && !(j <= 6)\n\n");
		
	}
}
