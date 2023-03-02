// theBitRiddler
// 1/10/2023
// 9:03 AM
// Total Sales
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SALESPEOPLE 4
#define PRODUCTS 5 

void getCalculateSales(int b[][PRODUCTS], int days);
void printSales(const int b[][PRODUCTS], size_t sales_people, size_t products);

int main(void) {
	srand(time(NULL));
	const int MONTH = 30;
	int sales[SALESPEOPLE][PRODUCTS] = {0};
	getCalculateSales(sales, MONTH);
	printSales(sales, SALESPEOPLE, PRODUCTS);
}

void getCalculateSales(int b[][PRODUCTS], int days) {
	for (int i = 0; i < days; ++i) { // get number of days
		++b[0][0 + rand() % 5];
		++b[1][0 + rand() % 5];
		++b[2][0 + rand() % 5];
		++b[3][0 + rand() % 5];
	}
}

void printSales(const int b[][PRODUCTS], size_t sales_people, size_t products) {
	int first,second = 0; int third,fourth = 0;
	printf("%s", "           Salespeople         Total\n");
	
	/* For this case switch row position to column position
	   control row; this time it's the products */
	for (size_t i = 0; i < products; ++i) {
		if (i == 2)	{
			printf("%s", "Products");
		}
		else {
			printf("%8s", "");
		}
		
		int total_sales_by_product = 0;
		// control column; this time it's the salespeople
		for (size_t j = 0; j < sales_people; ++j) {
			printf("%4d", b[j][i]); // remember to switch the row and the column subscript in the printf function array element and mind the size in the loops (row and column loops)
			total_sales_by_product += b[j][i];
			
			if (j == 0) {
				first += b[j][i];
			}
			else if (j == 1) {
				second += b[j][i];
			}
			else if (j == 2) {
				third += b[j][i];
			}
			else if (j == 3) {
				fourth += b[j][i];
			}
		}
		printf("%9d", total_sales_by_product);
		puts("");
	}
	printf("%s%4d%4d%4d%4d%9d", "Total   ", first, second, third, fourth, first + second + third + fourth);
}

