#include "sort.h"
/**
 * radix_sort - Sorts an array of integers in ascending order using the
 * radix sort algorithm.
 * @array: The array to be sorted by radix sorted
 * @size: The size of the array
 *
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
	int max, place;

	if (array && size > 1)
	{
		max = getMax(array, (int)size);
		place = 1;
		/*Minimum places in positional number system is 1 next 10th, 100th ...*/
		while ((max / place) > 0)
		{
			countSortRadix(array, size, place);
			place *= 10;
		}
	}
}
/**
 * getMax - Get the maximum element in the input array
 * @array: The input array
 * @size: Size of the input array
 *
 * Description - The maximum element determines the number of places we can use
 * to call a count sort on the input array like 1's, 10th, 100th, 1000th...etc
 *
 * Return: The maximum element of the input array
 */
int getMax(int *array, int size)
{
	int i = 1, max;

	max = array[0];
	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return (max);
}
/**
 * countSortRadix - Perform a count sort algorithm on the input array according
 * to the current places of the maximum element of the array.
 * @array: The input array
 * @size: The size of the array
 * @place: The current place of the maximum element's digit
 *
 * Return: Nothing
 */
void countSortRadix(int *array, size_t size, int place)
{
	int *bucket, *radix;
	int i;

	/*bucket: for storing sorted item according to current positional place*/
	/*radix: For counting frequency of digits in current place and do prefix sum*/
	bucket = dynamicArray((int)size);
	radix = dynamicArray(10);
	if (bucket && radix)
	{
		/*Initialize frequecy array with all unit zeroed*/
		for (i = 0; i < 10; i++)
			radix[i] = 0;
		/*Find digit frequency relative to current position*/
		for (i = 0; i < (int)size; i++)
			radix[(array[i] / place) % 10] += 1;
		/*Find cumulative sum of the frequency of digit in current plaace*/
		for (i = 1; i < 10; i++)
			radix[i] += radix[i - 1];
		/*Populate bucket according to current place*/
		for (i = size - 1; i >= 0; i--)
		{
			bucket[radix[(array[i] / place) % 10] - 1] = array[i];
			radix[(array[i] / place) % 10] -= 1;
		}
		/*Sort the input array according to the current place by populating*/
		/* it with elements from bucket*/
		for (i = 0; i < (int)size; i++)
			array[i] = bucket[i];
		print_array(array, size);
		free(radix);
		free(bucket);
	}
}
/**
 * dynamicArray - Create a dynamic array allocation on the heap
 * @size: The size of the dynamic array
 *
 * Return: Pointer to the dynamic array address in heap
 */
int *dynamicArray(int size)
{
	int *array;

	array = (int *)malloc(sizeof(int) * size);
	return (array);
}
