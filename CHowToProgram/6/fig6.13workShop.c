// theBitRiddler
// 12/11/2022
// 7:49 PM
// the work shop of mean, median, mode
#include <stdio.h>
#define SIZE 99

void mean(const int answer[]);
void median(int answer[]);
void mode(int freq[], const int answer[]);
void printArray(const int a[]);
void bubbleSort(int a[]);

int main(void) {
	int frequency[10] = {0};
	int response[SIZE] = 
	{
		6, 7, 8, 9, 8, 7, 8, 9, 8, 9,
	 	7, 8, 9, 5, 9, 8, 7, 8, 7, 8,
	 	6, 7, 8, 9, 3, 9, 8, 7, 8, 7,
	 	7, 8, 9, 8, 9, 8, 9, 7, 8, 9,
	 	6, 7, 8, 7, 8, 7, 9, 8, 9, 2,
	 	7, 8, 9, 8, 9, 8, 9, 7, 5, 3,
	 	5, 6, 7, 2, 5, 3, 9, 4, 6, 4,
	 	7, 8, 9, 6, 8, 7, 8, 9, 7, 8,
	 	7, 4, 4, 2, 5, 3, 8, 7, 5, 6,
	 	4, 5, 6, 1, 6, 5, 7, 8, 7
	};
	mean(response);
	median(response);
	mode(frequency, response);
}

// find average
void mean(const int answer[]) {
	double total = 0;
	for (size_t i = 0; i < SIZE; ++i) {
		total += answer[i];
	}
	printf("The average is: %.4f\n",total / SIZE);
}

// find the middle value in ascending order
void median(int answer[]) {
	puts("This is the original array;");
	printArray(answer);
	puts("\nThe sorted array");
	bubbleSort(answer);
	printArray(answer);
	printf("\nThe median is %u\n", answer[SIZE / 2]);
}

void mode(int freq[],const int answer[]) {
	for (size_t responses = 0; responses < SIZE; ++responses) {
		++freq[answer[responses]];
	}
	
	int mode = 0;// mode/ most frequent response
	int modeValue = 0;// number of response
	// sort them
	// bubbleSort(freq); bubble sort size is larger than that of frequencies size
	// bar chart
	printf("%s%14s\n","\nRating","bar");
	for (size_t rating = 1; rating < 10; ++rating) {// There is no zero rating, so cut off zero 
		printf("%6u%11s", rating, "");
		// the bar graph
		for (int i = 1; i <= freq[rating]; ++i) {
			printf("*");
		}
		puts("");
		if (freq[rating] > modeValue) { // printf("Value %u ",freq[rating]);puts("");
			modeValue = freq[rating];
			mode = rating;
		}
	}
	printf("\nThe mode is %u which came %u times\n", mode, modeValue);
}

void printArray(const int a[]) {
	for (size_t i = 0; i < SIZE; ++i) {
		if (i % 20 == 0) {
			puts("");
		}
		printf("%4u",a[i]);
	}
}

void bubbleSort(int a[]) {
	for (size_t pass = 1; pass < SIZE; ++pass) {
		for (size_t i = 0; i < SIZE - 1; ++i) {
			if (a[i] > a[i + 1]) {
				int hold = a[i];
				a[i] = a[i + 1];
				a[i + 1] = hold;
			}
		}
	}
}
