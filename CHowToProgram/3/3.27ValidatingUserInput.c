// fig03_06.c
 // Analysis of examination results.
 #include <stdio.h>

 // function main begins program execution 
 int main(void) {
 // initialize variables in definitions 
 int passes = 0; 
 int failures = 0; 
 int student = 1; 

 // process 10 students using counter-controlled loop 
 while (student <= 10) {
 // prompt user for input and obtain value from user 
 printf("%s", "Enter result (1=pass,2=fail): ");
 int result = 0; // one exam result 
 scanf("%d", &result);

 // if result 1, increment passes 
 if (result == 1) { 
 passes = passes + 1;
 student = student + 1; // increment student counter 
 } // end if 
 else if (result == 2) { // otherwise, increment failures 
 failures = failures + 1;
 student = student + 1; // increment student counter 
 } // end else 
 
 } // end while 

 // termination phase; display number of passes and failures 
 printf("Passed %d\n", passes);
 printf("Failed %d\n", failures);

 // if more than eight students passed, print "Bonus to instructor!"
 if (passes > 8) {
 puts("Bonus to instructor!");
 } // end if 
 } // end function main 
