#include <stdio.h>
#include "sort.h"


/**
 * selection_sort - Sorts an array of integers in ascending order using
 * the selection sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
    int tmp = 0;

    for (int i = 0; i < size - 1; i++)
    {
        int smallestIndex = i;  /* Assume the current index has the smallest value */

        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[smallestIndex])
            {
                smallestIndex = j;  /* Update the index of the smallest element */
            }
        }

        /* Swap the found smallest element with the element at index i */
        tmp = array[i];
        array[i] = array[smallestIndex];
        array[smallestIndex] = tmp;
    }
}

