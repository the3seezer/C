#include <stdio.h>
int main(void) {
	char mystr[20] = "";

	scanf_s("%19s", mystr, 20);
	printf("%s", mystr);

	// sscanf_s( "%19s", mystr, 20 );
	// printf_s( "%s", mystr );

} /* end main */
