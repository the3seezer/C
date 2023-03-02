// theBitRiddler
// 12/22/2022
// 10:18 PM
// Exercise 6.8 (e) and (f)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int doing(int even, int odd, int static_even, int static_odd);
void undo(int do_even, int static_do_odd, int do_static_even, int static_do_static_odd);

int main(void) { 
	int even = 2;
	int odd = 1;
	static int static_even = 4;
	static int static_odd = 3;
	
	for (int i = 0; i < 10; ++i) {
		doing(even, odd, static_even, static_odd);
	}
}

int doing(int even, int odd, int static_even, int static_odd) {
	int do_even = 0;
	static int static_do_odd = 0;
	int do_static_even = 0;
	static int static_do_static_odd = 0;
	
	do_even += even;
	static_do_odd += odd;
	do_static_even += static_even;
	static_do_static_odd += static_odd;
	
}

void undo(int do_even, int static_do_odd, int do_static_even, int static_do_static_odd) {
	static int size = 0;
	++size;
	int undo_do_even[size] = {0};
	int undo_static_do_odd[size] = {0};
	int undo_do_static_even[size] = {0};
	int undo_static_do_static_odd[size] = {0};
	
	undo_do_even[size - 1] = do_even;
	undo_static_do_odd[size - 1] = static_do_odd;
	undo_do_static_even[size - 1] = do_static_even;
	undo_static_do_static_odd[size - 1] = static_do_static_odd;
	if (size) {
		size--;
		undo(undo_do_even[size - 1], undo_static_do_odd[size - 1], undo_do_static_even[size - 1], undo_static_do_static_odd[size - 1]);
	}
}
