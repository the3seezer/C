 // fig06_01.c
 // Initializing the elements of an array to zeros.
 #include <stdio.h>

 // function main begins program execution
 int main(void) {
 int n[5]; // n is an array of five integers
 
 // set elements of array n to 0 
 for (size_t i = 0; i < 5; ++i) { 
 n[i] = 0; // set element at location i to 0
} 

printf("%s%8s\n", "Element", "Value");

// output contents of array n in tabular format
for (size_t i = 0; i < 5; ++i) { 
printf("%7zu%8d\n", i, n[i]); 
 } 
 }
