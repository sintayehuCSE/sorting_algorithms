#include "sort.h"
/**
 * shell_sort - A function that sorts an array of integerrs in ascending order
 * using the shell sort algorithm via use of `knuth`gap sequence.
 * @array: The array to be shell-sorted
 * @size: The size of the array
 *
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (array && size > 1)
	{
		for (; gap < size / 3;)
			gap = (gap * 3) + 1;
		for (; gap > 0; gap = (gap - 1) / 3)
		{
			for (i = gap; i < size; i++)
			{
				temp = array[i];
				for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
					array[j] = array[j - gap];
				array[j] = temp;
			}
			print_array(array, size);
		}
	}
}
