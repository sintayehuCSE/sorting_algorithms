#include "sort.h"
/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting sort algorithm
 * @array: The array to be count sorted
 * @size: The size of the array
 *
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted;
	int n = (int)(size), i;
	int k; /*`K` is to find the maximum element within the array*/

	if (!array || size < 2)
		return;
	k = array[0];
	for (i = 1; i < n; i++) /*Loop for finding maximum element in the array*/
	{
		if (k < array[i])
			k = array[i];
	}
	count = countArray(k);
	sorted = sortArray(n);
	if (!count || !sorted)
		return;
	for (i = 0; i < n; i++)/*finding frequence of each distinit element*/
	{
		count[array[i]] += 1;
	}
	for (i = 1; i <= k; i++)/*Cumulative sum of countArray*/
	{
		count[i] += count[i - 1];
	}
	print_array(count, (size_t)(k + 1));
	for (i = (n - 1); i >= 0; i--)/*Sort the array in backward direction*/
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}
	for (i = 0; i < n; i++) /*Sort the original input-array*/
	{
		array[i] = sorted[i];
	}
	free(count);
	free(sorted);
}
/**
 *countArray - Create a count array and intilize it to zero
 * @k: The maximum index of the count array
 *
 * Return: The pointer to count array
 */
int *countArray(int k)
{
	int *count;
	int i = 0;

	count = (int *)malloc(sizeof(int) * (k + 1));
	if (!count)
		return (count);
	else if (count)
	{
		for (; i <= k; i++)
			count[i] = 0;
	}
	return (count);
}
/**
 * sortArray - Create an array for storing a sorted element
 * @n: The size of the sort array
 *
 * Return: Pointer to the sort array
 */
int *sortArray(int n)
{
	int *sort;

	sort = (int *)malloc(sizeof(int) * n);
	if (!sort)
		return (sort);
	return (sort);
}
