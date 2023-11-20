#include "sort.h"
#include <stdio.h>

/**
 * merge_compare - compares and merges two halves of an array
 * @array: the integer array to be sorted
 * @start: the start index of the range to be merged
 * @middle: the middle index dividing the two halves
 * @stop: the stop index of the range to be merged
 * @new: the output array to store the merged result
 *
 * This function compares and merges two sorted halves of the array.
 * It uses the temporary array 'new' to store the merged result.
 */

void merge_compare(int *array, size_t start, size_t stop, int *new)
{

	size_t i = start;
	size_t j, k;
        size_t	middle;
	j = middle = (start + stop)/2;

	printf("Merging...\n");
	printf("[left]:");
        print_array(array + start, middle - start);
        printf("[right]:");
	print_array(array + middle, stop - middle);	

    	for (k = start; k < stop; k++)
    	{
        	if (i < middle && (j >= stop || array[i] <= array[j]))
        	{
            		new[k] = array[i];
            		i++;
        	}
        	else
        	{
            		new[k] = array[j];
           	 	j++;
        	}

    	}

    	
    	printf("[Done]: ");
	print_array(new + start, stop - start);

}

/**
 * merge_sort_top_down - sorts top-down recursively
 * @array: the integer array to be sorted
 * @start: the start index
 * @stop: the stop index
 * @new: the output array
 *
 * Return: void
 */
void merge_sort_top_down(int *array, size_t start, size_t stop, int *new){

	size_t middle;
	middle = (start + stop) / 2;

	if (stop - start < 2)
        	return;


   
    	merge_sort_top_down(new, start, middle, array);
    	merge_sort_top_down(new, middle, stop, array);


   	merge_compare(array, start, stop, new);
}





/**
 * merge_sort -sorts by merge sort algorithm
 * @array: the integer array to sort
 * @size: the size of the array
 *
 * Return: void.
 */
void merge_sort(int *array, size_t size)
{
	int* new;
	size_t i;

	if(array == NULL || size < 2)
		return;

	new = malloc(sizeof(int) * size);

	if(!new)
		return;

	for( i = 0; i < size; i++)
		new[i] = array[i];

	merge_sort_top_down(new, 0, size, array);

	free(new);


}
