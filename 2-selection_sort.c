#include "sort.h"
/**
 * selection_sort - A selection sorting algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j;
	int ind = -1, temp;

	for (; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[i])
			{
				if (ind != -1)
				{
					if (array[j] < array[ind])
						ind = (int)j;
				}
				else
				{
					ind = (int)j;
				}
			}
		}
		if (ind >= 0)
		{
			temp = array[i];
			array[i] = array[ind];
			array[ind] = temp;
			print_array(array, size);
		}
		ind = -1;
	}
}
