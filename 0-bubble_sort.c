#include "sort.h"

/**
 * swap - Swaps two integers.
 * @x: Pointer to the first integer.
 * @y: Pointer to the second integer.
 */
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order using the Bubble Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void bubble_sort(int *array, size_t size)
{
    int swapped;
    size_t i = 0, j =0;

    for (; i < size - 1; i++)
    {
        swapped = 0;

        for (; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                swapped = 1;
            }

	    print_array(array, size);
        }




        if (swapped == 0)
            break;
    }
}
