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
	// price of products
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
	// total price by products
	int priceOne = 100; int priceTwo = 200; int priceThree = 300; int priceFour = 400; int priceFive = 500;
	int first = 0,second = 0; int third = 0,fourth = 0; // sales people
	// total price by salespeople
	int firstPrice = 0,secondPrice = 0,thirdPrice = 0,fourthPrice = 0; 
	printf("%38s%18s%s", "Salespeople", "Total", "    Total Price\n");
	/* size_t j = 0;
	 int total_sales_by_salesperson = 0;
	 For this case switch row position to column position */
	 
	 // control row; this time it's the products 
	for (size_t i = 0; i < products; ++i) {
		if (i == 2)	{
			printf("%s", "Products        ");
		}
		else {
			printf("%s", "                ");
		}
		// total_sales_by_salesperson += b[i][j];
		int total_sales_by_product = 0;
		// control column; this time it's the salespeople
		for (size_t j = 0; j < sales_people; ++j) {
			printf("%7d", b[j][i]); // remember to switch the row and the column subscript in the printf function array element and mind the size in the loops (row and column loops)
			total_sales_by_product += b[j][i];
			
			if (j == 0) {
				first += b[j][i];
				firstPrice += b[j][i] * ((i == 0) ? priceOne : (i == 1) ? priceTwo : (i == 2) ? priceThree : (i == 3) ? priceFour :  priceFive);
			}
			else if (j == 1) {
				second += b[j][i];
				secondPrice += b[j][i] * ((i == 0) ? priceOne : (i == 1) ? priceTwo : (i == 2) ? priceThree : (i == 3) ? priceFour :  priceFive);
			}
			else if (j == 2) {
				third += b[j][i];
				thirdPrice += b[j][i] * ((i == 0) ? priceOne : (i == 1) ? priceTwo : (i == 2) ? priceThree : (i == 3) ? priceFour :  priceFive);
			}
			else if (j == 3) {
				fourth += b[j][i];
				fourthPrice += b[j][i] * ((i == 0) ? priceOne : (i == 1) ? priceTwo : (i == 2) ? priceThree : (i == 3) ? priceFour :  priceFive);
			}
		}
		printf("%9d", total_sales_by_product);
		printf("%10d @%d", total_sales_by_product * ((i == 0) ? priceOne : (i == 1) ? priceTwo : (i == 2) ? priceThree : (i == 3) ? priceFour :  priceFive), ((i == 0) ? priceOne : (i == 1) ? priceTwo : (i == 2) ? priceThree : (i == 3) ? priceFour :  priceFive));
		
		puts("");
	}
	printf("%s%7d%7d%7d%7d%9d\n", "Total           ", first, second, third, fourth, first + second + third + fourth);
	printf("%s%7d%7d%7d%7d%9d\n", "Total Price     ", firstPrice, secondPrice, thirdPrice, fourthPrice, firstPrice + secondPrice + thirdPrice + fourthPrice);
}

