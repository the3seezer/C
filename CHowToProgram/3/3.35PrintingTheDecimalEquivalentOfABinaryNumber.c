#include <stdio.h>
int main(void){
	int binary = 0;
	int counter = 1;
	int decimal = 0;
	int p_value = 1;
	printf_s("%s","print a five or less digit binary number\n");
	scanf_s("%d",&binary);
	int preserve = binary;//preserve the original number
	while(counter <= 5){
		int remainder = binary % 10;
		int decimal_p = remainder * p_value;
		decimal = decimal + decimal_p;
		binary /= 10;
		p_value *= 2;
		counter++;
	}
	printf_s("%d :binary\n%d :decimal",preserve,decimal);
	
}
