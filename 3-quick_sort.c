#include "sort.h"
/**
 * quick_sort - A Quick Sort Algorithm
 * @array: The array to be solved
 * @size: The size of the array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array && size > 1)
		quickly_sort(array, 0, size - 1, size);
}
/**
 * quickly_sort - Quicly sort the array
 * @array: The array to be quickly sorted
 * @low: Lower index of the subarray
 * @high: Higher index of the subarray
 * @size: Size of the array
 *
 * Return: Nothing
 */
void quickly_sort(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (high - low > 0)
	{
		pivot_index = partition_array(array, low, high, size);
		quickly_sort(array, low, pivot_index - 1, size);
		quickly_sort(array, pivot_index + 1, high, size);
	}
}
/**
 * partition_array - Divide the array in to two subarrays
 * @array: The array to be divided
 * @low: The lower index of the partition
 * @high: The higher index of the partition
 * @size: Size of the array
 *
 * Return: The index of pivot element for current partion.
 */
size_t partition_array(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	i = low;
	pivot = array[high];
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i < j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] > pivot)
	{
		temp = array[high];
		array[high] = array[i];
		array[i] = temp;
		print_array(array, size);
	}
	return (i);
}
