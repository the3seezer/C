// theBitRiddler
// 12/29/2022
// 10:34 PM
// Mean, Median, Mode Modifications
#include <stdio.h>
#define SIZE 108

void mean(const int b[], size_t size);
void median(int b[], size_t size);
void mode(int n_f[], int hz[], const int b[], size_t size);
void printArray(const int b[], size_t size);
void bubbleSort(int b[], size_t size);

int main(void) {
	int number_frequency[SIZE] = {0}; // number of frequency of rate values/ repeated rating values
	int frequency[10] = {0};
	int responses[SIZE] = 
	   {6, 7, 7, 7, 7, 7, 8, 9, 8, 7, 8, 9, 8, 9, 
		7, 8, 9, 5, 9, 8, 7, 8, 7, 8,
		6, 7, 8, 9, 3, 9, 8, 7, 8, 7,
		7, 8, 9, 8, 9, 8, 9, 7, 8, 9,
		6, 7, 8, 7, 8, 7, 9, 8, 9, 2, 2,
		7, 8, 9, 8, 9, 8, 9, 7, 5, 3,
		5, 6, 7, 2, 5, 3, 9, 4, 6, 4,
		7, 8, 9, 6, 8, 7, 8, 9, 7, 8,
		7, 4, 4, 2, 5, 3, 8, 7, 5, 6,
		4, 5, 6, 1, 1, 1, 1, 6, 5, 7, 8, 7, 9}; /*, 9, 9, 9, 9, 9, 9, 9 */ /*, 7, 7, 7, 7, */ /* , 1, 1, 1 */ // 2
	
	puts("Original array order");
	printArray(responses, SIZE);
	mean(responses, SIZE);
	median(responses, SIZE);
	mode(number_frequency, frequency, responses, SIZE);
}

void printArray(const int b[], size_t size) {
	for (size_t i = 0; i < size; ++i) {
		if(i % 20 == 0) {
			puts("");
		}
		printf("%4d", b[i]);
	}
}

void mean(const int b[], size_t size) {
	int total = 0;
	for (size_t i = 0; i < size; ++i) {
		total += b[i];
	}
	printf("\nAverage: %d", total / size);
}

void bubbleSort(int b[], size_t size) {
	int de = 1;
	// loop through pass
	for (int pass = 1; pass < size; ++pass) {
		int flag = 0;
		// loop through comparisons
		for (int i = 0; i < size - de; ++i) {
			if (b[i] > b[i + 1]) {
				int hold = b[i];
				b[i] = b[i + 1];
				b[i + 1] = hold;
				flag++;
			}
		}
		if (flag) {
			de++;
		}
		else {
			break;
		}
	}
}

void median(int b[], size_t size) {
	puts("\n\n\nascending order");
	bubbleSort(b, size);
	printArray(b, size);
	printf("\nMedian:%.2f", (size % 2 == 0)? (double)(b[size / 2] + b[size / 2 + 1]) / 2 : (double)b[size / 2] );
}

void mode(int n_f[], int hz[], const int b[], size_t size) {
	for (size_t i = 0; i < size; ++i) {
		n_f[i] = 0; // initialize mode frequency to zero
	}
	for (size_t i = 0; i < 10; ++i) {
		hz[i] = 0; // initialize frequency to zero
	}
	
	for (size_t i = 0; i < size; ++i) {
		++hz[b[i]]; // get frequency
	}		
	int largest = 0;
	int modeValue = 0;
	
	int hold_frequency = 0;
	int mode_type = 1;
	puts("");
	for (int rating = 1; rating <= 9; ++rating) {
		++n_f[hz[rating]]; //get number of repeated rating frequency
		hold_frequency = n_f[hz[rating]]; // to hold the value of each number frequency
		
		if (hz[rating] > largest) {
			largest = hz[rating];
			modeValue = rating;
		}
		if (hold_frequency == 2) { //get if its bimodal
			mode_type = 2;
		}
		if (hold_frequency > 2) { // get the largest mode type
			mode_type = hold_frequency;
		}
		
		for (int j = 1; j <= hz[rating]; ++j) {
			printf("%s", "*");
		}
		puts("");
	}
	
	
	
	if (mode_type == 1) {
		printf("Mode:%d\nFrequency:%d times", modeValue, largest);
	}
	else if (mode_type == 2) {
		printf("Bimodal:%d\nModes are:", mode_type);
		for (size_t rating = 1; rating <= 9; ++rating) {
			if (largest == hz[rating]) {
				printf("%zu ", rating);
			}
		}
		printf("\nFrequency:%d times", largest);
	}
	else if (mode_type > 2) { // multimodal
		printf("Multimodal:%d\nModes are:", mode_type);
		for (size_t rating = 1; rating <= 9; ++rating) {
			if (largest == hz[rating]) {
				printf("%zu ", rating);
			}
		}
		printf("\nFrequency:%d times", largest);
	}
}
