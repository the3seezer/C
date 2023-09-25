/*
theBitRiddler
9/23/2023
11:19 AM
Calcuating Circle Circumference, Circle Area or Sphere Volume Using Function
Pointers
*/
#include <math.h>
#include <stdio.h>


#define PIE 3.14

void circumference(double);
void area(double);
void sphereVolume(double);
void printMenu(void);

int main(void) {

  void (*circle[3])(double) = {circumference, area, sphereVolume};
  int choice = 0;
  double radius = 0;

  while (choice >= 0 && choice < 3 ) {
    
    do {
      printMenu();
      scanf("%d", &choice);
    } while (choice < -1 || choice > 2);

    if ( choice == -1 )
        break;

    printf_s("%s", "\tEnter the radius\n\t?");
    scanf("%lf", &radius);
    (*circle[choice])(radius);

  } // end while

  printf_s("%s", "\n\n\tProgram ended");
  return 0;
} /* end main */

void printMenu(void) {
  printf_s("%s", "\n\tEnter the choice of calculation\n"
                 "\t0 Circumference\n"
                 "\t1 Area\n"
                 "\t2 Sphere volume\n"
                 "\t-1 To end program\n"
                 "\t? ");
} /* end function printMenu */

void circumference(double radius) {

  printf_s("\tThe circumference a circle of radius %.2lf is %.2lf\n\n", radius,
           2 * PIE * radius);

} /* end function circumference */

void area(double radius) {
  printf_s("\tThe area of a circle of radius %.2lf is %.2f\n\n", radius,
           PIE * pow(radius, 2));
} /* end function area */

void sphereVolume(double radius) {
  printf_s("\tThe volume of a sphere of radius %.2f is %.2f\n\n", radius,
          ( (double) 4 / 3 ) * PIE * pow(radius, 3));
} /* end function sphereVolume */