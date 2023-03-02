#include <stdio.h>
struct card {
	const char *face;
	const char *suit;
	int numb;//to option two
};
int main(){
	struct card myCard;
	
	myCard.face = "Diamonds";
	myCard.suit = "Spades";
	
	printf_s("%s of %s\n",myCard.suit,myCard.face);
	//option two
	struct card *ptr;
	ptr = &myCard;
	myCard.numb = 99;
	printf_s("The value is %d",ptr->numb);
	printf_s("The value is %d",myCard.numb);
	
}
