#include "sort.h"
/**
 * bubble_sort - A bubble sorting algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 *
 * Descrription: This bubble sort is an optimized bubble sort. If the elements
 * are already sorted before feed in to this algorithm, it will only checkthem
 * once at time complexity of O(n) where n - is the number of ellement to sort.
 *
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, swapped, j;
	int temp;

	if (array && size >= 2)
	{
		for (; i < size; i++)
		{
			swapped = 0;
			for (j = 0; j < (size - (i + 1)); j++)
			{
				if (array[j] > array[j + 1])
				{
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
					swapped = 1;
					print_array(array, size);
				}
			}
			if (!swapped)
				break;
		}
	}
}
