#include <stdio.h>
int main(){
	int passed = 0;
	int failed = 0;
	int students = 1;
	
	while(students <= 10){
		int results = 0;
		puts("Enter results: 1 for passes and 2 for failules");
		scanf("%d",&results);
		if(results == 1){
			passed = passed + 1;
		}
		else{
			failed = failed + 2;
		}
		students = students + 1;
	}
	printf("Passes: %d\n",passed);
	printf("Failures: %d\n",failed);
	if(passed >= 8){
		puts("bonus to an instructor!");
	}
}
