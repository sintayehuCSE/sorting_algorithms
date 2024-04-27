#include "sort.h"
/**
 * quick_sort_hoare - Implement quick sort algorithm using hoare partition
 * @array: The input array
 * @size: The size of the array
 *
 * Return: Nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array && size > 1)
		quick_hoare(array, 0, size - 1, size);
}
/**
 * quick_hoare - Hoare scheme for quick sort algorithm
 * @array: The input array
 * @left: The left index of current partition
 * @right: The right index of current partition
 * @size: The size of the input array
 *
 * Return:Nothing
 */
void quick_hoare(int *array, int left, int right, size_t size)
{
	int pivot_index;

	if (left < right)
	{
		pivot_index = hoare_partition(array, left, right, size);
		quick_hoare(array, left, pivot_index - 1, size);
		quick_hoare(array, pivot_index, right, size);
	}
}
/**
 * hoare_partition - Perform a hoare partition scheme on the input array
 * @array: The input array
 * @left: The left index of curreent partition
 * @right: The right index of current partition
 * @size: The size of the input array
 *
 * Return: next pivot element index
 */
int hoare_partition(int *array, int left, int right, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[right];
	i = left - 1;
	j = right + 1;
	for (; i < j ;)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i < j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	return (i);
}
