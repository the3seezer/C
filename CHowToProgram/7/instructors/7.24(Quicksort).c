/* Exercise 7.24 Solution */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

/* function prototypes */
void quicksort(int *array, int first, int last);
int partition(int *array, int left, int right);
void swap(int *ptr1, int *ptr2);

int main()
{
    int loop;                       /* loop counter */
    int arrayToBeSorted[MAX] = {0}; /* array to sort */

    srand(time(NULL));

    /* randomly generate content */
    for (loop = 0; loop < MAX; loop++)
    {
        arrayToBeSorted[loop] = rand() % 1000;
    } /* end for */

    printf("Initial array values are: \n");

    /* print out values of the array */
    for (loop = 0; loop < MAX; loop++)
    {
        printf("%4d", arrayToBeSorted[loop]);
    } /* end for */

    printf("\n\n");

    /* if there is only one element */
    if (MAX == 1)
    {
        printf("Array is sorted: %d\n", arrayToBeSorted[0]);
    } /* end if */
    else
    { /* call quicksort */
        quicksort(arrayToBeSorted, 0, MAX - 1);
        printf("The sorted array values are:\n");

        /* display sorted array */
        for (loop = 0; loop < MAX; loop++)
        {
            printf("%4d", arrayToBeSorted[loop]);
        } /* end for */

        printf("\n");
    } /* end else */

    return 0; /* indicate successful termination */

} /* end main */

/* recursive function to sort array */
void quicksort(int array[], int first, int last)
{
    int currentLocation; /* current location in array */

    /* if array is sorted, return */
    if (first >= last)
    {
        return;
    } /* end if */

    currentLocation = partition(array, first, last); /* place an element */
    quicksort(array, first, currentLocation - 1);    /* sort left side */
    quicksort(array, currentLocation + 1, last);     /* sort right side */

} /* end function quicksort */

/* partition the array into multiple sections */
int partition(int array[], int left, int right)
{
    int position = left; /* final location of first element */

    /* infinite loop */
    while (1)
    {
        /* loop through the portion of the array */
        while (array[position] <= array[right] &&
               position != right)
        {
            --right;
        } /* end while */

        /* if correct position is found */
        if (position == right)
        {
            return position;
        } /* end if */

        /* swap positions */
        if (array[position] > array[right])
        {
            swap(&array[position], &array[right]);
            position = right;
        } /* end if */

        /* loop through the portion of the array */
        while (array[left] <= array[position] &&
               left != position)
        {
            ++left;
        } /* end while */

        /* if correct position is found */
        if (position == left)
        {
            return position;
        } /* end if */

        /* swap positions */
        if (array[left] > array[position])
        {
            swap(&array[position], &array[left]);
            position = left;
        } /* end if */

    } /* end while */

} /* end function partition */

/* swap locations */
void swap(int *ptr1, int *ptr2)
{
    int temp; /* temporary holder */

    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
} /* end function swap */