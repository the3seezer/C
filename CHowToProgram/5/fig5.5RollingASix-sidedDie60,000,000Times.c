#include <stdio.h>
#include <stdlib.h>

int main(void){
	int freq1 = 0;
	int freq2 = 0;
	int freq3 = 0;
	int freq4 = 0;
	int freq5 = 0;
	int freq6 = 0;
	for(int i = 1;i <= 60000000;i++){
		int face = 1 + rand() % 6;
		switch(face){
			case 1:
				freq1++;
				break;
			case 2:
				freq2++;
				break;
			case 3:
				freq3++;
				break;
			case 4:
				freq4++;
				break;
			case 5:
				freq5++;
				break;
			case 6:
				freq6++;
				break;
		}
	}
	printf("%s%13s\n","Face","Frequency");
	printf("1%13d\n",freq1);
	printf("2%13d\n",freq2);
	printf("3%13d\n",freq3);
	printf("4%13d\n",freq4);
	printf("5%13d\n",freq5);
	printf("6%13d\n",freq6);
}
