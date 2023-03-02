// theBitRiddler
// 1/4/2023
// 8:16 AM
//  (Airline Reservations System)
#include <stdio.h>
#define SIZE 10

enum Seats {
	FULL, EMPTY
};
enum Plane {
	BOTH_FULL, STILL_EMPTY, STOP
};

void printArray(const int b[], size_t size);

int main(void) {
	int decide = 0;
	int seats[SIZE] = {0};
	int seatClass = 0;
	int full_first_class = 0;
	int full_economy = 0;
	
	enum Seats firstClassSeatStatus = EMPTY;
	enum Seats economySeatStatus = EMPTY;
	enum Plane classStatus = STILL_EMPTY;
	
	puts("Please type 1 for \"first class\"\nPlease type 2 for \"economy\"");
	scanf("%d", &seatClass);
	
	while (classStatus == STILL_EMPTY) {
		int firstClassFlag = 0; // when someone tries to choose a full first Class
		int economyFlag = 0; // when someone tries to choose a full economy class
		switch(seatClass) {
			case 1:
				for (size_t i = 0; i < 5; ++i) {
					if (full_first_class == 5) {
						firstClassSeatStatus = FULL;
						firstClassFlag = 1;
					}
					
					if (seats[i] == 0) {
						seats[i] = 1;
						++full_first_class;
						if (full_first_class == 5) {
							firstClassSeatStatus = FULL;
						}
						break;
					}
				}	
				break;
			case 2:
				for (size_t i = 5; i < SIZE; ++i) {
					if (full_economy == 5) {
						economySeatStatus = FULL;
						economyFlag = 1;
					}
					
					if (seats[i] == 0) {
						seats[i] = 1;
						++full_economy;
						if (full_economy == 5) {
							economySeatStatus = FULL;
						}
						break;
					}
				}
				break;
		}
		
		if (economySeatStatus == EMPTY && firstClassSeatStatus == EMPTY) {
			puts("Please type 1 for \"first class\"\nPlease type 2 for \"economy\"");
			scanf("%d", &seatClass);
		}
		
		if (firstClassSeatStatus == FULL && economySeatStatus == EMPTY) {
			if (seatClass == 2) {
				puts("Please type 2 for economy");
				scanf("%d", &seatClass);
			}
			if (seatClass == 1) {
				if (firstClassFlag == 1) {
					puts("Sorry, First Class is full. Can you take the economy class?\ny == yes, n == no");
					decide = getchar();
					scanf("%c", &decide);
					switch(decide){
						case 'y':
							seatClass = 2;
							break;
						case 'n':
							classStatus = STOP;
							break;
					}
				}
			}
		}
		
		if (economySeatStatus == FULL && firstClassSeatStatus == EMPTY) {
			if (seatClass == 1) {
				puts("Please type 1 for first class");
				scanf("%d", &seatClass);
			}
			if (seatClass == 2) {
				if (economyFlag == 1) {
					puts("Sorry, Economy is full. Can you take the first class?\ny == yes, n == no");
					decide = getchar();
					scanf("%c", &decide);
					switch(decide){
						case 'y':
							seatClass = 1;
							break;
						case 'n':
							classStatus = STOP;
							break;
					}
				}
			}	
		}
		
		if (economySeatStatus == FULL && firstClassSeatStatus == FULL) {
			classStatus = BOTH_FULL;
		}	
	}
	
	if (classStatus == BOTH_FULL || classStatus == STOP) {
		puts("\"Next flight leaves in 3 hours.\"");
	}
}
