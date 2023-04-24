/*
 theBitRiddler
 11:49 PM
 4/24/2023
 PayCode, Managers, hWorkers, cWorkers, pworkers and Pieces
 
*/
#include <stdio.h>
int main(void) {
	int payCode = 0;
	int managers = 0;
	int hWorkers = 0;
	int cWorkers = 0;
	int pWorkers = 0;
	int pieces = 0;
	double mSalary = 0;
	double hSalary = 0;
	double cSalary = 0;
	double pSalary = 0;
	double hours = 0;
	double otHours = 0;
	double pay = 0;
	double otPay = 0;
	
	printf("%s", "Enter pay code (-1 to end): ");
	scanf("%d", &payCode);
	
	while (payCode != -1) {
		
		switch (payCode) {
			case 1:
				
				printf("%s", "Manager selected\n");
				printf("%s", "Enter weekly salary: ");
				scanf("%lf", &mSalary);
				
				printf("Manager's pay is $%.2f\n", mSalary);
				
				++managers;
				
				break;
				
			case 2:
				
				printf("%s", "Hourly worker selected\n");
				printf("%s", "Enter hourly salary: ");
				scanf("%lf", &hSalary);
				
				printf("%s", "Enter total hours worked: ");
				scanf("%lf", &hours);
				
				if (hours > 40.0) {
					
					otHours = hours - 40.0;
					otPay = hSalary * 1.5 * otHours + hSalary * 40;
					
					printf("worker has worked %f overtime hours\n", otHours);
					printf("Worker's pay is $%f.2\n", otPay);
					
				}
				else {
					pay = hSalary * hours;
					printf("Worker's pay is $%.2f\n", pay);
				}
				
				++hWorkers;
				
				break;
				
			case 3:
				
				printf("%s", "Commission worker selected\n");
				printf("%s", "Enter gross weekly pay: ");
				scanf("%lf", &cSalary);
				
				pay = 250.0 + 0.057 * cSalary;
				printf("Commission worker's pay is $%.2f\n", pay);
				
				++cWorkers;
				
				break;
				
			case 4:
				
				printf("%s", "Pieceworker selected\nEnter number of pieces: ");
				scanf("%d", &pieces);
				
				printf("%s", "Enter wage per pieces: ");
				scanf("%lf", &pSalary);
				
				pay = pieces * pSalary;
				printf("Pieceworker's salary is $%.2f\n", pay);
				
				++pWorkers;
				
				break;
				
			default:
				printf("%s", "Invalid pay code\n");
				break;	
		}
		
		printf("%s", "Enter pay code (-1 to end): ");
		scanf("%d", &payCode);
	}
	
	printf("%s", "\n");
	printf("Total number of managers paid           %d\n", managers);
	printf("Total number of hourly workers paid     %d\n", hWorkers);
	printf("Total number of commission workers paid %d\n", cWorkers);
	printf("Total number of pieces workers paid     %d\n", pWorkers);
}
