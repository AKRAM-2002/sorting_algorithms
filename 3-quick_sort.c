#include <stdio.h>

/**
 * quick_sort - Sorts an array of integers in ascending order using the Quick Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_s(array, 0, size - 1, size);
}

/**
 * swap - Swaps the values of two integers.
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
 * partition - Partitions the array and selects a pivot for Quick Sort.
 * @array: Pointer to the array to be partitioned.
 * @lo: Starting index of the partition.
 * @hi: Ending index of the partition.
 * @size: Size of the array.
 * Return: Index of the pivot element.
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int i = lo - 1, j = lo;
	int pivot = array[hi];

	for (; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[hi])
	{
		swap(&array[i + 1], &array[hi]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_s - Recursively sorts the subarrays of the Quick Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @lo: Starting index of the subarray.
 * @hi: Ending index of the subarray.
 * @size: Size of the array.
 */
void quick_s(int *array, int lo, int hi, size_t size)
{
	int pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		quick_s(array, lo, pivot - 1, size);
		quick_s(array, pivot + 1, hi, size);
	}
}
