#include "sort.h"
/**
 * merge_sort - Sorts an array of integerrs in ascending order using
 * Merge sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	if (array && size > 1)
	{
		divide(array, 0, size - 1);
	}
}
/**
 *divide - Recurisvely divide the list in to sublists untill unit element
 * is left in each sublists
 * @array: The array to be divided into sublists
 * @left: The left index of any sublist
 * @right: The right index of any sublist
 *
 * Return: Nothing
 */
void divide(int *array, int left, int right)
{
	int middle;

	if (left != right)
	{
		middle = (left + (right - 1)) / 2;
		divide(array, left, middle);/*Divide left sublists upto unit element*/
		divide(array, middle + 1, right);/*Divide right sublist upto unit element*/
		conquer(array, left, middle, right);/*Merge back the sublists*/
	}
}
/**
 * conquer - Merge back the two sublist into the input array
 * @array: The input array
 * @left: The left index of input array for current conquer
 * @middle: The middle index of input array for current conquer
 * @right: The right index of input array for current conquer
 *
 * Return: Nothing
 */
void conquer(int *array, int left, int middle, int right)
{
	int *left_sublist, *right_sublist;
	int i, j, k = left;

	/*Create a storage for sublist*/
	left_sublist = createSublist((middle - left) + 1);
	right_sublist = createSublist(right - middle);
	/*Populate the sublist with thier element from the input array*/
	for (i = 0; i < ((middle - left) + 1); i++)
		left_sublist[i] = array[left + i];
	for (j = 0; j < (right - middle); j++)
		right_sublist[j] = array[middle + 1 + j];
	printf("Merging...\n[left]: ");
	print_array(left_sublist, (middle - left) + 1);
	printf("[right]: ");
	print_array(right_sublist, right - middle);
	/*Merge back the two sublist into input array*/
	i = 0, j = 0;
	while ((i < (middle - left) + 1) && (j < right - middle))
	{
		if (left_sublist[i] <= right_sublist[j])
			array[k] = left_sublist[i], i++;
		else
			array[k] = right_sublist[j], j++;
		k++;
	}
	/*Store any remaining elment in the sublists into input array*/
	for (; i < (middle - left) + 1; i++)
		array[k] = left_sublist[i], k++;
	for (; j < right - middle; j++)
		array[k] = right_sublist[j], k++;
	printf("[Done]: ");
	for (i = left; i < right + 1; i++)
	{
		printf("%d", array[i]);
		if (i != right)
			printf(", ");
	}
	printf("\n");
	destroySublist(left_sublist); /*Deallocate left sublist*/
	destroySublist(right_sublist); /*Deallocate right sublist*/
}
/**
 * createSublist - Create a sublist for storing division result
 * @sublist_size: The size of sublist to be created
 *
 * Return: Pointer to the sublist just created
 */
int *createSublist(int sublist_size)
{
	int *sublist;

	sublist = (int *)malloc(sizeof(int) * sublist_size);
	return (sublist);
}
/**
 * destroySublist - Free memory area allocated for the sublsit
 * @sublist: The sublsit to be destroyed
 *
 * Return: Nothing
 */
void destroySublist(int *sublist)
{
	free(sublist);
}
