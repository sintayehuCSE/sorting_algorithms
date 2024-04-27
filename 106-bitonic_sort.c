#include "sort.h"
/**
 * bitonic_sort - Sorts an array of integers in ascending order using the
 * Bitonic sort algorithm
 * @array: The input array
 * @size: The size of the array
 *
 * Return: Nothing
 */
void bitonic_sort(int *array, size_t size)
{
	if (array && size > 1)
		bitonic_seq(array, 0, (int)size, 1, size);
}
/**
 * bitonic_seq - Construct a bitonic sequence from an input sequence
 * @array: The input sequence
 * @left: The left index of current sub-sequence
 * @right: The right index bound of the current sub-sequence
 * @type: A sorting type either ascending or descending
 * @size: The size of the input sequence
 *
 * Return: Nothing
 */
void bitonic_seq(int *array, int left, int right, int type, size_t size)
{
	int k; /*Delimits the range of next subsequence, its left and right index*/

	if (right > 1)
	{
		k = right / 2;
		print_status(array, left, right, type, 0, size);
		/*Bitonify the array in increasing order/direction, type = 1*/
		bitonic_seq(array, left, k, 1, size);
		/*Bitonify the arra in decreasing order/direction, type = 0*/
		bitonic_seq(array, left + k, k, 0, size);
		/*Merge back the result of bitonifying operation to get partial*/
		/*and finally full bitonic sequence from the input sequence*/
		bitonic_merge(array, left, right, type);
		print_status(array, left, right, type, 1, size);
	}
}
/**
 * bitonic_merge - Perform a merge of bitonic sequence to sort the input array
 * @array: The input sequence
 * @left: The left index bound of current sequence range
 * @right: The right index bound of current sequence range
 * @type: The direction for merging, Ascending or Descending
 *
 * Return: Nothing
 */
void bitonic_merge(int *array, int left, int right, int type)
{
	int k, i;

	if (right > 1)
	{
		k = right / 2;
		for (i = left; i < left + k; i++)
			compare_and_swap(array, i, i + k, type);
		bitonic_merge(array, left, k, type);
		bitonic_merge(array, left + k, k, type);
	}
}
/**
 * compare_and_swap - Swap the element at the requested index if condion is met
 * @array: The input sequence
 * @i: The ith element for comparing and swaping
 * @j: The jth element for comparing and swaping
 * @type: The type of bitonification either ascending or descending order
 *
 * Return: 1 if swapped , 0 otherwise.
 */
void compare_and_swap(int *array, int i, int j, int type)
{
	int temp;

	if (type == (array[i] > array[j]))
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}
/**
 * print_status - Prints the input array/sequence after swaping
 * @array: The input sequence
 * @left: The left index of current sequence
 * @right: The right index of current sequence
 * @type: The type of bitonic operation
 * @stat: For distinguishing between merging and swaping action
 * @size: The size of the input sequence
 *
 * Return: Nothing
 */
void print_status(int *array, int left, int right, int type, int stat,
		       size_t size)
{
	if (!stat)
		printf("Merging [%d/%lu] ", right, size);
	else
		printf("Result [%d/%lu] ", right, size);
	if (type)
		printf("(UP):\n");
	else
		printf("(DOWN):\n");
	print_array(array + left, (size_t)right);
}
