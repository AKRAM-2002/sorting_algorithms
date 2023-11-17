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
    size_t i = 0, j = 0;
    size_t smallestIndex;
    if(array == NULL || size == 0)
	    return;

    for (; i < size - 1; i++)
    {
        smallestIndex = i;  
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[smallestIndex])
            {
                smallestIndex = j; 
	    }
        }

	if (smallestIndex != i){
		tmp = array[i];
        	array[i] = array[smallestIndex];
       		array[smallestIndex] = tmp;
		print_array(array,size);
	
	}
    }
}

