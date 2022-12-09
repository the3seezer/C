// theBitRiddler
// 12/8/2022
// 8:35am
/*  Survey data analysis with arrays: computing the mean, median and mode of the 
data. */
#include <stdio.h>
#define SIZE 99

void mean(const int answer[]);
void median(int answer[]);
void mode(int freq[], const int answer[]);
void bubbleSort(int a[]);
void printArray(const int a[]);

// Begins programs execution
int main(void) {
	int frequency[10] = {0};
	
	int response[SIZE] = 
	   {6, 7, 8, 9, 8, 7, 8, 9, 8, 9,
		7, 8, 9, 5, 9, 8, 7, 8, 7, 8,
		6, 7, 8, 9, 3, 9, 8, 7, 8, 7,
		7, 8, 9, 8, 9, 8, 9, 7, 8, 9,
		6, 7, 8, 7, 8, 7, 9, 8, 9, 2,
		7, 8, 9, 8, 9, 8, 9, 7, 5, 3,
		5, 6, 7, 2, 5, 3, 9, 4, 6, 4,
		7, 8, 9, 6, 8, 7, 8, 9, 7, 8,
		7, 4, 4, 2, 5, 3, 8, 7, 5, 6,
		4, 5, 6, 1, 6, 5, 7, 8, 7};
	
	// process responses
	mean(response);
	median(response);
	mode(frequency,response);
}

// calculates average of all responses
void mean(const int answer[]) {
	printf("%s\n%s\n%s\n", "--------", "   Mean", "--------");
	
	int total = 0;
	for (size_t j = 0; j < SIZE; ++j) {
		total += answer[j];
	}
	
	printf("The mean is the average value of the data\n"
		   "items, The mean is equal to the total of\n"
		   "all the data items divided to the number\n"
		   "of data items (%u). The mean value for\n"
		   "this run is: %u / %u = %.4f\n\n",
		   SIZE, total, SIZE, (double) total / SIZE);
}

// sorts array and determines median element's value
void median(int answer[]) {
	printf("%s\n%s\n%s\n%s", "--------", "  Median", "--------",
		   "The unsorted array of responses is");
		   
		   printArray(answer);// unsorted
		   
		   bubbleSort(answer);// sorted
		   
		   printf("%s","\n\nThe sorted array is");
		   printArray(answer);// outputs sorted array
		   
		   //Display median element
		   printf("\n\nThe median is element %u of\n"
		   		  "the sorted %u element array.\n"
				  "For this run the median is %u\n\n\n",
				  SIZE / 2, SIZE, answer[SIZE / 2]);
}

// determines most frequent response
void mode(int freq[], const int answer[]) {
	printf("\n%s\n%s\n%s\n", "--------", "    Mode", "--------");
	
	// initialize frequencies to zero
	for (size_t rating = 1; rating <= 9; ++rating) {
		freq[rating] = 0;
	}
	
	// summarize frequencies
	for (size_t j = 0; j < SIZE; ++j) {
		++freq[answer[j]];
	}
	
	//output headers for result columns
	printf("%s%11s%19s\n\n%54s\n%54s\n\n",
		   "Response", "Frequency", "Bar Chart",
		   "1    1    2    2", "5    0    5    0    5");
	
	//Output result
	int largest = 0;// represents largest frequency
	int modeValue = 0;// represents most frequent response
	
	for (size_t rating = 1; rating <= 9; ++rating) {
		printf("%8zu%11d          ", rating, freq[rating]);
		
		// keep track of mode value and largest frequency value
		if (freq[rating] > largest) {
			largest = freq[rating];
			modeValue = rating;
		}
		
		// output bar representing frequency value
		for (int h = 1; h <= freq[rating]; ++h) {
			printf("%s","*");
		}
		
		puts("");// Begin new line of output
	}
	
	// display the mode value
	printf("\nThe mode is the most frequent value.\n"
		   "For this run the mode is %u which occured %u times.\n",
		   modeValue, largest);
}

// function that sort array with bubble sort algorithm
void bubbleSort(int a[]) {
	// loop to control number of passes
	for (size_t pass = 1; pass < SIZE; ++pass) {
		// loop to control number of comparisons per passes
		for (size_t j = 0; j < SIZE - 1; ++j) {
			// swap elements if out of order
			if (a[j] > a[j + 1]) {
				int hold = a[j];
				a[j] = a[j + 1];
				a[j + 1] = hold;
			}
		}
	}
}

void printArray(const int a[]) {
	// output array content
	for (size_t j = 0; j < SIZE; ++j) {
		//Begin new line every 20 value
		if (j % 20 == 0) {
			puts("");
		}
		printf("%2d", a[j]);
	}
}
